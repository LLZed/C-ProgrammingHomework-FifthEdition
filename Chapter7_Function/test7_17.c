//用递归法将一个整数n转换成字符串。例如，输入483,应输出字符串”483”。n的位数不确定,可以是任意位数的整数。
#include<stdio.h>
#include<stdlib.h>

void main()
{
	int convert(int n);
    int number;
    printf("input an integer:");
    scanf("%d",&number);
    printf("output:");
    if(number<0)        //考虑到如果输入是负数，先变为正数
    {
        putchar('-');
        putchar(' ');
        number=-number;
    }
    convert(number);
    printf("\n");
    system("pause");
}

int convert(int n)
{
    int i;
    if ((i=n/10)!=0)
    {
        convert(i);
    }
    putchar(n%10+'0');       
    putchar(32);            //输出空格，空格的ASCII码是32
    return 0;
}