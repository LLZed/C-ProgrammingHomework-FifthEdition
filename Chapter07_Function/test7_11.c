//写一个函数,用“起泡法”输入的10个字符按由小到大顺序排列。
/*外层循环控制排序的趟数，内层循环主要是进行每一趟排序的比较
如果前面的字符大于后面的字符，就进行交换，每做一趟排序，就把一个最大字符排在最后
每做一趟排序就需要少比较一个字符。*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define M 10
int main()
{
    void sort(char str[]);
    char str[M];
    int i,flag;//用flag做标记识别是否字符串过长
    for(flag=1;flag==1;)//字符串过长，flag=1，循环输入字符串功能语句
	{
        printf("请输入10个字符:>");    
		scanf("%s", &str);
        if(strlen(str) > M)//计算字符串长度，判断字符串是否过长
            {
                printf("字符过长，请重新输入!\n");
                flag=1;//跳回for循环开头重新执行
            }
        else
            flag=0;//字符串没有超过，令flag=0跳出for循环
    }
    sort(str);
    printf("排序后的字符为:\n");
    printf("%s",str);
    printf("\n");
    system("pause");
    return 0;
}

void sort(char str[])
{
    int i,j;
    char tmp;
    for(i=0;i<M;++i)//两两比较大小所以进行9次循环，实现9趟比较
    { 
        for(j=0;(j<M-1-i) && (str[j]!='\0');++j)//在每一趟中进行9-i次比较
        {
            if(str[j]>str[j+1])//两两比较大小
            {
                tmp=str[j+1];
                str[j+1]=str[j];
                str[j]=tmp;
            }
        }
    }
}
