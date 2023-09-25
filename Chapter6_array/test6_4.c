//有一个已经排好序的数组，要求输入一个数后，按原来顺序的规律将它插入数组中
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int array[10]={1,2,3,4,5,6,7,8,9};
    int num;	
    printf("原数组序列为:\n");
	for (int i = 0; i < 9; i++)
	printf("%d ", array[i]);
	printf("\n");
    printf("输入一个数:\n");
    scanf("%d",&num);
    int i=8;
    while (num<=array[i])
    {
            array[i+1]=array[i];
            array[i]=num;
            i--;
    }
    printf("插入排列后为: \n");
    for(int i=0;i<10;i++)
    {
        printf("%d ",array[i]);
    }
system("pause");
return 0;
}

