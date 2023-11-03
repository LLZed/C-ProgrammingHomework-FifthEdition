//写一个函数转置3*3整型矩阵
//解题思路： 矩阵转置就是行变列，列变行，说白了就是 arry[i][j] 转换为 arry[j][i] ; 但是需要注意的是，因为行列个数可能并非相同，转换后行数或者列数变多了或者变少，因此不能直接转换。需要重新申请空间存储转换后的数据。
#include <stdio.h>
#include <stdlib.h>
#define N 3

 int main(){
    void zhuanzhi(int (* arry)[N]);//形参是一个指向N个整形元素的指针，只有这样定义才能指向二维数组名，不能用 int*arry 这样的定义
    int arry[N][N];
    printf("input the 3*3 matrix:\n");
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            scanf("%d",*(arry+i)+j);
    printf("initial matrix:\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%d\t",arry[i][j]); 
        printf("\n");
    }
    zhuanzhi(arry);
    
    printf("zhuanzhi matrix:\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            printf("%d\t",arry[i][j]);   
        printf("\n");
    } 
    system("pause");
    return 0; 
 }
 void zhuanzhi(int (* arry)[N]){
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
                  int tmp = *(*(arry+i)+j);
                *(*(arry+i)+j) = *(*(arry+j)+i);
                *(*(arry+j)+i) = tmp;
        }
    }
 }
/*
//另一种解法
 #define M 4
 int main()
 {
    void zhuanzhi (int (*arry1)[M],int (*arry2)[N],int row_count, int col_count);
	int arry1[N][M];//定义整型二维数组存放矩阵
    int arry2[M][N];//定义整型二维数组存放矩阵
	printf("Please enter a %d x %d matrix: \n",N,M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arry1[i][j]);
		} 
	}
    printf("initial matrix:\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            printf("%d\t",arry1[i][j]); 
        printf("\n");
    }

	zhuanzhi(arry1, arry2 ,N, M);//调用函数并返回一个指针放到指针变量p中
    printf("----------------------------");
    printf("\n");
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", arry2[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
 }
 //转置函数
 void zhuanzhi (int (*arry1)[M],int (*arry2)[N],int row_count, int col_count)
 {
	for (int i = 0; i < col_count; i++) {
        for (int j = 0; j < row_count; j++){
            arry2[i][j]= *(*(arry1+j)+i);
        } 
	}
 }
 */