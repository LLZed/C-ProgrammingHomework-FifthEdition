//比较三个字符串，找出“最大者”
#include <stdio.h>
#include "string.h"
#include "stdlib.h"
int main()
{
    char str[3][50];
    char string[50];
    printf("请分别输入三行字符：\n");
    for(int i=0;i<=2;i++)
        gets(str[i]);
    if(strcmp(str[0],str[1])>=0)
    {
        strcpy(string,str[0]);
    }
    else
    {
        strcpy(string,str[1]);
    }
    if(strcmp(string,str[2])<0)
        strcpy(string,str[2]);
    printf("这三行字符最大的为：\n");
    puts(string);
    system("pause");
    return 0;
}