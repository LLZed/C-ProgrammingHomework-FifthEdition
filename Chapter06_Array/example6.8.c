//输入一行字符，统计其中有多少个单词
#include <stdio.h>
#include "string.h"
#include "stdlib.h"
int main()
{
    int num=0,word=0;
    char string[100];
    char a;
    printf("请输入一行字符：\n");
    gets(string);
    for(int i=0;(a=string[i])!='\0';i++)
    {
        if(a==' ')
        word=0;
        else if(word==0)
        {
            word=1;
            num++;
        }
    }
    printf("这一行字符的单词数为：%d\n",num);
    system("pause");
    return 0;
}