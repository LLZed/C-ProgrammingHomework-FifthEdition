/*
用公式π/4=1-(1/3)+(1/5)-(1/7)...求π的近似值，直到发现某一项的绝对值小于10^(-6)为止（该项不累加）
并分别统计当“fabs(t)>= le- 6”和“fabs(t)> = le- 8”时执行循环体的次数。
*/
# include <stdio.h>
#include <stdlib.h>
# include <math.h>

int main()
{
	int sign = 1;
	double pi = 0.0, term = 1.0;
	int n1 = 0,n2=0;

	while (fabs(term) >= 1e-6)
	{
		n1++;
		term = 1.0 / (2 * n1 - 1)*sign;
		pi += term;
		sign = -sign;
	}
	pi *= 4;
	printf("pi的近似值是 %lf\n", pi);
	printf("循环体循环了 %d 次\n", n1);
    
    sign = 1;pi = 0.0; term = 1.0;
    while (fabs(term) >= 1e-8)
	{
		n2++;
		term = 1.0 / (2 * n2 - 1)*sign;
		pi += term;
		sign = -sign;
	}
	pi *= 4;
	printf("pi的近似值是 %lf \n", pi);
	printf("循环体循环了 %d 次\n", n2);
    system("pause");
	return 0;
}
	

