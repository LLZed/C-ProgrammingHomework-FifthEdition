//编写一个函数,由实参传来一个字符串,统计此字符串中字母、数字、空格和其他字符的个数,在主函数中输入字符串以及输出上述的结果。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
int letter= 0, digit = 0, space = 0, other = 0;
int main()
{
    void tongji(char str[]);
    char text[100];
    printf("please input line:\n");
    gets(text);
    printf("string: %s\n", text);
    tongji(text);
    printf("letter case: %d\n", letter);
    printf("digit case: %d\n", digit);
    printf("space case: %d\n", space);
    printf("other case: %d\n", other);
    system("pause");
    return 0;
}
void tongji(char str[])
{
    // 统计该行文本中字母、数字、空格、其他字符的个数
        for (int i=0; i<100 && str[i]!='\0'; ++i)
        {
            if (str[i]>='A'&& str[i]<='Z' || str[i]>='a' && str[i]<='z')   // 字母
                letter++;
            else if (str[i]>='0' && str[i]<='9')  // 数字
                digit++;
            else if (str[i]==' ')  // 空格
                space++;
            else
                other++;   // 其他字符
        }
}
*/

int main()
{
    void tongji(char str[],char a[]);
    char text[100],a[4]={'0','0','0','0'};
    printf("please input line:\n");
    gets(text);
    printf("string: %s\n", text);
    tongji(text,a);
    printf("letter case: %c\ndigit case: %c\nspace case: %c\nother case: %c\n", 
             a[0],a[1],a[2],a[3]);
    system("pause");
    return 0;
}
void tongji(char str[],char a[])
{
    // 统计该行文本中字母、数字、空格、其他字符的个数
        for (int i=0; i<100 && str[i]!='\0'; ++i)
        {
            if (str[i]>='A'&& str[i]<='Z' || str[i]>='a' && str[i]<='z')   // 字母
                a[0]++;
            else if (str[i]>='0' && str[i]<='9')  // 数字
                a[1]++;
            else if (str[i]==' ')  // 空格
                a[2]++;
            else
                a[3]++;   // 其他字符
        }
}
