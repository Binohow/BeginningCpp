#include<cstdlib>
#include<ctime>
#include"TruckLoad.h"
inline unsigned random(size_t count)
{
    return 1+static_cast<unsigned>(std::rand()/(RAND_MAX/count+1));
}
inline ShareBox randomBox()
{
    const size_t dimLimit {99};
    return std::make_shared<Box>(random(dimLimit),random(dimLimit),random(dimLimit));
}
int main()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    TruckLoad load1;

    const size_t boxCount{12};
    for (size_t i = 0; i < boxCount; i++)
    {
        load1.addBox(randomBox());
    }
    
    std::cout << "The first list:\n";
    load1.listBoxes();

    TruckLoad copy{load1};
    std::cout << "The copied truckload:\n";
    copy.listBoxes();

    ShareBox largestBox{load1.getFirstBox()};
    ShareBox nextBox{load1.getNextBox()};

    while(nextBox)
    {
        if(nextBox->compare(*largestBox)>0)
            largestBox=nextBox;
        nextBox=load1.getNextBox();
    }
    
    std::cout << "\nThe largest box in the first list is ";
    largestBox->listBox();
    std::cout << std::endl;
    load1.removeBox(largestBox);
    std::cout << "\nAfter deleting the largest box, the list contains:\n";
    load1.listBoxes();
    
    const size_t nBoxes {20};            // Number of vector elements
    std::vector<ShareBox> boxes;

    for (size_t i = 0; i < nBoxes; i++)
        boxes.push_back(randomBox());

    TruckLoad load2{boxes};
    std::cout << "\nThe second list:\n";
    load2.listBoxes();

    auto smallestBox{load2.getFirstBox()};
    for (auto nextBox{load2.getNextBox()}; nextBox; nextBox=load2.getNextBox())
    {
        if (nextBox->compare(*smallestBox)<0)
        {
           smallestBox=nextBox;
        }
    }
    
    std::cout << "\nThe smallest box in the second list is ";
    smallestBox->listBox();
    std::cout << std::endl;
}