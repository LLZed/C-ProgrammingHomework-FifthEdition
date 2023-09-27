//写一个函数,使给定的一个3X3的二维整型数组转置,即行列互换。
#include <stdio.h>
#include <stdlib.h>
#define M 3
#define N 3
int main()
{
    void ReverseArray(int array[M][N]);//声明函数
    int array[M][N];//定义一个整型数组
    printf("请输入一个3*3的数组:\n");
    for(int i=0;i<M;++i)
    {for(int j=0;j<N;++j)
        scanf("%d",&array[i][j]);
    }
//输出转置前的数组
    printf("转置前的数组为:\n");
    for(int i=0; i<M; ++i)
	{
		for(int j=0; j<N; ++j)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
    printf("\n");
    ReverseArray(array);//调用函数
//输出转置后的数组
    printf("转置后的数组为:\n");
    for(int i=0; i<M; ++i)
	{
		for(int j=0; j<N; ++j)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
system("pause");
return 0;
}
//实现转置的函数
void ReverseArray(int array[M][N])
{
    int tmp;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(i!=j)
            {
                tmp=array[i][j];
                array[i][j]=array[j][i];
                array[j][i]=tmp;
            }
        }
    }


}