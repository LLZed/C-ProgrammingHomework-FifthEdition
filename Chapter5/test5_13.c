//迭代法求x=根号a
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
int main()
{
    double a,x0,x;
    printf("输入a的值: ");
    scanf("%lf",&a);
    x0=a;
    x=(x0+a/x0)/2;
    do
    {
    x0=x;
    x=(x0+a/x0)/2;
    }
    while(fabs(x-x0)>=1e-5);
    printf("The square root of %5.2lf is %8.5lf\n",a,x);
    system("pause");
    return 0;
}