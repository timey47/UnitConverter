// Copyright 2023 Timothy
#include "weight.h"

class WeightRange {
 private:
  Weight smallest;  // The smallest weight in the range.
  Weight largest;   // The largest weight in the range.

 public:
  // Default constructor: Initializes the range with default Weight values.
  WeightRange();

  // determines which is smaller and larger to set the range correctly.
  WeightRange(const Weight& w1, const Weight& w2);

  // Returns the smallest weight in the range.
  Weight GetSmallest() const;

  // Returns the largest weight in the range.
  Weight GetLargest() const;

  // Sets the smallest weight in the range, ensuring it's not larger than the
  // current largest weight.
  void SetSmallest(const Weight& w);

  // Sets the largest weight in the range, ensuring it's not smaller than the
  // current smallest weight.
  void SetLargest(const Weight& w);

  // Converts the units of both smallest and largest weights to the specified
  // new units.
  void ConvertUnits(const std::string& newUnits);

  // Checks if a given weight is within the range.
  bool InRange(const Weight& w, bool inclusive = true) const;

  // Returns the difference (width) between the largest and smallest weights in
  // the range.
  Weight Width() const;
};
