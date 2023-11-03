//写一个函数,将两个字符串连接。不用strcat函数
#include <stdio.h>
#include <stdlib.h>
int main()
{
    void ConcatString(char string1[], char string2[], char string[]);//声明被调用的函数
    char string[100];//定义字符串
    char string1[50],string2[50];
    printf("请输入string1:\n");
    scanf("%s",string1);//输入字符串
    printf("请输入string2:\n");
    scanf("%s",string2);//输入字符串
    ConcatString(string1,string2,string);//调用函数
    printf("连接后的字符为:%s\n", string);
system("pause");
return 0;    
} 
void ConcatString(char string1[], char string2[], char string[])
{
    int i,j;
    for(i=0;string1[i]!='\0';++i)
    string[i]=string1[i];           //将string1的值全部给到string
    for(j=0;string2[j]!='\0';++j)   //找到字符串末尾后，继续往后面链接字符串
    string[i+j]=string2[j];         //从i+j位置开始将string2的值给到string
    string[i+j]='\0';
}