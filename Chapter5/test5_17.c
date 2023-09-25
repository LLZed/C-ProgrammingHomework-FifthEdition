//寻找A，B，C各自的对手x，y，z
#include "stdio.h"
#include "stdlib.h"
int main()
{
    char i,j,k;  //i是A的对手，j是B的对手，k是C的对手
    for(i='x';i<='z';i++)
        for(j='x';j<='z';j++)
        if(i!=j)    //对手不能一样
            for(k='x';k<='z';k++)
            if(i!=k && j!=k)    //对手不能一样
                if(i!='x' && k!='x' && k!='z')  //又题目分析得来的A，B，C对手的限制
    printf("A--%c\nB--%c\nC--%c\n",i,j,k);
    system("pause");
    return 0;
}