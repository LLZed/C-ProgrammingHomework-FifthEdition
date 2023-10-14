//求1！+2！+3!+...+20!

#include <stdio.h>
#define _CRT_SECURE_NO_WANRNINGS
#include <stdlib.h>
int main()
{
    int n=20;
    double total_sum=0.0;
    double num=1;
    for (int i=1;i<=n;i++)
    { 
        num=num*i;
        total_sum+=num;
    }
    printf("%lf\n",total_sum); 
system("pause");
return 0;
}
