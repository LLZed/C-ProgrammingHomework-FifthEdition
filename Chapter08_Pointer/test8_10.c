/*
10. 将一个5x5的矩阵中最大的元素放在中心,4个角分别放4个最小的元素(顺序为从左到右,从上到下依次从小到大存放),写一函数实现之。用main函数调用。
解题思路： 将二维数组当做一维数组进行处理比较方便，而二维数组本身就是扁平化存储，所以直接使用首地址即可。
先遍历找到最大值，将其与中间数字交换，而中间数字的下标就是数字总数除以2；
其次寻找四次最小值，每次寻找的时候将最小值的下标记录起来，前提是这个数字如果已经是选中的最小数字之一，则需要跳过，也就是只跟剩余的数字作比较。
（第二次开始遍历找最小数字的时候，千万不能与第一个最小数进行比较，否则永远都只有一个最小数）。

*/

#include <stdio.h>
#include <stdlib.h>

//
#define N 5
 int main()
 {
    void fun(int *arry);
	int a[N][N],*arry;    //定义整型二维数组存放矩阵
	printf("Please enter a %d x %d matrix: \n",N,N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
		} 
	}
    printf("initial matrix:\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%d\t",a[i][j]); 
        printf("\n");
    }
    arry=&a[0][0];      //二维数组转成一维数组来处理
	fun(arry);
    printf("----------------------------");
    printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
 }
 //转置函数
 void fun (int *arry){
    int *max,*min,tmp;
    max=arry;
    min=arry;
    //先找出最大的
	for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++){
            if(*max<*(arry+N*i+j))
                max=arry+N*i+j;  //找出最大值的地址并赋给max
            if(*min>*(arry+N*i+j))
                min=arry+N*i+j; //找出最小值的地址并赋给min
        }       
    //将最大值交换给中心位置
    tmp=*(arry+12); 
    *(arry+12)=*max;
    *max=tmp;  
    //将最小值交换给左上角位置
    tmp=*arry; 
    *arry=*min;
    *min=tmp; 
 
    //找第二小的元素并和右上角元素交换位置
    min=arry+1; //最小值指针指向第二个元素
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if(((arry+N*i+j)!=arry) && (*min>*(arry+N*i+j)))
                min=arry+N*i+j;
    tmp=*min;
    *min=*(arry+4);
    *(arry+4)=tmp;
    //找第三小的元素并和右上角元素交换位置
    min=arry+1; //最小值指针指向第二个元素
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if(((arry+N*i+j)!=arry+4) && ((arry+N*i+j)!=arry) && (*min>*(arry+N*i+j)))
                min=arry+N*i+j;
    tmp=*min;
    *min=*(arry+20);
    *(arry+20)=tmp;
    //找第四小的元素并和右上角元素交换位置
    min=arry+1; //最小值指针指向第二个元素
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if(((arry+N*i+j)!=arry+20) && ((arry+N*i+j)!=arry+4) && ((arry+N*i+j)!=arry) && (*min>*(arry+N*i+j)))
                min=arry+N*i+j;
    tmp=*min;
    *min=*(arry+24);
    *(arry+24)=tmp; 
} 


