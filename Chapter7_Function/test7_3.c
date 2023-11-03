//写一个判素数的函数,在主函数输入一个整数,输出是否为素数的信息。
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

int main()
{
    bool sushu();
    bool flag;
    int value;
    printf("请输入一个整数:\n");
    scanf("%d",&value);
    flag = sushu(value);
    if(flag)
        printf("%d是素数\n",value);
    else   
        printf("%d不是素数\n",value);
system("pause");
return 0;
}

bool sushu(int value)
{
    
    for(int i=2;i<value && value%i!=0;i++)
    {
        if(value%i!=0)
            return true;
        else 
            return false;
    }   
}
