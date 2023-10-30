//写一函数，求一个字符串长度。在main中输入字符串，并输出其长度
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len;
    char string[100];
    int count_len(char *p);
    printf("input the string:");
    gets(string);
    len=count_len(string);
    printf("length of string is %d\n",len);
    system("pause");
    return 0;    
}
int count_len(char *p)
{
    int count=0,i=0;
    while(*(p+i)!='\0')
    {
        count++;
        i++;
    }
    return count;
}