//单偶魔方阵
/*单偶： 阶数n = 4 * m + 2（m =1，2，3……）的魔方规律如下：
将魔方分成A、B、C、D四个k阶方阵，这四个方阵都为奇方阵，利用上面讲到的方法依次将A、D、B、C填充为奇魔方。
交换A、C魔方元素，对魔方的中间行，交换从中间列向右的m列各对应元素；对其他行，交换从左向右m列各对应元素。
交换B、D魔方元素，交换从中间列向左m – 1列各对应元素。*/
# include<stdio.h>
#define N 6
void MagicSquare()
{
#define ROW N
#define COL ROW
    int arr[ROW][COL] = {0};//将数组全部置为0
    int temp;
    int k;
	int a;
    int currow;
	int curcol;
	k=N/2;
	curcol=(k-1)/2;
	currow=0;
	arr[currow][curcol]=1;
	//生成魔方阵A 
	for(a=2;a<k*k;a++)
	{
		if((a-1)%k==0)//前一个数是3的倍数
		{
			currow++;
		}
		else
		{
            currow--;
            currow = (currow+k)%k;
            curcol ++;
            curcol %= k;
		}
		arr[currow][curcol]=a;
	}
	//根据A生产B、C、D魔方 
	for(currow = 0;currow < k; currow++)
    {
        for(curcol = 0;curcol < k; curcol++)
        {
            arr[currow+k][curcol+k] = arr[currow][curcol] + k*k;
            arr[currow][curcol+k] = arr[currow][curcol] + 2*k*k;
            arr[currow+k][curcol] = arr[currow][curcol] + 3*k*k;
        }
    }
    for(currow = 0;currow < k;currow++)
    {
        if(currow == k / 2)
        {
            for(curcol = k / 2; curcol < k - 1; curcol++)
            {
                temp = arr[currow][curcol];
                arr[currow][curcol] = arr[currow + k][curcol];
                arr[currow + k][curcol] = temp;
            }
        }
        else
        {
            for(curcol = 0;curcol < k / 2;curcol++)
            {
                temp = arr[currow][curcol];
                arr[currow][curcol] = arr[currow + k][curcol];
                arr[currow + k][curcol] = temp;
            }
        }  
    }
    for(currow = 0; currow < k;currow++)
    {
        for(a = 0;a < (k - 1)/2 - 1;a++)
        {
            temp = arr[currow][k+ k/2 - a];
            arr[currow][k+ k /2 -a] = arr[currow + k][k+k/2 -a];
            arr[currow + k][k+k/2 -a] = temp;
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
int main()
{
	MagicSquare();
	return 0;
 }
/*————————————————
版权声明：本文为CSDN博主「cyy_0802」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/cyy_0802/article/details/80151813