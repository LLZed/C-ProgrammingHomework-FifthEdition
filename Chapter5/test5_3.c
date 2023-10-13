/*
输人两个正整数m和n,求其最大公约数和最小公倍数.
答案解析：
该题题目直接使用“辗转相除法”来求解最大公约数:
以除数和余数反复做除法运算，当余数为 0 时，就取得当前算式除数为最大公约数。

最大公约数和最小公倍数之间的性质：两个自然数的乘积等于这两个自然数的最大公约数和最小公倍数的乘积。
所以，当我们求出最大公约数，就可以很轻松的求出最小公倍数。
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int  p, r, n, m, temp;
	printf("请输入两个正整数n,m:");
	scanf("%d%d,", &n, &m);
	//调整n保存较大的值
	if (n < m)
	{
		temp = n;
		n = m;
		m = temp;
	}

	p = n * m;
	while (m != 0)
	{
		r = n % m;
		n = m;
		m = r;
	}
	printf("它们的最大公约数为:%d\n", n);
	printf("它们的最小公倍数为:%d\n", p / n);
    system("pause");
	return 0;
}
