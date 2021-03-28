#include<iostream>
#include"box.h"
int main()
{
    Box box1{2,3,4};
    Box box2{5};
    std::cout << "box1 volume = " << box1.volume() << std::endl;
    std::cout << "box2 volume = " << box2.volume() << std::endl;
    return 0;
}