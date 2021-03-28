#include<iostream>
using namespace std;
template <typename T>
void sort(T *a,int n)//降序
{
    for (size_t i = 0; i < n; i++)
    {
        int p=i;
        for (size_t j = i+1; j < n; j++)
        {
            if(a[p]<a[j]) p=j;
        }
        T t=a[i];
        a[i]=a[p];
        a[p]=t;
    }  
}

template <typename T>
void display(T *a,int n)
{
    for(size_t i=0; i<n; i++)
    {
        cout<<a[i]<<"\t"<<endl;
    }
}
int main(int argc, char const *argv[])
{
    int a[]={1,41,2,5,8,21,23};
    char b[]={'a','x','y','e','q','g','o','u'};
    sort(a,7);
    sort(b,8);
    display(a,7);
    display(b,8);
    return 0;
}
