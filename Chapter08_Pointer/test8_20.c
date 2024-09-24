/*20. 
用指向指针的指针的方法对5个字符串排序并输出。
解题思路:指向指针的指针其实就是二级指针，使用二级指针的保存一级指针的地址，让这个一级指针指向具体的数据空间；
        定义一个字符串指针数组包含5个元素，每个元素可以保存一个字符串的首地址，而这个地址指向的是具体的字符串数据空间，
        通过指针访问实现对指向空间内的字符串进行比较排序交换即可。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
//法一，不满足题目要求，没有用指向指针的指针来解决问题。
//虽然指针数组可以被视为一个指向指针（首地址也是指针）的指针，但严格意义上它是一组指向字符的指针的集合而不是一个单独的指向指针的指针，因此指针数组本身不是直接意义上的“指向指针的指针”
int main(){
    char *str[5];//定义字符串指针数组，可以分别保存指向5个字符串所在空间首地址
    void sort(char *p[5]);
    printf("enter 5 strings:\n");
    for(int i=0;i<5;i++){
        printf("enter %d string:",i);
        str[i] = (char *)malloc(32);    //为每一个指针分配空间
        gets(str[i]);
    }
    sort(str);
    system("pause");
	return 0;
}
void sort(char *p[5]){
    int i,j;
	for (i = 0; i < 5; i++)
		for (j = i; j < 5; j++)
			if (strcmp(p[i], p[j])> 0){     //s[i]保存的就是一个字符串的首地址
				char *tmp = p[i];           //指针的好处在于直接通过赋值可以改变指向
				p[i] = p[j];                //只要交换了字符串的地址就实现了字符串的交换
				p[j] = tmp;                 //因此通过指针指向的交换就能够实现数组中字符串的排序
	        }
    printf("strings of after sort:\n");
    for(int i=0;i<5;i++){
        printf("%s\n",p[i]);
        free(p[i]);
    }
}
*/

//法二
int main(){
    void sort(char **p);
    int i;
    char **p,*pstr[5],str[5][LINEMAX];
    for(i=0;i<5;i++)
        pstr[i]=str[i];     //将第i个字符串的首地址赋予指针数组pstr的第i个元素
    printf("input 5 string:\n");
    for(i=0;i<5;i++)
        scanf("%s",pstr[i]);
    p=pstr;
    sort(p);
    printf("\nstring sorted:\n");
    for(i=0;i<5;i++)
        printf("%s\n",pstr[i]);
    system("pause");
	return 0;
}
//用冒泡法对5个字符串排序函数
void sort( char **p){
    int i,j;
    char *temp;
    for(i=0;i<5;i++)
        for(j=i+1;j<5;j++)
            if(strcmp(*(p+i),*(p+j))>0){
                temp=*(p+i);
                *(p+i)=*(p+j);
                *(p+j)=temp;
            }

}

