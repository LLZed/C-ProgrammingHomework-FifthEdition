/*
 输入n个数，并逆序排列
*/
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

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

