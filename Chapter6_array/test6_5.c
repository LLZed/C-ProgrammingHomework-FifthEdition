// 将一个数组中的值按逆序重新存放。例如：原来顺序为8,6,5,4,1。要求改为1,4,5,6,8。
#include <stdio.h>
#include "stdlib.h"
void main()
{
    int array[5];
    printf("输入要排序的数（空格隔开）:\n");
    for(int i=0;i<5;i++)
    scanf("%d",&array[i]);

    int begin=0,end=4;
    while (begin<end)
    {
        int num=array[begin];
        array[begin]=array[end];
        array[end]=num;
        begin++;
        end--;
    }

    printf("逆序重新存放后的数组序列为:\n");
	for (int i = 0; i < 5; i++)
	printf("%d ", array[i]);
	printf("\n");
system("pause");
}