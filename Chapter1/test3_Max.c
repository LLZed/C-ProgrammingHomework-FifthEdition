//编写一个C程序,运行时输人a,b,c三个值,输出其中值最大者。

#include<stdio.h>
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
