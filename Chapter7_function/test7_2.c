//求方程 ax^2 + bx + c = 0的根,用3个函数分别求当: b^2 − 4ac大于0、等于0和小于0时的根并输出结果。从主函数输入a,b,c的值。
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float x1,x2,disc;//定义的三个全局变量
void greater(float x,float y)  //定义有参函数
{
    x1=(-y+sqrt(disc))/(2*x);
    x2=(-y-sqrt(disc))/(2*x);
}
    
void equal(float x,float y)  //定义有参函数
{
    x1=x2=(-y)/(2*x);
}
//求虚数根
void smaller(float x, float y)  //定义有参函数
{
    x1=(-y+sqrt(-disc))/(2*x);
    x2=(-y-sqrt(-disc))/(2*x);
}
int main()//定义主函数
{
    int a,b,c;  //定义三个动态局部变量
    printf("请输入a b c的值,空格隔开:\n");
    scanf("%d %d %d",&a,&b,&c);
    printf("表达式为: %d*x^2+%d*x+%d = 0\n", a, b, c);
	disc = b*b - 4 * a*c;
    if (disc > 0)
	{
		greater(a, b);//调用函数
		printf("disc>0的根为: x1=%f    x2=%f\n", x1, x2);//调用标准C库函数
	}
	else if (disc == 0)
	{
		equal(a, b);//调用函数
		printf("disc==0的根为:x1=%f    x2=%f\n", x1, x2);//调用标准C库函数
	}
	else if(disc<0)
	{
		smaller(a, b);//调用函数
		printf("disc<0的根为:x1=%fi    x2=%fi\n", x1,x2);//调用标准C库函数
	}
system("pause");
return 0;    
}



// #include<stdio.h>
// #include <stdlib.h>
// #include<math.h>

// //x1为第一个根，x2为第二个根
// float x1, x2, disc, p, q;

// void greater_than_zero(float a, float b)
// {
// 	float m = sqrt(disc);
// 	x1 = (-b + sqrt(disc)) / (2 * a);
// 	x2 = (-b - sqrt(disc)) / (2 * a);
// }

// void equal_to_zero(float a, float b)
// {
// 	x1 = x2 = (-b) / (2 * a);
// }

// void smaller_than_zero(float a, float b)
// {
// 	p = -b / (2 * a);
// 	q = sqrt(-disc) / (2 * a);
// }

// int main()
// {
// 	int a, b, c;
// 	printf("请输入 a b c:");
// 	scanf("%d %d %d", &a, &b, &c);

// 	printf("表达式为: %d*x^2+%d*x+%d = 0\n", a, b, c);
// 	disc = b*b - 4 * a*c;

// 	if (disc > 0)
// 	{
// 		greater_than_zero(a, b);
// 		printf("disc>0的根为: x1=%f    x2=%f\n", x1, x2);
// 	}
// 	else if (disc == 0)
// 	{
// 		equal_to_zero(a, b);
// 		printf("disc==0的根为:x1=%f    x2=%f\n", x1, x2);
// 	}
// 	else
// 	{
// 		smaller_than_zero(a, b);
// 		printf("disc<0的根为:x1=%f+%f x2=%f-%f\n", p, q, p, q);
// 	}
//     system("pause");
// 	return 0;
// }
