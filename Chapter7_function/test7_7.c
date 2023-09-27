//写一个函数,将一个字符串中的元音字母复制到另一字符串,然后输出。
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    void yuanyin(char string1[], char string2[]);//声明被调用的函数
    char string1[100],string2[100];//定义字符串
    printf("请输入string1:\n");//输入字符串
    scanf("%s",string1);
    yuanyin(string1,string2);//调用函数
    printf("The vowel letters are:%s\n",string2);
system("pause");
return 0;    
} 

void yuanyin(char string1[], char string2[])
{
    int i,j;
    for(i=0,j=0;i<strlen(string1);++i)
    {
        if(string1[i]=='a'  || string1[i]=='o' || string1[i]=='e'  || string1[i]=='i' || string1[i]=='u'
            || string1[i]=='A' || string1[i]=='O' || string1[i]=='E' || string1[i]=='I' || string1[i]=='U')
        {
            string2[j]=string1[i];
            j++;
        }
    }
}
