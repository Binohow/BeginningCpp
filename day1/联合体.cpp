#include<iostream>
#include <iomanip>
using test = union myunion
{
    struct { int x; int y; int z; }u; 
    int k; 
};

int main(int argc, char const *argv[])
{
    test a;
    a.u.x=1;
    a.u.y=2;
    a.u.z=3;
    std::cout<<sizeof(test)<<std::endl;
    char *p=(char *)&a.u.x;
    for (int i = 0; i < sizeof(test); i++)
    {     
       printf("%#x\n",*p);
       p++;
    }
    p=(char *)&a.u.x;
    for (int i = 0; i < sizeof(test); i++)
    {     
       std::cout<<std::setbase(16)<<std::showbase<<(int)*p<<std::endl;
       p++;
    }
    return 0;
}