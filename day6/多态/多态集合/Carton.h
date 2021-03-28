#pragma once
#include"Box.h"
class Carton:public Box
{
private:
    /* data */
    std::string material;

public:
    Carton(double lv, double wv, double hv,std::string_view str = "material"):Box{lv,wv,hv},material{str}
    {}
    double volume(int i=50) const override
    {
        std::cout << "Carton parameter = " << i << std::endl;
        const double vol {(length - 0.5)*(width - 0.5)*(height - 0.5)};
        return vol > 0.0 ? vol : 0.0;
    }
};
