#include<iostream>
#include<string_view>
int main()
{
    std::string_view str;
    str=std::string_view{"fdsadfsa",1};
    std::cout<<str<<std::endl;
    return 0;
}