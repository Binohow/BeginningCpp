#pragma once
#include<iostream>
class Box
{
protected:
    double length {1.0};
    double width {1.0};
    double height {1.0};
public:
    Box(/* args */)=default;
    Box(double lv, double wv, double hv):length{lv},width{wv},height{hv}{};

      // Function to show the volume of an object
    void showVolume() const
    {
        std::cout << "Box usable volume is " << volume() << std::endl;
    }
    
    virtual double volume(int i=5) const
    {
        std::cout << "Box parameter = " << i << std::endl;
        return length*width*height;
    }
};
