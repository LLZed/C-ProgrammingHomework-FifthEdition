//找出一个二维数组中的鞍点，即该位置上的元素在该行上最大，在该列上最小，也可能没有鞍点。
#include <stdio.h>
#include "stdlib.h"
#define M 3
#define N 3
void main()
{
    int i,j,max,min,row,col,flag=0;
    int array[M][N];
    printf("输入%d行%d列的数组:\n",M,N);
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        scanf("%d",&array[i][j]);
    }

    for(i=0;i<M;i++)
    {
        max=array[i][0];
        for(j=0;j<N;j++)
        {
            if(array[i][j]>max)
            {   
                max=array[i][j];
                col=j;
            }
        }
        min=array[0][col];
        for (int k=0;  k< M; k++)
        {
            if(array[k][col]<min)
            {
                min=array[k][col];
                row=k;
            }
        }
        if(max==min && i==row)
        {
			flag = 1;//标记，用来判断是否输出有鞍点
			printf("鞍点为：%d行%d列的元素%d\n", row, col, max);
			break;
		}
        else
        
    }
    if(flag==0)
    printf("没有鞍点\n");
system("pause");
}