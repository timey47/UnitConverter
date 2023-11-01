// Copyright 2023 Timothy
#include "weight.h"

#include <iostream>
using std::string;

// checks if a given unit is one of the valid units: ounces, pounds, grams, or
// kilograms.
bool Weight::isValidUnit(const string& unit) const {
  return unit == "ounces" || unit == "pounds" || unit == "grams" ||
         unit == "kilograms";
}

// Default Constructor
Weight::Weight() : value_(0), units_("pounds") {}

// Single argument Constructor
Weight::Weight(double value)
    : value_(value > 0 ? value : 0), units_("pounds") {}

// Two argument Constructor
Weight::Weight(double value, const string& units) {
  if (value < 0) {
    value_ = 0;  // If invalid value, set to 0
  } else {
    value_ = value;
  }

  if (isValidUnit(units)) {
    units_ = units;
  } else {
    units_ = "pounds";  // If invalid unit, set to pounds
  }
}

// Accessor functions that return the value and units of the Weight object
double Weight::GetValue() const { return value_; }

string Weight::GetUnits() const { return units_; }

// Mutators, ensure that the value is non-negative and the units are valid.
void Weight::SetValue(double value) {
  if (value >= 0) {
    value_ = value;
  }
}
void Weight::SetUnits(const string& units) {
  if (isValidUnit(units)) {
    units_ = units;
  }
}
// Changes the units of the Weight object and adjusts its value accordingly
// using conversion factors
void Weight::ConvertUnits(const string& newUnits) {
  if (isValidUnit(newUnits)) {
    if (units_ == "pounds" && newUnits == "ounces") {
      value_ *= 16;
    } else if (units_ == "ounces" && newUnits == "pounds") {
      value_ /= 16;
    } else if (units_ == "pounds" && newUnits == "kilograms") {
      value_ *= 0.453592;  // 1 pound is approximately 0.453592 kilograms
    } else if (units_ == "kilograms" && newUnits == "pounds") {
      value_ /= 0.453592;
    } else if (units_ == "kilograms" && newUnits == "grams") {
      value_ *= 1000;  // 1 kilogram is 1000 grams
    } else if (units_ == "grams" && newUnits == "kilograms") {
      value_ /= 1000;
    } else if (units_ == "pounds" && newUnits == "grams") {
      value_ *= 453.59237;  // 1 pound is approximately 453.592 grams
    } else if (units_ == "grams" && newUnits == "pounds") {
      value_ /= 453.592;
    } else if (units_ == "ounces" && newUnits == "grams") {
      value_ *= 28.3495;  // 1 ounce is approximately 28.3495 grams
    } else if (units_ == "grams" && newUnits == "ounces") {
      value_ /= 28.3495;
    } else if (units_ == "ounces" && newUnits == "kilograms") {
      value_ *= 0.0283495;  // 1 ounce is approximately 0.0283495 kilograms
    } else if (units_ == "kilograms" && newUnits == "ounces") {
      value_ /= 0.0283495;
    }
    units_ = newUnits;  // Update the units after conversion
  }
}

// Returns the value of the Weight object in grams, regardless of its current
// units.
double Weight::GetValueInGrams() const {
  if (units_ == "grams")
    return value_;
  else if (units_ == "kilograms")
    return value_ * 1000;
  else if (units_ == "ounces")
    return value_ * 28.3495;
  else if (units_ == "pounds")
    return value_ * 453.592;
  else
    return 0;
}

std::ostream& operator<<(std::ostream& os, const Weight& weight) {
  os << weight.GetValue() << " " << weight.GetUnits();
  return os;
}