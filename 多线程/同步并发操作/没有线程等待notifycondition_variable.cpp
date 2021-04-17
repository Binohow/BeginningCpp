#include<iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>
#include <chrono>
std::deque<int> q;
std::mutex mu;
std::condition_variable cond;
void foo_1()
{
    int count=10;
    while (count>0)
    {
        std::unique_lock<std::mutex> locker(mu);
        q.push_front(count);
        locker.unlock();
        std::cout<<"will call  cond.notify_one() "<<std::endl;
        cond.notify_one();
        std::cout<<"called  cond.notify_one() "<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count--;
    }
    
}
// void foo_2()
// {
//     int data=0;
//     while (data!=1)
//     {
//         std::unique_lock<std::mutex> locker(mu);
//         cond.wait(locker);
//         data=q.back();
//         q.pop_back();
//         locker.unlock();
//         std::cout<<"t2 got a value from t1 "<<data<<std::endl;
//     }
    
// }
int main()
{
    std::thread t1(foo_1);
    // std::thread t2(foo_2);
    t1.join();
    // t2.join();
}