#pragma once
#include "Package.h"
#include <vector>
class TruckLoad
{
private:
    Package * pHead{};
    Package * pTail{};
    Package * pCurrent{};
public:
    TruckLoad(/* args */)=default;
    TruckLoad(ShareBox box){pHead=pTail=new Package(box);}
    TruckLoad(const std::vector<ShareBox> &boxes);
    TruckLoad(const TruckLoad& src);
    
    ~TruckLoad(){delete pHead;}

    ShareBox getFirstBox();
    ShareBox getNextBox();
    void addBox(ShareBox box);
    bool removeBox(ShareBox boxToRemove);
    void listBoxes() const;
};
