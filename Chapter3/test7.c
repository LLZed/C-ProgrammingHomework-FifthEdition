/*
设圆半径r=1.5,圆柱高h=3,求圆周长、圆面积、圆球表面积、圆球体积、圆柱体积。
用scanf输人数据，输出计算结果，输出时要求有文字说明,取小数点后2位数字。请编程序。
*/
#include<stdio.h>
#include <stdlib.h>
int main()
{
	float h, r, l, s, sq, vq, vz;
	float pi = 3.141526;
	printf("请输入圆半径r，圆柱高h∶");
	scanf("%f %f", &r, &h);               //要求输入圆半径r和圆柱高h 
	l = 2 * pi*r;                          //计算圆周长l
	s = r*r*pi;                          //计算圆面积s
	sq = 4 * pi*r*r;                       //计算圆球表面积sq
	vq = 3.0 / 4.0*pi*r*r*r;               //计算圆球体积vq
	vz = pi*r*r*h;                       //计算圆柱体积vz
	printf("圆周长为:       l=%6.2f\n", l);
	printf("圆面积为:       s=%6.2f\n", s);
	printf("圆球表面积为:   sq=%6.2f\n", sq);
	printf("圆球体积为:     v=%6.2f\n", vq);
	printf("圆柱体积为:     vz=%6.2f\n", vz);
    system("pause");
	return 0;
}

