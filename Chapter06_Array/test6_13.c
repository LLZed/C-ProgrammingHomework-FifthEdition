//编一程序，将两个字符串连接起来，不要用strcat函数
#include <stdio.h>
#include "stdlib.h"
#include <string.h>
#define M 100
#define N 100
void main()
{
    char str1[M],str2[N];

    printf("请输入字符串1：\n");
    gets(str1);
    printf("请输入字符串2：\n");
    gets(str2);
    printf("拼接后的字符串为:\n");
    int i=0,j=0;
    while ('\0' != str1[i])
	{	
        i++;
    }
	while (str2[j]!='\0')
    str1[i++] = str2[j++];

    // printf("请输入字符串1：\n");
	// scanf("%s",&str1[M]);
    // printf("请输入字符串2：\n");
	// scanf("%s",&str2[N]);
    // printf("%s\n", str1);
    // printf("%s\n", str2);
    // printf("拼接后的字符串为:\n");
    // int i=0,j=0;
    // while ('\0' != str1[i])
	// i++;
    // while (str2[j]!='\0')
    // str1[i++] = str2[j++];

    printf("%s\n", str1);
system("pause");
}