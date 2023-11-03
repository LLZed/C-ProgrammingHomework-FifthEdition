#define _CRT_SECURE_NO_WANRNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float x,y;
    printf("请输入xy的值,用逗号隔开：");
    scanf("%f,%f",&x,&y);
    float fx=fabs(x);//求绝对值
    float fy=fabs(y);
    float lx=fabs(fx-2);//求相对圆心的坐标
    float ly=fabs(fy-2);
    float len=sqrt(lx*lx+ly*ly);//求平方根
    if (len>1)
    {   
       printf("输入的位置上的建筑物高度为 0m\n");    
    }
    else if(len<1)
    {
      printf("输入的位置上的建筑物高度为 10m\n");  
    }
    system("pause");    // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}