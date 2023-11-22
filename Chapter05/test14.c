//用牛顿迭代法求方程在1.5附近的根
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
int main()
{
    double x0,x1,fx0,fx;
    x1=1.5;
    do
    {
    x0=x1;
    fx0=2*x0*x0*x0-4*x0*x0+3*x0-6;
    fx=6*x0*x0-8*x0+3;
    x1=x0-fx0/fx;
    }
    while(fabs(x1-x0)>=1e-5);
    printf("The square root is %8.5lf\n",x1);
    system("pause");
    return 0;
}