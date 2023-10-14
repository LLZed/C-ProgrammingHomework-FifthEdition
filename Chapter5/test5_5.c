/*
Sn=a+aa+aaa+…+ a⋯a(n 个 a) 的值
其中a是一个数字，n表示a的位数，n由键盘输入。例如:2+22+222+2222+22222 (此时n=5)
答案解析：
该题目可以将数字拆分为 a * 10^n + 前一个数字，例如:
2 = 2 * 10^0 + 0 : 默认2的前一个数字为0，也就是没有任何值
22 = 2 * 10^1 + 2 ： 22的前一个数字为2
222 = 2*10^2 + 22 ：222的前一个数字为22

以此类推…

所以，在每次循环的时候，需要保存下，上一次结果的值，方便下一次计算
还需要使用到C库当中使用的pow函数，来计算某个数的n次方，我们在该题目当中使用的是10的n次方，n随着循环的次数，以此递增。
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	//n为a的个数
	int n;
	double a, prev_sum = 0.0, total_sum = 0.0;
	printf("请输入a的值以及n的值: ");
	scanf("%lf %d", &a, &n);
	//循环n次求总和
	for (int i = 0; i < n; i++)
	{
		prev_sum += a * pow(10, i); 
		total_sum += prev_sum;
	}
	printf("总和为：%lf\n", total_sum);
    system("pause");
	return 0;
}
