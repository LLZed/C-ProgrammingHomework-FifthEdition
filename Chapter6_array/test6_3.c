//求一个3 X 3的整形矩阵对角线元素之和
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int array[3][3];
    int sum1=0,sum2=0,sum;
    //输入一个矩阵，按行输入的，所以输入时一个个数字输入就行
    printf("输入3*3整数矩阵:\n");
    for(int i=0;i<3;i++)
    {for(int j=0;j<3;j++)
    {
        scanf("%d",&array[i][j]);
    }
    }
    //显示输入的矩阵
    printf("输入的矩阵为: \n");
    for(int i=0;i<3;i++)
    {for(int j=0;j<3;j++)
    {
        printf("%d ",array[i][j]);
        if(j!=0 && j/2==1)
        printf("\n");
    }
    }
    //计算元素和
    for(int i=0;i < 3;i++)//左上角到右下角对角线元素行坐标列坐标相等
    {
        sum1+=array[i][i];
    }
    printf("左上角到右下角对角线元素之和:%d \n",sum1);
    for (int j=2,i=0;i<3; i++,j--)//右上角到左下角对角线元素行坐标递增列坐标递减
    {
        sum2+=array[i][j];
    }
    printf("右上角到左下角对角线元素之和:%d \n",sum2);
    sum=sum1+sum2;
    printf("矩阵对角线元素之和:%d \n",sum);
    system("pause");
return 0;
}