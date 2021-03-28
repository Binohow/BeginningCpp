#pragma once
#include<iostream>
class Vessel
{
public:
    virtual ~Vessel()=default;
    virtual double volume() const=0;
};