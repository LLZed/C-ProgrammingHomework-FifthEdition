/*
1. 输入3个整数，要求按由小到大的顺序输出。
解题思路： 先获取到三个变量的地址，然后获取三个数据，通过指针进行比较转换即可
*/ 

#include  <stdio.h>
#include <stdlib.h>

int main()
{
    int *p1,*p2,*p3,*p;
    int a,b,c;
    //获取到三个变量的地址
    p1=&a;
    p2=&b;
    p3=&c;
    printf("input number:");
    scanf("%d %d %d",&a,&b,&c);
    if(*p1>*p2){
        p=p1;
        p1=p2;
        p2=p;
        if(*p1>*p3){
            p=p1;
            p1=p3;
            p3=p;
        }
    }
    if(*p2>*p3){
        p=p2;
        p2=p3;
        p3=p;
    } 
    printf("min->max:%d < %d < %d\n",*p1,*p2,*p3);
    system("pause");
    return 0;
}