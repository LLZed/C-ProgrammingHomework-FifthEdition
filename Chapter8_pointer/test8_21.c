/*
21. 用指向指针的指针的方法对n个整数排序并输出。要求将排序单独写成一个函数。n个整数在主函数中输入,最后在主函数中输出。
解题思路:指向指针的指针其实就是二级指针，使用二级指针的保存一级指针的地址，让这个一级指针指向具体的数据空间。
        排序就是按照每个元素指针指向空间中的数据进行比对排序即可。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    void sort(int *p[],int n);
    printf("enter the number of count:");
    scanf("%d",&n);
    int *number = (int*)malloc(n * sizeof(int));     //为指针申请n个int空间用于存放输入的数据,该空间首地址赋给number
	int **p = (int **)malloc(n * sizeof(int*)); //为指针申请n个int*空间用于存放int空间的首地址，该空间首地址赋给p
    for (int i = 0; i < n; i++) {
		p[i] = number + i; //将数组中每个int元素空间的首地址赋值给指针数组中的各个元素
		scanf("%d", p[i]); //p[i]就保存时第i个数据的地址，因此这里不用取地址
	}
    sort(p,n);
	for (int i = 0; i < n; i++) {
		printf("%d ", number[i]);
	}
	printf("\n");
	free(number);
	free(p);
    system("pause");
	return 0;
}
void sort(int *p[],int n){
    int i,j;
	for (i = 0; i < n; i++){
		for (j = i; j < n; j++){
			if (*(p[i]) > *(p[j])){//s[i]保存的就是一个字符串的首地址
				int tmp = *(p[i]); //指针的好处在于直接通过赋值可以改变指向
				*(p[i]) = *(p[j]);  //只要交换了字符串的地址就实现了字符串的交换
				*(p[j]) = tmp;//因此通过指针指向的交换就能够实现数组中字符串的排序
			}
		}
	}
}

