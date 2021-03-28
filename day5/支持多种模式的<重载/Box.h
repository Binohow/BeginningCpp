class Box
{
private:
  double length {1.0};
  double width {1.0};
  double height {1.0};
public:
  Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} {}
  Box() = default; 
  double volume() const                              // Function to calculate the volume
  {
    return length*width*height;
  }

  // Accessors
  double getLength() const { return length; }
  double getWidth()  const { return width; }
  double getHeight() const { return height; }

  bool operator<(const Box& aBox) const
  {
     return volume()<aBox.volume(); 
  }
  bool operator<(double value) const;//obj<25
};
inline bool Box::operator<(double value)const
{
    return volume()<value;
}
inline bool operator<(double value,const Box& aBox)//25<ojb
{
    return value<aBox.volume();
}