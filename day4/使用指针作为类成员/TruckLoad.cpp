#include"TruckLoad.h"
TruckLoad::TruckLoad(const std::vector<ShareBox>& boxes)
{
    for(const auto& pBox:boxes)
    {
        addBox(pBox);
    }
}
TruckLoad::TruckLoad(const TruckLoad& src)
{
    for(Package* package{src.pHead}; package;package=package->getNext())
    {
        addBox(package->getBox());
    }
}
void TruckLoad::listBoxes() const
{
    const size_t boxesPerLine =5;
    size_t count {};
    for (Package* package = this->pHead; package; package=package->getNext())
    {
        package->getBox()->listBox();

        if(!(++count%boxesPerLine)) std::cout<<std::endl;
    }
    if(++count%boxesPerLine) std::cout<<std::endl;
}
ShareBox TruckLoad::getFirstBox()
{
    pCurrent=pHead;
    return pCurrent?pCurrent->getBox():nullptr;
}
ShareBox TruckLoad::getNextBox()
{
    if(!pCurrent)
        return this->getFirstBox();
    pCurrent=pCurrent->getNext();
    return pCurrent?pCurrent->getBox():nullptr;
}
void TruckLoad::addBox(ShareBox pBox)
{
    auto pPackage=new Package{pBox};
    if(this->pTail)
        pTail->setNext(pPackage);
    else
        pHead=pPackage;
    
    pTail=pPackage;
}
bool TruckLoad::removeBox(ShareBox boxToRemove)
{
    Package *pCurrent{pHead};
    Package *pPrevious{nullptr};
    while(pCurrent)
    {
        if(pCurrent->getBox()==boxToRemove)
        {
            if(pPrevious)
            {
                pPrevious->setNext(pCurrent->getNext());
            }
            else
            {
                pHead=pCurrent->getNext();
            }

            pCurrent->setNext(nullptr);
            delete pCurrent;
            return true;
        }
        pPrevious=pCurrent;
        pCurrent=pCurrent->getNext();
    }
    return false;
}
