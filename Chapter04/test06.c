#define _CRT_SECURE_NO_WANRNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int x,y;
    printf("请输入x的值：");
    scanf("%d",&x);
    if (x<1)
    {   
        y=x;  
    }
    else if(x>=1 && x<10)
    {
        y=2*x-1;  
    }
    else if(x>=10)
    {
        y=3*x-11; 
    }
    printf("y=%d\n",y);
    system("pause");    // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}