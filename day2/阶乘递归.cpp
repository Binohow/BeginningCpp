#include<iostream>
using namespace std;
int f(int n);
int main(void)   
{ 
    cout<<f(3)<<endl;
    return 0;
}
int f(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n*f(n-1);
    }
}