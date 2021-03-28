#include<iostream>
#define Print_Fun(name,count,value)\
void name##count(){ printf(#value);}
Print_Fun(my,123,hello\n)
int main()
{
    printf("hello\n");
    my123();
    return 0;
}
/*
## 相当于string中的+号连接符
#  相当于 用双引号""包裹相应变量
 */