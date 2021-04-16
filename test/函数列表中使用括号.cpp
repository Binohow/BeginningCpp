#include<iostream>
class Test
{
private:
    int num;
public:
 Test(int n):num(n){}; //  Test(int n):num{n} {};也是可以的 
 /* void show(int n):num{1} //只可以在构造函数上使用
 {}; error */
};


int main()
{
    return 0;
}