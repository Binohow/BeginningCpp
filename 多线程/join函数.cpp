#include<iostream>
#include<thread>
using namespace std;
void func()
{
  
   for(int i =0; i <=15; i++)
    {
        cout << "from func():" << i << endl;
    }
}
int main()
{
    thread t(func);	//子线程
    t.detach();		//分离子线程
    for (size_t i = 0; i < 5; i++)
    {
        cout << "mian()" << endl;
    }
    return 0;
}