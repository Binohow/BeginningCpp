#pragma once
class Box
{
private:
  double length{1.0};
  double width{1.0};
  double height{1.0};

public:
    Box(double length, double width, double height);
    Box(/* args */)=default;
    ~Box()=default;
    double volume() const;      // Function to calculate the volume of a box
    double getLength() const {return length;}
    double getWidth() const  { return width; }
    double getHeight() const { return height; }

    // Functions to set member variable values
    void setLength(double lv) { if (lv > 0) length = lv;}
    void setWidth(double wv)  { if (wv > 0) width = wv; }
    void setHeight(double hv) { if (hv > 0) height = hv; }
};