/*
有n个整数,使前面各数顺序向后移m个位置,最后m个数变成最前面m个数。
写一函数实现以上功能,在主函数中输入n个整数和输出调整后的n个数。
解题思路： 
找出最后m个数据，从倒数第m个数据这里开始保存数据，
因为倒数第m位置的数据要放到数组最前方，将m之前的数据都向后偏移一位，
然后将数组第一个位置的数据替换为保存的数据，逐个往后递增即可。
*/
#include <stdio.h>
#include <stdlib.h>
#define N 50

int main(){
    int arry[N],n,m;
    void move(int *arry,int n,int m);//函数声明
    printf("Please enter the number of numbers:"); //先确定有几个整数
    scanf("%d",&n);//确定有n个整数
    printf("Please enter %d numbers: ", n);
    for(int i=0;i<n;i++){
        scanf("%d",&arry[i]);
    }
    printf("Number of positions to move: ");
	scanf("%d", &m);//确定要向后移动m个位置
	move(arry, n, m);
	for (int i = 0; i < n; i++) {
		printf("%d ", arry[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
void move(int *arry,int n,int m){
    int end_idx = n - m;   //找到倒数第m个数据在数组中的位置（位置从0开始算），也就是要移动到数组首部的数据的起始位置
	//从倒数第m个数据在数组中的位置开始逐渐向后偏移直到数组尾部
	for (int i = 0; i < m; i++) {
		int *p = arry + end_idx + i;  //从倒数第m个数据在数组中的位置开始逐渐向后偏移直到数组尾部  
		int tmp = *p;       //获取到这个位置的值，用于数组前边数据向后偏移1位之后，向数组第i位赋值
		//从第i位开始逐个向后偏移一位
		for (int j = end_idx + i; j > i; j--) {     
			*p = *(p - 1);
			p--;
		}
		*(arry + i) = tmp;      //数组的前第i个数字逐个替换为后边被覆盖的值
	}
}