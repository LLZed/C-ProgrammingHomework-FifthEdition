//分析程序：用下面的scanf 函数输人数据,使a=3,b=7,x=8.5,y=71. 82,cl=‘A’,c2=‘a’。在键盘上应如何输入?
#include<stdio.h>
#include <stdlib.h>
int main()
{
	int a, b;
	float x, y;
	char c1, c2;
	scanf("a=%db=%d", &a, &b);
	scanf("%f%e",&x, &y);
	scanf("%c%c",&c1, &c2);
    system("pause");
	return 0;
}
