#define _CRT_SECURE_NO_WANRNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float sum;
    printf("请输入sum的值：");
    scanf("%f",&sum);
    if (sum<0 || sum>1000)
    {   
       printf("请输入一个0~999的正数：");   
    }
    else
    {
        sum=sqrt(sum); 
        printf("y=%.1f\n",sum); 
    } 
    system("pause");    // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}