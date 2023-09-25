//猴子吃桃，第一天吃了一半＋1个，接下来每天都吃一半多一个，第十天还剩1个，求猴子第一天摘了几个桃子
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n=1;
    int day=10;
    int sum=0;
    while(day>1)
    {
        sum=(n+1)*2;
        n=sum;
        day--;
    }
    printf("第一天摘的桃子为：%d\n",sum);  
system("pause");
return 0;
}
