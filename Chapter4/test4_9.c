#define _CRT_SECURE_NO_WANRNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num,a;
    printf("请输入不大于5位的正整数：");
    scanf("%d",&num);
    if (num<0||num>=99999)
    {   
        printf("输入的数据不符合规则！\n");
        return -1;  
    }
    if(num>=10000)
    {
        a=5;
        printf("这个数是5位数！\n"); 
    }
    else if(num>=1000&&num<10000)
    {
        a=4;
        printf("这个数是4位数！\n");  
    }
    else if(num>=100&&num<1000)
    {
        a=3;
        printf("这个数是3位数！\n"); 
    }
    else if(num>=10&&num<100)
    {
        a=2;
        printf("这个数是2位数！\n"); 
    }
    else 
    {
        a=1;
        printf("这个数是1位数！\n"); 
    }
    int indiv,ten,hundred,thousand,ten_thousand;
    printf("每位数为：\n");
     ten_thousand=num/10000;
     thousand=(int)(num%10000/1000);
     hundred=(int)(num%10000%1000/100);
     ten=(int)(num%10000%1000%100/10);
     indiv=(int)(num%10000%1000%100%10);
     switch (a)
     {
     case 5/* constant-expression */:
        printf("%d,%d,%d,%d,%d",ten_thousand,thousand,hundred,ten,indiv); /* code */
        printf("\n逆序输出：");
        printf("%d,%d,%d,%d,%d\n",indiv,ten,hundred,thousand,ten_thousand);
        break;
     case 4/* constant-expression */:
        printf("%d,%d,%d,%d",thousand,hundred,ten,indiv); /* code */
        printf("\n逆序输出：\n");
        printf("%d,%d,%d,%d\n",indiv,ten,hundred,thousand);
        break;
    case 3/* constant-expression */:
        printf("%d,%d,%d",hundred,ten,indiv); /* code */
        printf("\n逆序输出：\n");
        printf("%d,%d,%d\n",indiv,ten,hundred);
        break;
    case 2/* constant-expression */:
        printf("%d,%d",ten,indiv); /* code */
        printf("\n逆序输出：\n");
        printf("%d,%d\n",indiv,ten);
        break;
    case 1/* constant-expression */:
        printf("%d",indiv); /* code */
        printf("\n逆序输出：\n");
        printf("%d\n",indiv);
        break;
     }
    system("pause");    // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}