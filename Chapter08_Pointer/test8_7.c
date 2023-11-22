//有一个字符串包含n个字符，写一个函数，将此字符中从第m个字符开始的全部字符复制到另一个字符串。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int m,n;
    char str1[50],str2[50];
    void copystr(char *p1,char *p2,int m);
    printf("input the str1:");
    gets(str1);
    n=strlen(str1);
    printf("which character that begin to copy?\n");
    scanf("%d",&m);
    //检测输入的位置是否合法
    if(n<m)
        printf("input error!\n");
    else
    {
        copystr(str1,str2,m);
        printf("%s\n",str2);
    }
    system("pause");
    return 0;    
}
void copystr(char *p1,char *p2,int m)
{
    int i=0;
    while(*(p1+m+i-1)!='\0')// 从第m个位置开始复制新数据
    {
        *(p2+i)=*(p1+m+i-1);
        i++;
    }
    p2[i] = '\0';//不要忘了字符串结尾标志
}