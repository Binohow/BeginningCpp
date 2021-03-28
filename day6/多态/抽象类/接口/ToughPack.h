#pragma once
#include"Box.h"
class ToughPack : public Box
{
public:
  // Constructor
  ToughPack(double lv, double wv, double hv) : Box {lv, wv, hv} {}

  // Function to calculate volume of a ToughPack allowing 15% for packing
  double volume() const override { return 0.85 * Box::volume(); }
};