//输出一下的杨辉三角(要求输出10行)
/*
1                          a[0][0]=1    
1   1                      a[1][0]=1    a[1][1]=1
1   2   1                  a[2][0]=1    a[2][1]=2   a[2][2]=1
1   3   3   1              a[3][0]=1    a[3][1]=3   a[3][2]=3   a[3][3]=1
1   4   6   4   1          a[4][0]=1    a[4][1]=4   a[4][2]=6   a[4][3]=4   a[4][4]=1
1   5  10  10   5   1
……
*/
#include <stdio.h>
#include "stdlib.h"
void main()
{
    int array[10][10];
    for(int i = 0; i < 10; i++)
    {
        for(int j=0;j<=i;j++)
        {
            // 对角线和第0列上全部为1
            if(i==j || j==0)
            array[i][j]=1;
            else
            array[i][j]=array[i-1][j-1]+array[i-1][j];
        }
    }
    printf("10行杨辉三角为:\n");
	for (int i = 0; i < 10; i++)
    {   for(int j=0;j<=i;j++)
	    {
            printf("%5d ", array[i][j]);
            if(j==i)
            printf("\n");
        }
    }
    printf("\n");
system("pause");
}