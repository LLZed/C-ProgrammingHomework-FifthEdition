//用二分法求方程在（-10,10）的根，普遍适用的代码：
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
int main()
{
    float x0,x1,x2,fx0,fx1,fx2;
    do
    {
    printf("输入x1 x2的值,空格隔开:");
    scanf("%f %f",&x1,&x2);
    fx1=2*x1*x1*x1-4*x1*x1+3*x1-6;
    fx2=2*x2*x2*x2-4*x2*x2+3*x2-6;
    } while(fx1*fx2 > 0);
    do
    {
    x0=(x1+x2)/2;
    fx0=2*x0*x0*x0-4*x0*x0+3*x0-6;
    if((fx0*fx1)<0)
        {
            x2=x0;
            fx2=fx0;
        }
    else
        {
            x1=x0;
            fx1=fx0;
        }         
    } while(fabs(fx0)>=1e-5);
    printf("The square root is %5.3f\n",x0);
    system("pause");
    return 0;
}

//针对这题还有更简单的代码,如下：
/*#include "stdio.h"
#include "stdlib.h"
#include "math.h"
int main()
{
    float x0,fx=1;
    float x1=-10,x2=10;
    while(fabs(fx)>=1e-5)
    {
    x0=(x1+x2)/2;
    fx=2*x0*x0*x0-4*x0*x0+3*x0-6;
    if((fx)<0)
        {
            x1=x0;
        }
    else if((fx)>0)
        {
            x2=x0;
        }         
    }
    printf("The square root is %5.3f\n",x0);
    system("pause");
    return 0;
}*/