/*
假如我国国民生产总值的年增长率为7%， 计算10年后我国国民生产总值与现在相比增长多少百分比。
计算公式为p = ( 1 + r )^n,其中r为年增长率，n为年数，p为与现在相比的倍数。
题目解析:
利用数学库math中pow函数进行计算，若不熟悉可以查阅帮助文档，查看pow函数的用法。
*/
#include<stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	float p, r, n;
	r = 0.07;
	n = 10;
	p = pow(1 + r, n);
	printf("p=%f\n", p);
    system("pause");
	return 0;
}

