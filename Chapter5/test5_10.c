//求分数序列2/1,3/2,5/3,8/5,...的前20项之和
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,n=20;
    double a=2,b=1,sum=0,t;
    for (i=1;i<=n;i++)
    {
        sum=sum+a/b;
        t=a;
        a=a+b;
        b=t;
    }      
printf("sum  =%16.10f\n",sum);
system("pause");            
return 0;
}
