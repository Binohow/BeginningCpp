#include<iostream>
using WEEK=enum{
s,m,t,w,thu,f,s1
};
int main(int argc, char const *argv[])
{
    WEEK w=s;
    for (int i = w; i!=f; i++)
    {
        std::cout<<i<<std::endl;
        std::cout<<w+s<<std::endl;
        std::cout<<"-------哈哈-------"<<std::endl;
    }
    
    return 0;
}