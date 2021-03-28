#include"Box.h"
#include"Carton.h"
#include"ToughPack.h"
#include<vector>
#include<memory>
void showVolume(const Box& rBox)//通过引用在函数体中支持多态
{
    std::cout << "Box usable volume is " << rBox.volume() << std::endl;
}
int main()
{
    Box box {20.0, 30.0, 40.0};
    ToughPack hardcase {20.0, 30.0, 40.0};         // A derived box - same size
    Carton carton {20.0, 30.0, 40.0, "plastic"};   // A different derived box

    box.showVolume();
    hardcase.showVolume();
    carton.showVolume();
    std::cout << "hardcase volume is " << hardcase.volume() << std::endl;

    Box* pBox{&box};
    std::cout << "\nbox volume through pBox is " << pBox->volume() << std::endl;
    pBox->showVolume();

    pBox=&hardcase;
    std::cout << "hardcase volume through pBox is " << pBox->volume() << std::endl;
    pBox->showVolume();

    pBox = &carton;                              // Points to type Carton
    std::cout << "carton volume through pBox is " << pBox->volume() << std::endl;
    pBox->showVolume();

    std::cout<<std::endl;
    showVolume(box);
    showVolume(hardcase);
    showVolume(carton);

    // 多态集合
    std::cout<<std::endl;
    std::vector<std::unique_ptr<Box>> polymorphicBoxes;
    polymorphicBoxes.push_back(std::make_unique<Box>(20.0, 30.0, 40.0));
    polymorphicBoxes.push_back(std::make_unique<ToughPack>(20.0, 30.0, 40.0));
    polymorphicBoxes.push_back(std::make_unique<Carton>(20.0, 30.0, 40.0,"plastic"));

    for (const auto &p:polymorphicBoxes )
    {
        p->showVolume();
    }
    
} 