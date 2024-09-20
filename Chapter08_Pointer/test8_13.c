/* 写一个用矩形法求定积分的通用函数,分别求∫(0,1) sinx dx , ∫(0,1) cosx dx , ∫(0,1) e^x dx ,
说明: sin,cos,exp 函数已在系统的数学函数库中，程序开头要用#include <math. h>。
解题思路：
矩形法，学过高等数学就知道化曲为直的思想。将定积分化为多个函数连续的和。基本思想是将区间[a，b]化成n等分，
当n越大的时候结果越准确。图形化成一小块一小块的矩形。底边长都为(b-a)/n.高为每个等分点的函数值。然后将每个矩形的面积相加即为所求。
因为被分成n等分，就可以认为每一等分是一个矩形，那么每一矩形的面积为： 每一个矩形面积为：
Sn=f(x)(b-a)/n ；
总面积为：S=S1+S2+…+Sn；具体计算过程根据公式套即可

这里主要在于函数指针的应用，将函数作为参数传递给另一个函数，在另一个函数中进行调用的方式向外提供统一接口,
而接口内的处理方式随着传入的函数而不同。
*/
#include<stdio.h>
#include <stdlib.h>
#include<math.h>

double integral(double(*handler)(double), double a, double b, int n)
{
	double i,s = 0;
	double h = (b - a) / n;
	for (i = a; i <= b; i += h){
		s += handler(i) * h;
	}
	return s;
}
int main()
{
	double a, b;
	int n = 200000; // 区间划分个数
	int func_idx; // 计算函数选择id
	printf("Please enter the lower and upper limit of integration:\n");
	scanf("%lf %lf", &a, &b);
	printf("Please enter specific calculation function(1-sin/2-cos/3-exp): \n");
	scanf("%d", &func_idx);
	switch (func_idx) {
		case 1:printf("The integral of sin(x) is:%lf\n", integral(sin, a, b, n)); break;
		case 2:printf("The integral of cos(x) is:%lf\n", integral(cos, a, b, n)); break;
		case 3:printf("The integral of exp(x) is:%lf\n", integral(exp, a, b, n)); break;
		default:
			printf("function id error\n");
			return -1;
	}
	system("pause");
	return 0;
}

/*
//法二
int main(){
	float integral(float (*)(float),float,float, int);		//integral函数声明
	float fsin(float);		//对fsin函数声明
	float fcos(float);		//对fcos函数声明
	float fexp(float);		//对fexp函数声明
	float a1,b1,a2,b2,a3,b3,c,(*p)(float);
	int n=20;		// 区间划分个数
	printf("input a1,b1:");		//输入求sin（x）定积分的下限和上限
	scanf("%f,%f",&a1,&b1);
	printf("input a2,b2:");		//输入求cos（x）定积分的下限和上限
	scanf("%f,%f",&a2,&b2);
	printf("input a3,b3:");		//输入求exp（x）定积分的下限和上限
	scanf("%f,%f",&a3,&b3);
	p=fsin;			//使p指向fsin函数
	c=integral(p,a1,b1,n);	//求出sin(x)的定积分
	printf("The integral of sin(x) is:%f\n",c);
	p=fcos;			//使p指向fcos函数
	c=integral(p,a2,b2,n);	//求出cos(x)的定积分
	printf("The integral of cos(x) is:%f\n",c);
	p=fexp;			//使p指向fexp函数
	c=integral(p,a3,b3,n);	//求出exp(x)的定积分
	printf("The integral of exp(x) is:%f\n",c);
	system("pause");
	return 0;
}
//下面是矩形法求定积分函数
float integral(float (*p)(float ),float a,float b, int n){
	int i;
	float x,h,s=0;
	x=a;
	for(i=1;i<=n;i++)
	{
		x=x+h;
		s=s+(*p)(x)*h;
	}
	return s;
}
float fsin(float x){
	return sin(x);
}
float fcos(float x){
	return cos(x);
}
float fexp(float x){
	return exp(x);
}
*/
