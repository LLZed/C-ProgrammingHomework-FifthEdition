/*
编程序,用getchar函数读人两个字符给c1和c2，然后分别用putchar函数和printf函数输出这两个字符。思考以下问题:
(1) 变量cl和c2应定义为字符型、整型还是二者皆可?
(2) 要求输出cl和c2值的ASCII码,应如何处理?用putchar函数还是printf函数?
(3) 整型变量与字符变量是否在任何情况下都可以互相代替?如:
char c1,c2; 与 int cl,c2;
是否无条件地等价?
*/
#include<stdio.h>
#include <stdlib.h>
int main()
{
	int c1, c2;
	printf("请输入两个字符c1,c2:");
	c1 = getchar();
	c2 = getchar();
	printf("用putchar语句输出结果为:");
	putchar(c1);
	putchar(c2);
	printf("\n");
	printf("用printf语句输出结果为:");
	printf("%c %c\n", c1, c2);
        system("pause");
	return 0;
}
/*
(1) 变量cl和c2应定义为字符型、整型还是二者皆可?
答：c1和c2 应定义为整形，因为定义为字符有可能返回的整数会超出字符的存储范围
(2) 要求输出cl和c2值的ASCII码,应如何处理?用putchar函数还是printf函数?
答：需要使用printf函数，打印是以整形形式打印
(3) 整型变量与字符变量是否在任何情况下都可以互相代替
答：不是，因为两者的存储范围不同，如果整数超出了字符的存储范围，则不能相互替换
*/