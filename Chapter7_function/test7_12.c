/********************************************************************************************
用牛顿迭代法求根。方程为ax^3 + bx^2 + cx + d = 0，系数a,b,c,d的值依次为1,2,3,4,由主函数输入。
求x在1附近的一个实根。求出根后由主函数输出。
*********************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float solut(float a,float b,float c,float d);
    float a,b,c,d;
    printf("请输入a,b,c,d的值:>");
    scanf("%f,%f,%f,%f",&a,&b,&c,&d);
    printf("方程:%dx^3+%dx^2+%dx+%d=0\n",a,b,c,d);
    printf("x=%10.7f\n", solut(a, b, c, d));
    system("pause");
    return 0;
}
float solut(float a,float b,float c,float d)
{
    float x0,x=1,f,f1;
    do
    {
        x0=x;
        f=a*x0*x0*x0 + b*x0*x0 + c*x0 + d;
        f1=3*a*x0*x0+2*b*x0+3;
        x=x0-f/f1;//迭代公式   
    } while (fabs(x-x0)>=1e-3);
    return x;
}
