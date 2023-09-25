//求（1+2+...+100）+（1^2+2^2+...+50^2）+（1/1+1/2+1/3+...+1/10）
#define _CRT_SECURE_NO_WANRNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int sum1=0,sum2=0;
    float sum3=1.0,sum=0.0;
    for (int i=1;i<=100;i++)
    { 
        if (i<=10)
        {
            sum3+=1.0/i;
        }
        //1^2+2^2+3^2+4^2+...+50^2
        if (i<=50)
         {
            sum2+=i*i;
         } 
         //1+2+3+4+...+100  
        if(i<=100)
        {
            sum1+=i;
        }      
    }
    sum=sum1+sum2+sum3;   
printf("%lf\n",sum); 
system("pause");
return 0;
}