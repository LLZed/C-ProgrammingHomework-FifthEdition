#include  <stdio.h>
#include <stdlib.h>

int main()
{
    int *p1,*p2,*p3,*p;
    int a,b,c;
    p1=&a;p2=&b;p3=&c;
    printf("input number:");
    scanf("a=%d,b=%d,c=%d",&a,&b,&c);
    if(*p1>*p2)
        {p=p1;p1=p2;p2=p;
            if(*p1>*p3)
                {p=p1;p1=p3;p3=p;}
        }
    if(*p2>*p3)
        {p=p2;p2=p3;p3=p;} 
    printf("min->max:%d,%d,%d\n",*p1,*p2,*p3);
    system("pause");
    return 0;
}