// Copyright 2023 Timothy
#ifndef WEIGHT_H
#define WEIGHT_H

#include <iostream>
#include <string>

class Weight {
 public:
  // Constructors
  Weight();              // default constructor with 0 value and "pounds" unit
  Weight(double value);  // single argument constructor
  Weight(double value, const std::string& units);  // two argument constructor

  // Accessors
  double GetValue() const;
  std::string GetUnits() const;

  // Mutators
  void SetValue(double value);
  void SetUnits(const std::string& units);

  void ConvertUnits(
      const std::string& newUnits);  // Converts weight to a given unit

  double GetValueInGrams() const;  // Declare the method

  // Overloaded stream insertion operator (friend function for output)
  friend std::ostream& operator<<(std::ostream& os, const Weight& weight);

 private:
  double value_;
  std::string units_;
  bool isValidUnit(
      const std::string& unit) const;  // Helper function to check valid units
};

#endif  // WEIGHT_H
