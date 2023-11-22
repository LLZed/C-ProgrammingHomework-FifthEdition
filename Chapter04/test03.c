/*
写出下面各逻辑表达式的值。设a=3,b=4,c=5。
（1）a + b > c && b == c
（2）a || b + c && b - c
（3）!(a > b) && !c || 1
（4）!(x = a) && (y = b) && 0
（5）!(a + b) + c - 1 && b + c / 2

解题思路：
关系运算符的优先级高于赋值运算符，但是低于算术运算符.
&&表示两边条件同为真则成立，||表示两边条件任意一个为真则成立，!取条件反义。
逻辑运算符优先级： ! > && > ||
有括号优先括号。
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a = 3, b = 4, c = 5,x,y;
    printf("%d\n", a + b > c && b == c);
	printf("%d\n", a || b + c && b - c);
    printf("%d\n", !(a > b) && !c || 1);
    printf("%d\n", !(x = a) && (y = b) && 0);
    printf("%d\n", !(a + b) + c - 1 && b + c / 2);
	system("pause");//这一句是为了让控制台不退出
	return 0;
}
