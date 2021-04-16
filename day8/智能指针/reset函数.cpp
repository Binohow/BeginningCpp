#include<iostream>
#include<memory>
#define newline std::cout<<std::endl;
class Test
{
private:
    int n=8;
public:  
    explicit Test(int n);
    ~Test();
    void show() const
    {
        std::cout<<"n="<<n<<std::endl;
    }

};
void __delete(Test * test)
{
    std::cout<<"__delete is called "<<std::endl;
    test->show();
    test->~Test();
}
Test::Test(int n):n{n}
{
    std::cout<<"consturctor is called \n"<<"n="<<n<<std::endl;

}

Test::~Test()
{ 
    std::cout<<"deconsturctor is called \n"<<"n="<<n<<std::endl;
}

int main()
{
    std::shared_ptr<Test> pTest=std::make_shared<Test>(1);
    pTest->show();
    pTest.reset(new Test(9));
    newline
    pTest->show();
    newline
    pTest.reset(new Test(6),__delete);
    pTest->show();
    newline

    for (size_t i = 0; i < 100; i++)
    {
        std::cout<<i<<"\t";
        if(((i+1)%10)==0) newline
    }
    newline
    return 0;
}