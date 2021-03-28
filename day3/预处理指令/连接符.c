#include<stdio.h>
#define Print_Fun(name,count,value)\
void name##count(){ printf(#value);}
Print_Fun(my,123,hello\n);
int main()
{
    printf("hello\n");
    my123();
    return 0;
}