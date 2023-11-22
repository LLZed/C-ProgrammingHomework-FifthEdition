/*
购房从银行贷了一笔款d,准备每月还款额为p,月利率为r,计算多少月能还清。设d为300 000元,p为6000元,r为1%。
对求得的月份取小数点后一位,对第2位按四舍五人处理。
*/
#include<stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	float d = 300000, p = 6000, r = 0.01, m;
	m = log10(p / (p - d*r)) / log10(1 + r);
	printf("m = %3.1f\n", m);
	system("pause");
    return 0;
}
