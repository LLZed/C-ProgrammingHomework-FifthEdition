/*17.
写一函数，实现两个字符串的比较。即自己写一个strcmp函数,函数原型为int strcmp(char * p1 ,char * p2); 
设p1指向字符串s1, p2指向字符串s2。要求当s1=s2时,返回值为0;若s1≠s2,返回它们二者第1个不同字符的ASCII码差值.
如"BOY"与"BAD" ,第2个字母不同,0与A之差为79- 65=14。
如果s1>s2,则输出正值;如果s1<s2,则输出负值。
解题思路： 使用两个指针指向两个字符串首部，逐个往后进行比较，不相等的时候则将数据进行相减，作为返回值。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
int main(){
    char str1[N],str2[N];
    int x;//存放两字符比较的结果
    int STRcmp(char *p1,char *p2);//函数声明，函数形参是两个字符型指针变量
    printf("enter string1:\n");
    gets(str1);//输入字符串1
    printf("enter string2:\n");
    gets(str2);//输入字符串2
    printf("string1:%s\nstring1:%s\n",str1,str2);//输出两个字符串
    x=STRcmp(str1,str2);//调用函数进行比较
    printf("results:%d\n",x);//输出两个字符串
    system("pause");
    return 0;
}
int STRcmp(char *p1,char *p2){
    int x;
    while(*p1 != '\0' && *p2 != '\0'){
        if(*p1 != *p2){
            x=*p1-*p2;
            break;
        }
        p1++;
        p2++;
    }
    //注意一个字符串到达结尾或者两个都到达结尾的情况
    if (*p1 == '\0' || *p2 == '\0') {
		x= *p1 - *p2;
	}
    return x;
}