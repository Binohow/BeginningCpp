#include<iostream>
#include<memory>
int main()
{
    
    std::shared_ptr<int> p;
    int* q=new int{1};
    p.reset(q);
    std::cout<<"p= "<<p.get()<<std::endl;
    std::cout<<"q= "<<q<<std::endl;
    return 0;
} 