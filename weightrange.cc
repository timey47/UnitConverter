// Copyright 2023 Timothy
#include "weightrange.h"

// Default constructor
WeightRange::WeightRange() : smallest(0, "pounds"), largest(0, "pounds") {}

// Constructor with two Weight objects
WeightRange::WeightRange(const Weight& w1, const Weight& w2) {
  double w1InGrams = w1.GetValueInGrams();  //  method in the Weight class
  double w2InGrams = w2.GetValueInGrams();  // method in the Weight class

  if (w1InGrams <= w2InGrams) {
    smallest = w1;
    largest = w2;
  } else {
    smallest = w2;
    largest = w1;
  }
}

// Accessor for smallest weight
Weight WeightRange::GetSmallest() const { return smallest; }

// Accessor for largest weight
Weight WeightRange::GetLargest() const { return largest; }

// Set smallest weight
void WeightRange::SetSmallest(const Weight& w) {
  if (w.GetValueInGrams() <= largest.GetValueInGrams()) {  // Compare in grams
    smallest = w;
  }
}

// Set largest weight
void WeightRange::SetLargest(const Weight& w) {
  if (w.GetValueInGrams() >= smallest.GetValueInGrams()) {  // Compare in grams
    largest = w;
  }
}

// Check if a weight is in range
bool WeightRange::InRange(const Weight& w, bool inclusive) const {
  double weightInGrams = w.GetValueInGrams();
  double smallestInGrams = smallest.GetValueInGrams();
  double largestInGrams = largest.GetValueInGrams();

  bool result;
  if (inclusive) {
    result =
        weightInGrams >= smallestInGrams && weightInGrams <= largestInGrams;
  } else {
    result = weightInGrams > smallestInGrams && weightInGrams < largestInGrams;
  }

  return result;
}

// Get the width of the range
Weight WeightRange::Width() const {
  double smallestInGrams = smallest.GetValueInGrams();
  double largestInGrams = largest.GetValueInGrams();

  double diffInGrams = largestInGrams - smallestInGrams;

  // Convert the difference back to the units of the largest weight
  Weight diff(diffInGrams, "grams");
  diff.ConvertUnits(largest.GetUnits());

  return diff;
}