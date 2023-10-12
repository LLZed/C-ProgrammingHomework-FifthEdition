/*
有一个函数表示y在不同x取值范围下的值： 
−1   (x<0)
 0   (x=0)
 1   (x>0)
​编写程序实现题目要求。
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x, y;
    printf("enter x:");
    scanf("%d", &x);
    y=0;
    if (x >= 0)
		if (x > 0) 
            y=1;
    	else 
            y=0;
    else
        y=-1;
    printf("x=%d,y=%d\n", x, y);
    system("pause");
    return 0;
}
