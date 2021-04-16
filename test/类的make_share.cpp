#include<iostream>
#include<memory>
class Test
{
private:
    /* data */
public:
    Test(/* args */);
    ~Test();
};

Test::Test(/* args */)
{
}

Test::~Test()
{
}

int main()
{
    std::shared_ptr<Test> ptr=Test::make_share();
    return 0;
}