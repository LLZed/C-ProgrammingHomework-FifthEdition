/*编写一个程序，将连个字符串s1和s2比较，如果s1 > s2，输出一个整数；
若s1 = s2，输出0；
若s1 < s2，输出一个负数。不要用strcmp函数。
两个字符串用gets函数读入。
输出的正数或负数的绝对值应是相比较的两个字符串相对应字符的ASCII码的差值。
例如，“A"和“C”相比，由于"A” < “C”，应输出负数，同时由于‘A’与‘C’的ASCII码差值为2，因此应输出"-2"。
同理：“And”和"Aid"相比较，根据第2个字符比较结果，“n"比"i"大5，因此应输出"5”。
解题思路：不能用strcmp函数，那就从前往后逐个字符进行比较，相等时继续往后，不相等时返回该位置两个字符差值。*/
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
    int i,sum;
    // 将s1和s2中的字符从前往后逐个进行比较，相等继续往后，
    // 不相等时sum中结果不为0,循环结束
    // 如果一个走到末尾，一个未走到末尾,循环结束
    // 如果两个字符串相等，同时达到末尾,循环结束
    while ('\0' != str1[i]&&str2[i]!='\0'&&(sum=str1[i]-str2[i])==0)
    i++;
    printf("result=%d\n", sum);
system("pause");
}