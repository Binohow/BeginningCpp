#include<iostream>
#include<memory>
int main(int argc, char const *argv[])
{
    auto pdata {std::make_unique<double[]>(10)};
    for (size_t i = 0; i < 10; i++)
    {
        pdata[i]=i;
    }
    for (size_t i = 0; i < 10; i++)
    {
        std::cout<<pdata[i]<<std::endl;
    }
    return 0;
}