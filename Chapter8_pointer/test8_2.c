#include  <stdio.h>
#include <stdlib.h>
#include  <string.h>
#define N 10

int main()
{
    char *p1,*p2,*p3,*p;
    char str[3][N];
    p1=str[0];p2=str[1];p3=str[2];
    printf("input string:\n");
    for(int i=0;i<3;i++)
    {
        printf("第%d个字符串",i+1);
        scanf("%s",str[i]);
    }
    getchar();      //消耗回车
    if(strcmp(p1,p2)>0)
        {p=p1;p1=p2;p2=p;
            if(strcmp(p1,p3)>0)
                {p=p1;p1=p3;p3=p;}
        }
    if(strcmp(p2,p3)>0)
        {p=p2;p2=p3;p3=p;} 
    printf("min->max:%s,%s,%s\n",p1,p2,p3);
    system("pause");
    return 0;
}