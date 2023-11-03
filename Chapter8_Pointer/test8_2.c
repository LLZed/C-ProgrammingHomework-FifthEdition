/*2. 输入3个字符串，要求按由小到大的顺序输出。
解题思路： 
字符串的比较可以使用strcmp函数，返回值>0表示大于，返回值小于0表示小于，返回追等于0表示相同。
其他的比较排序思路与数字的排序交换没有区别，逐个进行比较先找出最大的，然后找出第二大的。
*/

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