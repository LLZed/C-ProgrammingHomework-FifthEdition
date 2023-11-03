//用递归方法求n阶勒让德多项式的值,递归公式为书上所给
#include <stdio.h>
#include <stdlib.h>
int main()
{
    float p(int,int);
    int x,n;
    printf("请输入n,x的值:>");
    scanf("%d,%d",&n,&x);
    printf("n=%d,x=%d\n",n,x);
    printf("p%d(%d)=%.2f\n", n,x,p(n,x));
    system("pause");
    return 0;
}
float p(int n,int x)
{
    float z;
    if(n==0)
    return 1;
    else if(n==1)
    return x;
    else
    {
        z=((2*n-1)*x-p(n-1,x)-(n-1)*p(n-2,x))/n;
        return z;
    }
}