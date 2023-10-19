//用选择法排序10个整数
/*每一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置;
  然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾;
  以此类推，直到全部待排序的数据元素排完。*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    int array[10];
    //int size = sizeof(array) / sizeof(array[0]);//也通过总字节,除以数组中的任意的一个元素的字节,来达到求一个数组中有多少元素的目的
    printf("输入十个整数:\n");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&array[i]);
    }
    // 输出原数组
	printf("排序前数组中数据为：\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", array[i]);
	printf("\n");

    for (int i = 0; i < 9; i++)
    {
        // 用max标记[0, 10-1)区间中最大元素
		// 在该趟选择没有开始前，默认认为0号位置就是最大元素
        int maxPos=0;
        for(int j=1;j<10-i;j++)
        {
        if(array[j]>array[maxPos])
            maxPos=j;// 遍历区间[0, size-i)中元素，如果有元素比max位置元素大，max记录该元素位置
        }

        // 如果最大元素不在区间末尾时，将最大元素与区间末尾元素交换
		if (maxPos != 10-i-1)
		{
			int temp = array[maxPos];
			array[maxPos] = array[10-i-1];
			array[10-i-1] = temp;
		}
    } 

    // 输出原数组
	printf("选择排序后数组中数据为：\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", array[i]);
	printf("\n");
    system("pause");
    return 0;
}
