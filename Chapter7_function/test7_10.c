//写一个函数,输入一行字符,将此字符串中最长的单词输出。
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int alphabetic(char);
    int LongestWord(char str1[]);//声明函数
    char text[100];//定义字符串变量
    printf("please input line:\n");
    gets(text);
    printf("最长的单词为: \n");
    for(int i=LongestWord(text);alphabetic(text[i]);++i)//从place标记的位置开始输出字符直到不是字母停止
        printf("%c",text[i]);
    printf("\n");
    system("pause");
    return 0;
}
//判断字符是不是字母
int alphabetic(char c)
{
    if((c>='A' && c<='Z') || (c>='a' && c<='z'))
    return 1;
    else
    return 0;
}
/********************************************************
用flag表示单词是否已开始,flag=0表示未开始, flag=1表示单词开始; 
len代表当前单词已累计的字母个数; max_len 代表先前单词中最长单词的长度; 
point代表当前单词的起始位置(用下标表示) ; 
place代表最长单词的起始位置。
函数alphabetic的作用是判断当前字符是否字母,若是则返回l,否则返回0。
********************************************************/
int LongestWord(char str1[])
{
    int max_len = 0,len = 0,i = 0,point=0,flag=1,place=0;
    for(i;i<=strlen(str1);++i)//如果字符不是空字符，就执行
    {
        if(alphabetic(str1[i]))//找到字母，如果返回值为1，表明是字母，执行
        {
            if(flag)//如果flag=1，则单词开始，执行；flag=0,单词未开始不执行
            {
                point=i;//将此时的字符串起始位置标记
                flag=0;//单词未开始
            }
            else //flag=0，执行计数
            len++;//计数单词长度
        }
        else
        {
            flag=1;
            if(max_len<=len)
            {
                max_len=len;
                place=point;//标记最长单词的起始位
                len=0;
            }
        }
    }
return (place);
}

    
