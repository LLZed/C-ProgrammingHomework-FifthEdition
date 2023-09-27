//写一个函数,输入一个4位数字，要求输出这4个数字字符,但每两个数字间空一个空格。如输入1990,应输出“1 9 9 0”。
#include <stdio.h>
#include <stdlib.h>

int main()
{
    void jiakongge(char string1[],char string2[]);
    char str1[4],str2[10];
    printf("请输入四位数字:\n");
    scanf("%s",str1);
    jiakongge(str1,str2);
    printf("%s",str2);
    system("pause");
    return 0;
}
/*
void jiakongge(char string1[],char string2[])
{
    int i,j;
    for(i=0,j=0; i<4; ++i,++j)
    {
        if(string1[i]!='\0')
        {
        string2[j]=string1[i];
        if(string1[i+1]!='\0')//清除最后一个空格不输出
        string2[j+1]=' ';
        j++;    
        }
    }
}*/
void jiakongge(char string1[],char string2[])
{
    int i=0,j=0;
    while(string1[i]!='\0')
    {
        string2[j]=string1[i];
        string2[j+1]=' ';
        i++;
        j=j+2;    
    }
    string2[j-1]='\0';
}
