/*
有一行电文，以按下面规律译成密码：
A--->Z   a--->z
B--->Y   b--->Y
C--->X   c--->x
……
即第1个字母变成第26个字母，第i个字母变成第(26-i+1)个字母，非字母字符不变
要求编程序将密码译回原文，并输出密码和原文。
*/
#include <stdio.h>
#include "stdlib.h"
#define M 100
void main()
{
    char array[M];
    printf("请输入电文:\n");
    gets(array);
    printf("原电文为:\n");
    puts(array);
    int i=0;
        while (array[i]!='\0')
        {
            if(array[i]>='A'&&array[i]<='Z')
                array[i]=155-array[i];
            else if(array[i]>='a'&&array[i]<='z')
                array[i]=219-array[i];
            else
                array[i]=array[i];
        i++;
        }
    printf("密码原文为:\n");
    puts(array); 
system("pause");
}