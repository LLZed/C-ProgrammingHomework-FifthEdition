//写两个函数,分别求两个整数的最大公约数和最小公倍数,用主函数调用这两个函数,并输出结果。两个整数由键盘输入。
/*
该题直接使用“辗转相除法”来求解最大公约数和最小公倍数
最大公约数找出两数中的最小值，然后直接相模，当能够同时被两数整除时，则为最大公约数。
最小公倍数找出两数中的最大值，然后直接进入死循环，直到找到一个数能够同时被两数整除时，则为最小公倍数
*/
#include <stdio.h>
#include "stdlib.h"
int hcf(int x,int y);//函数全局声明
int lcd(int x,int y,int z);//函数全局声明
int main()
{
    int a,b,h,l;
    printf("输入两个整数:\n");
    scanf("%d,%d",&a,&b);
    h=hcf(a,b);
    l=lcd(a,b,h);
    printf("最大公约数为:%d\n",h); //调用标准C库函数
    printf("最小公倍数为:%d\n",l); //调用标准C库函数    
system("pause");
return 0;
}
//辗转相除法求最大公约数
int hcf(int x,int y) //定义有参函数，辗转相除法求最大公约数
{
    int i,j;
    if(x<y)
    {
    i=x;
    x=y;
    y=i;
    }
    while ((j=x%y)!=0)
    {
       x=y;
       y=j; 
    }
return y;
}
//求最小公倍数
int lcd(int x,int y,int z)//定义有参函数，求最小公倍数
{
    int k;
    k=(x*y)/z;
return k;
}