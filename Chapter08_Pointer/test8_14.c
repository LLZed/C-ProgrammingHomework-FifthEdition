/*
 输入n个数，并逆序排列
*/
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

/*方法一
void fun(char *p)
{
	char tmp,len;
	len = strlen(p);
	for (int i = 0; i <= len/2; i++){
		tmp=*(p+i);
        *(p+i)=*(p+len-1-i);//这里要多减一个1，因为len是数组长度，但是数组的起始从0开始
        *(p+len-1-i)=tmp;
    }
}
int main()
{
	char n[50];
	printf("Please enter number:\n");
    scanf("%s",n);
    printf("%s\n",n);
	fun(n);
    printf("---------------------");
	printf("\n%s\n",n);
	system("pause");
	return 0;
}
*/

//方法二
void sortfun(int *a, int n) {  
    int i,tmp;
	for (int i = 0; i <= n/2; i++){
		tmp=*(a+i);
        *(a+i)=*(a+n-1-i);	//这里要多减一个1，因为n是数组长度，但是数组的起始从0开始
        *(a+n-1-i)=tmp;
    }
}


int main(){
	int *array,num,count=0,i=0;
	char flag='\0';
	array=(int *)malloc(sizeof(int));	// 初始分配内存 

	printf("输入要逆序排列的数,以回车结束:\n");
	do{
		scanf("%d",&num);
		flag=getchar();
		count++;	//记录输入的数的个数
		array=(int *)realloc(array,sizeof(int)*count);
		*(array+i)=num;
		i++;
	}while(flag != '\n');
	/*或者用下面这段
	printf("输入要逆序排列的数, 以非数字结束:\n");  

    // 读取直到非数字  
    while (scanf("%d", &num) == 1) {  
        count++;  // 记录输入的数的个数  
        array = (int *)realloc(array, sizeof(int) * count); // 重新分配内存  
        array[i] = num; // 赋值  
        i++;  
    }  
	*/
	printf("输入的数:\n");
	for(i=0;i<count;i++)
		printf("%d ",*(array+i));
	
	// 这里调用sortfun  
    sortfun(array, count); // 如果需要排序

	printf("\n逆序后:\n");
	for(i=0;i<count;i++)
		printf("%d ",*(array+i));  

	free(array); // 释放内存 
	system("pause");
	return 0;
}
