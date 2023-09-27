//写一个函数,使输入的一个字符串按反序存放,在主函数中输入和输出字符串。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    void ReverseString(char str[100]);//声明被调用的函数
    char str[100];//定义字符串
    printf("请输入字符:\n");
    scanf("%s",str);//输入字符串
    printf("原始字符串为:%s\n", str);
    ReverseString(str);//调用函数
    printf("反序存放后的字符为:%s\n", str);
system("pause");
return 0;    
} 

void ReverseString(char str[])
{
    char t;
    for(int i=0,j=strlen(str);i<(strlen(str)/2);++i,--j)
    {
        t=str[i];
        str[i]=str[j-1];
        str[j-1]=t;
    }
}