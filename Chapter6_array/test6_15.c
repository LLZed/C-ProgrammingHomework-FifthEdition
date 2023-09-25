//编写一个程序，将字符数组s2中的全部字符复制到字符数组s1中，不用strcpy函数。
//复制时，‘\0’也要赋值过去。’\0’之后的字符不复制。
#include <stdio.h>
#include "stdlib.h"
#include <string.h>
#define M 100
#define N 100
/*
void main()
{
    char str1[M],str2[N];

    printf("请输入字符串1：\n");
    gets(str1);
    printf("请输入字符串2：\n");
    gets(str2);
    int i;
    while (str2[i]!='\0')
    {
        str1[i]=str2[i];
        i++;
    }
    while (str2[i]=='\0')
    {
        str1[i]='\0';
        i++;
    }
    printf("result=%s\n", str1);
system("pause");
}
*/
int main()
{
    char str1[M],str2[N];

    printf("请输入字符串1：\n");
    gets(str1);
    printf("请输入字符串2：\n");
    gets(str2);
    int i;
    while (str2[i]!='\0')
    {
        str1[i]=str2[i];
        i++;
    }
    str1[i]=str2[i];
    printf("result=%s\n", str1);
system("pause");
return 0;
}