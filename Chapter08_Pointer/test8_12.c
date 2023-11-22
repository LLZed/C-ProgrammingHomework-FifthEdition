//在主函数中输入10个字符串。用另一函数对它们排序。然后在主函数输出这10个已排好序的字符串。用指针处理。
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
/*
 int main(){
    char str[10][32];
    printf("please enter ten string:\n");
    for(int i=0;i<10;i++)
        scanf("%s",str[i]);

    void sort(char (*s)[32]);
    sort(str);
    printf("\n");
    for(int i=0;i<10;i++)
        printf("%s\n",str[i]);  
    system("pause");
    return 0;
 }
 void sort(char (*s)[32]){
    int i,j;
    for(i=0;i<10;i++)
        for(j=0;j<10;j++)
            if(strcmp(s[i],s[j])>0){
                char tmp[32];
                strcpy(tmp,s[i]);
                strcpy(s[i],s[j]);
                strcpy(s[j],tmp);
            }
 }
 */
//法二
#include<stdio.h>
#include<string.h>
void sort(char *s[10])
{
	int i, j;
	for (i = 0; i < 10; i++){
		for (j = i; j < 10; j++){
			if (strcmp(s[i], s[j])> 0){
				char *tmp = s[i]; //指针的好处在于直接通过赋值可以改变指向
				s[i] = s[j];  //只要交换了字符串的地址就实现了字符串的交换
				s[j] = tmp;//因此通过指针指向的交换就能够实现数组中字符串的排序
			}
		}
	}
}
int main()
{
	char *str[10];
	printf("Please enter ten strings:\n");
	for (int i = 0; i < 10; i++) {
		str[i] = (char *)malloc(32);//为每一个指针分配空间
		scanf("%s", str[i]);
	}
	sort(str);
	printf("\n");
	for (int i = 0; i < 10; i++){
		printf("%s\n", str[i]);
        free(str[i]);//释放开辟的空间
	}
	system("pause");
	return 0;
}

