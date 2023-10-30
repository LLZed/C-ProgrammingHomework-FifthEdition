//编写一个函数,由实参传来一个字符串,统计此字符串中大写字母、小写字母、数字、空格和其他字符的个数,在主函数中输入字符串以及输出上述的结果。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

int main()
{
    int str_count[5]={0,0,0,0,0};
    char str[N];
    void Count_str(char *p1,int *p2);
    printf("please input line:\n");
    gets(str);
    printf("string: %s\n", str);
    Count_str(str,str_count);
    printf("big letter case: %d\tlittle letter case: %d\tspace case: %d\tdigit case: %d\tother case: %d\t", str_count[0],str_count[1],
                            str_count[2],str_count[3],str_count[4]);
    system("pause");
    return 0;
}
void Count_str(char *p1,int *p2)
{
    int i=0;
    // 统计该行文本中字母、数字、空格、其他字符的个数
        while(*(p1+i)!='\0')
        {
            if (*(p1+i)>='A'&& *(p1+i)<='Z' )
                p2[0]++;
            else if(*(p1+i)>='a' && *(p1+i)<='z')   // 字母
                p2[1]++;
            else if (*(p1+i)==' ')  // 空格
                p2[2]++;
             else if (*(p1+i)>='0' && *(p1+i)<='9')  // 数字
                p2[3]++;
            else
                p2[4]++;  // 其他字符
            i++;
        }
}

