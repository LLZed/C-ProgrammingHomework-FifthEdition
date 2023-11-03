/*
10. 将一个5x5的矩阵中最大的元素放在中心,4个角分别放4个最小的元素(顺序为从左到右,从上到下依次从小到大存放),写一函数实现之。用main函数调用。
解题思路： 将二维数组当做一维数组进行处理比较方便，而二维数组本身就是扁平化存储，所以直接使用首地址即可。
先遍历找到最大值，将其与中间数字交换，而中间数字的下标就是数字总数除以2；
其次寻找四次最小值，每次寻找的时候将最小值的下标记录起来，前提是这个数字如果已经是选中的最小数字之一，则需要跳过，也就是只跟剩余的数字作比较。
（第二次开始遍历找最小数字的时候，千万不能与第一个最小数进行比较，否则永远都只有一个最小数）。

*/

#include <stdio.h>
#include <stdlib.h>

//解法一
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
/*
//解法二
#define N 5
int main()
{
    void transform(int *arry, int col_row); //函数声明，函数参数是一个整型指针和一个整型变量
	int arry[5][5];   //定义一个二维数组存放矩阵
//输入矩阵并输出初始未改变的矩阵
	printf("Please enter a %d x %d matrix: \n",N,N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arry[i][j]);
		} 
	}
    printf("initial matrix:\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%d\t",arry[i][j]); 
        printf("\n");
    }

	transform(*arry, 5);  //调用函数，将二维数组当做一维数组传入处理，此时形参arry指向二维数组arry[N][N]的第一行的地址，即arry[0]的地址，并且传入行列数
//输出改变后的矩阵
	printf("----------------------------");
    printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d\t", arry[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
void transform(int *arry, int col_row)   //形参arry指向二维数组arry[N][N]的第一行的地址，即arry[0]的地址
{
    //找到最大值
	int max = arry[0], max_idx;  //因为arry指向的是实参arry[0]的地址，所以这里arry[0]等价于arry[0][0]
	for (int i = 0; i < col_row * col_row; i++) {
		if (max < arry[i]) 
            max = arry[i];//找出最大数
		max_idx = i;   //存放最大的数的位置
	}
	//行列相乘得到总数量，除以2后加1则为中心点（暂时不考虑偶数的情况）
	int center_idx = (col_row * col_row) / 2;
	int tmp = arry[center_idx]; arry[center_idx] = arry[max_idx]; arry[max_idx] = tmp;//把最大的数和中心位置的数互换

	//找到四个最小值
	int min_idx[4];//用于存放四个最小值的位置
    //循环4次获取到4个最小值
	for (int i = 0; i < 4; i++) {
		int min_tmp = arry[col_row * col_row - 1];  //用于存放当前找到的最小值
        //遍历所有数据，逐个比较获取最小值   
		for (int j = 0; j < col_row * col_row; j++) {
			int k = 0;
            //检查当前最小值是不是已经找到过了，如果某个下标的数据已经是获取过的最小值,则不能进行判断（因为这个肯定是最小的）
			for (; k < i; k++) {
				if (j == min_idx[k]) 
                    break;
			}
            //k和i不同表示j这个坐标已经是找到的最小的几个数字之一，则找下一个判断
			if (k != i) { 
                continue;
            }
            // 相当于在剩下的数中找到最小的那个数字 
			if (min_tmp > arry[j]) {  
				min_tmp = arry[j];
				min_idx[i] = j; //并且记录这个数字的位置
			}
		}
	}
    //先计算四个角的下标，便于后边进行交换
    int change_idx[4];
	change_idx[0] = 0;                      //第一个要置换的数据的下标，也就是左上角
	change_idx[1] = col_row - 1;            //第二个要置换的数据的下标，也就是右上角
	change_idx[2] = col_row * (col_row - 1);//第一个要置换的数据的下标，也就是左下角
	change_idx[3] = (col_row * col_row) - 1;//第一个要置换的数据的下标，也就是右下角
	for (int i = 0; i < 4; i++) {
		int tmp = arry[change_idx[i]]; arry[change_idx[i]] = arry[min_idx[i]]; arry[min_idx[i]] = tmp;  //交换4个最小值
	}
	return 0;
}
*/

