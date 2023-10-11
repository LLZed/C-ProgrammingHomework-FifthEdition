//有3个整数a, b, c，由键盘输入，输出其中最大的数。
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a, b, c, max;
	printf("请输入三个数：\n");
	scanf("%d%d%d", &a, &b, &c);
	if (a > b)
	{
		max = a;
	}
	else
	{
		max = b;
	}

	if (c > max)
	{
		max = c;
	}
	printf("三个数中最大的数为：%d\n", max);
    system("pause");
	return 0;
}
/*
//两两比较
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b && a == c) {
        printf("Three numbers are equal\n");
    }else if (a == b && a > c) {
        printf("a and b are the largest number\n", a); 
    }else if (a == c && a > b) {
        printf("a and c are the largest number\n", a); 
    }else if (b == c && b > a) {
        printf("c and b are the largest number\n", a); 
    }else if (a > b && a > c) {
        printf("a=%d is the largest number\n", a); 
    }else if (b > a && b > c) {
        printf("b=%d is the largest number\n", b); 
    }else {
        printf("c=%d is the largest number\n", c); 
    }
	system("pause");//这一句是为了让控制台不退出
    return 0;
}
*/