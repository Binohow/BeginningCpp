#pragma once
#include"Vessel.h"
#define PI 3.141592653589793238462643383279502884
class Can:public Vessel
{
private:
    /* data */
    double diameter {1.0};
    double height {1.0};
public:
    Can(double d, double h) : diameter {d}, height {h} {}
    double volume() const override{return PI * diameter * diameter * height / 4.0; }
};
