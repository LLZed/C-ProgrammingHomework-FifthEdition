#define _CRT_SECURE_NO_WANRNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c,d,tmp;
    printf("请输入abcd的值,用逗号隔开：");
    scanf("%d,%d,%d,%d",&a,&b,&c,&d);
    //找出最大的数
    if (a<b)
    {   
       tmp=a,a=b,b=tmp;
       if (a<c)
       {
        tmp=a,a=c,c=tmp;
       } 
       if (a<d)
       {
       tmp=a,a=d,d=tmp;
       }     
    }
    if(b<c)
    {
       tmp=b,b=c,c=tmp; 
       if(b<d)
       {
        tmp=b,b=d,d=tmp;
       }
    }
    if (c<d)
    {
       tmp=c,c=d,d=tmp;
    } 
    printf("%d,%d,%d,%d\n",d,c,b,a);
    system("pause");    // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}