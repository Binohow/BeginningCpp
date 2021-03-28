#pragma once
#include"Vessel.h"
class Box:public Vessel
{
protected:
    /* data */
    double length {1.0};
    double width {1.0};
    double height {1.0};
public:
    Box(/* args */)=default;
    Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} {}
    double volume() const override { return length*width*height; }
};
