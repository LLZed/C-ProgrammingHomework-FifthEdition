//找出1000内的所有完数
#define _CRT_SECURE_NO_WANRNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int sum,num,i;
    for (num=2;num<=1000;num++)
    { 
        sum=0;
        for(i=1;i<num;i++)
        {
            if (num%i==0)
            sum=sum+i;
        }
        if (sum==num)
        {   
            printf("%d its factors are: ",num);
            for(i=1;i<num;i++)
             {
                 if (num%i==0)
                 printf("%d ",i);
             }
             printf("\n");
        }
    }        
system("pause");
return 0;
}
