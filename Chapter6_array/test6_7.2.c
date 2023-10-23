//双偶魔方阵
/*双偶：阶数n = 4 * m（m =1，2，3……）的偶魔方的规律如下：

按数字从小到大，即1，2，3……n2顺序对魔方阵从左到右，从上到下进行填充；
将魔方中间n/2列的元素上、下进行翻转；
将魔方中间n/2行的元素左、右进行翻转。*/
# include<stdio.h>
#define N 4
void MagicSquare()
{
#define ROW N
#define COL ROW
	int a = 1;
	int temp; 
	int arr[ROW][COL] = {0};
	int currow;
	int curcol;
	for(currow=0;currow<N;currow++)//魔方阵填充
	{
		for(curcol=0;curcol<N;curcol++)
		{
			arr[currow][curcol]=a; 
			a++;
		} 
	} 
	for(currow=0;currow<N/2;currow++)//翻转中间列
	{
		for(curcol=N/4;curcol<N/4*3;curcol++)
		{
			temp = arr[currow][curcol];
            arr[currow][curcol] = arr[N-currow-1][curcol];
		    arr[N-currow-1][curcol] = temp;
		}
	}
	for(curcol=0;curcol<N/2;curcol++)//翻转中间行
	{
		for(currow=N/4;currow<N/4*3;currow++)
		{
			temp = arr[currow][curcol];
			arr[currow][curcol] = arr[N-currow-1][curcol];
			arr[N-currow-1][curcol] = temp;
		}
	}
	for(int i=0;i<ROW;i++)
	{
		for(int j=0;j<COL;j++)
		{
			printf("%-2d ",arr[i][j]);
		}
		printf("\n");
	}
}

/*版权声明：本文为CSDN博主「cyy_0802」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/cyy_0802/article/details/80151813