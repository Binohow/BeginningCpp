#pragma once
#include<iostream>
class Box
{
private:
    /* data */
    double length{1.0};
    double width{1.0};
    double height{1.0};
public:
    Box(double lv, double wv, double hv);
    explicit Box(double side);
    Box(/* args */)=default;//等价于 Box(/* args */){}
    ~Box()=default;
    double volume();
};