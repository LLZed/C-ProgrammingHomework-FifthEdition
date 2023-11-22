/*输出"奇魔方阵"。所谓魔方阵是指这样的方阵，它的每一行、每一列和对角线之和均相等。例如：
8   1   6
3   5   7
4   9   2
要求输出1~n^2的自然数构成的魔方阵。这里讨论的是奇魔方阵！！！！
魔方阵的生成方法为：在第0行中间置1，对从2开始的其余n^2-1个数依次按下列规则存放：
1.将1放在第1行的中间一列。
2.从2开始直到n*n，各数依次按此规律存放：每一个数存放的行比前一个数的行数减1，列数加1。
3.如果上一行的行数为1，则下一个数的行数为n(指最下一行）。
4.当上一个数的列数为n时，下一个数的列数应该为1。
5.如果按上面规律确定的位置有数，或者上一个数是第1行第n列时，则把下一个数放在上一个数的下面。
*/
#include <stdio.h>
#include <stdlib.h>
void main()
{
    int array[100][100];
    int n,i,j;
    int col=0,row=0;
    int preRow=0,preCol=0;//前一个元素所在行与列
    while(1)
    {
    printf("输入魔方阵的阶数n(n=3~100内的奇数): ");
    scanf("%d",&n);
    if(n%2!=0 && (n>=3 && n<100))
    {
        break;
    }
    }

    for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
			array[i][j] = 0;
	}
    //放置1在第0行最中间的位置
    col=n/2;
    array[0][col]=1;

    //对于n^2-1个元素
    for(i=2;i<=n*n;i++)
    {
        //对其他元素，下一个元素存在当前元素的上一行下一列
        row--;
        col++;
        if(row<0)
        {
            row=n-1;
        }
        if(col>=n)
        {
            col=0;
        }
        if(array[row][col]!=0)
        {
            //该位置已经有元素了，就放到上一个放的元素的下一行，所以在存放每个元素时应纪录上一个的位置
                row=preRow+1;
                col=preCol;
        }
        array[row][col]=i;
        preRow=row;
        preCol=col;
    }
    printf("奇魔方阵为:\n");
	for (i = 0; i <n; ++i)
    {   for(int j=0;j<n;++j)
	    {
            printf("%4d ", array[i][j]);
        }
        printf("\n");
    }

system("pause");  
}


