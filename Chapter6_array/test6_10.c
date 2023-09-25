//有一篇文章，共有3行文字，每行有80个字符。要求分别统计出其中英文大写字母、小写字母、数字、空格以及其他字符的个数。
/*获取文章中的3行文本，并对每行文本进行以下操作:
    定义保存结果变量：A、a、digit、space、other
    遍历每行文本中的字符
    如果该字符ch：ch >= ‘a’ && ch <=‘z’，则该字符是小写字母，给low++
    如果该字符ch：ch >= ‘A’ && ch <=‘Z’，则该字符是小写字母，给up++
    如果该字符ch：ch >= ‘0’ && ch <=‘9’，则该字符是小写字母，给digit++
    如果该字符ch：ch == ’ '，则该字符是小写字母，给space++
    否则为其他字符，给other++
输入统计结果*/
#include <stdio.h>
#include "stdlib.h"
#define M 3
#define N 80
int main()
{
    char array[M][N];
    int A=0,a=0,digit=0,space=0,other=0;
    printf("输入三行文本,每行不超过80个字符:\n");
    int i;
    for(i=0;i<M;i++)
    {
            for(int j=0;j<N;j++)
        {
            scanf("%c",&array[i][j]);
            if(array[i][j]=='\n')
            break;
        }
    }

    // for (int i=0; i<3; i++)
    // {
    //     // 获取一行文本
    //     printf("please input line %d:\n",i+1);
    //     gets(array[i]);
    // }

    //统计文本中小写字母、大写字母、数字、空格、其他字符的个数    
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N&&array[i][j]!='\0'&&array[i][j]!='\n';j++)
        {
            if(array[i][j]>='A'&& array[i][j]<='Z')
                A++;// 统计大写字母个数
            else if(array[i][j]>='a'&& array[i][j]<='z')
                a++;// 统计小写字母个数
            else if(array[i][j]>='0'&& array[i][j]<='9')
                digit++;// 统计数字个数
            else if(array[i][j]==' ')
                space++;// 统计空格个数
            else
                other++;// 统计其它字符个数
        }

    }
    printf("大写字母个数: %d\n", A);
    printf("小写字母个数: %d\n", a);
    printf("数字个数: %d\n", digit);
    printf("空格个数: %d\n", space);
    printf("其他字符个数: %d\n", other);

system("pause");
return 0;
}
