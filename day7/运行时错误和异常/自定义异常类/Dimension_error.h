#pragma once
#include<iostream>
#include<string>
#include<stdexcept>
class dimension_error:public std::out_of_range 
{
private:
    double value;
public:
    explicit dimension_error(double dim)
    : std::out_of_range("Zero or negative dimension: " + std::to_string(dim)),value{dim}{}
    double getValue() const noexcept { return value; }
};
