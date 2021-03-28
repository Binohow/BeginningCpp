#pragma once
#include <memory>
#include "Box.h"
using ShareBox=std::shared_ptr<Box>;
class Package
{
private:
    ShareBox pBox;
    Package * pNext;
public:
    Package(ShareBox pb):pBox{pb},pNext{nullptr}{}
    Package(/* args */)=default;
    ~Package(){delete pNext;}
    
    ShareBox getBox()const {return pBox;}
    Package * getNext() {return pNext;}
    void setNext(Package *pPackage) {pNext=pPackage;}
};
