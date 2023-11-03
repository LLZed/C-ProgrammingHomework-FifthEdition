//有n个人围成一圈顺序排序，从第一个人开始报数，从1报到3，凡是报到3的退出圈子，问最后留下来的是原来第几号的那位
#include  <stdio.h>
#include <stdlib.h>

int main()
{
    int i,k,m,n,num[100],*p;
    printf("input number of person:n=");
    scanf("%d",&n);
    p=num;
    for(i=0;i<n;i++)
        *(p+i)=i+1;             //以1至n为序给每个人编号
    i=0;                        //每次循环计数变量
    k=0;                        //k从1到3
    m=0;                        //退出的总人数，m=n-1时就剩一个人了
    while (m<n-1)
    {
        if(*(p+i)!=0)
            k++;
        if(k==3)                //当k=3，即报数报到3时
        {
            k=0;                //k置0
            *(p+i)=0;           //让当前序号的人的编号为0，表示退出
            m++;                //退出人数+1
        }
        i++;
        if(i==n)
            i=0;                    //继续循环报数踢人直到退出的人数为n-1个人（即只剩下一个人）
    }
    while(*p==0)
       p++;     
    printf("the last one is No.%d\n",*p);
    system("pause");
    return 0;
}