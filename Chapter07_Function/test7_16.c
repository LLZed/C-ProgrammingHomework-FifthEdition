//写一个函数,输入一个十六进制数,输出相应的十进制数。
/*
#include<stdio.h>
#include<stdlib.h>
size_t HextoDec(char s[])						//函数功能定义，形参是字符串数组
{
	size_t i, n;								//定义一个基本的无符号整数的C / C + +类型size_t变量，它是sizeof操作符返回的结果类型，该类型的大小可选择
	n = 0;										//赋初值给n
	for (i = 0; s[i] != '\0'; i++)				//检查字符串的每个字符，并且当字符不是空字符时做循环
	{
		if (s[i] >= '0'&& s[i] <= '9')			//如果字符是十六进制0到9的话，进行该位字符的十进制转换
			n = n * 16 + s[i] - '0';			//权值法进行进制转换，十六进制的权值为16
		if (s[i] >= 'a' && s[i] <= 'f')			//如果字符是十六进制10到15的话
			n = n * 16 + s[i] - 'a' + 10;		//权值法
		if (s[i] >= 'A' && s[i] <= 'F')			//如果字符是十六进制10到15的话
			n = n * 16 + s[i] - 'A' + 10;
	}
	return n;
}
int main()
{
	size_t result = 0;							//定义一个基本的无符号整数的C / C + +类型size_t变量result，并赋初值为0
	char hex[9] = {0}; 							//定义一个字符串数组存放十六进制数
	printf("input a HEX number:");
	scanf("%s", hex);
	result = HextoDec(hex);						//调用函数转换进制
	printf("0x%s = %u\n", hex, result);			//输出结果
	system("pause");
	return 0;
}
/*  这是用来将数组s[]中存放的十六进制字符串转换成对应的数值的代码
	根据进位计数制，比如4位16进制数 s3 s2 s1 s0，
	其数值=s3*16^3 +s2*16^2 +s1*16^1 +s0*16^0 = ( ( (0*16 +s3)*16 + s2)*16 +s1)*16 +s0
    而数组s[]中存放的是16进制的字符，如'9','7'等，要变成数值就需要减去字符'0'，也就是s[i]-'0'。*/




#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int main()
{
	int htoi(char s[]);							//函数声明
	int c,i,flag,flag1;
	char t[MAX];								//定义一个数组用来存放十六进制数
	i=0;
	flag=0;										//
	flag1=1;
	printf("input a HEX number: ");
	while((c=getchar())!='\0' && i<MAX && flag1)//输入的字符不为EOF（文件结束符），不超过定义长度且flag1=1
	{
		if(c>='0' && c<='9' || c>='a'&&c<='f' || c>='A' && c<='F')
		{
			flag=1;			//标记变量赋值1
			t[i++]=c;		//把输入的字符一个个放入字符数组t中
		}
		else if(flag)
		{
			t[i]='\0';		//结束t字符数组
			printf("decimal number: %d\n",htoi(t));
			printf("continue or not?");
			c=getchar();
			if (c=='N' || c=='n')
				flag1=0;
			else if(c=='Y' || c=='y')
			{
				flag=0;
				i=0;
				printf("\ninput a HEX number:");
			}
			
		}
	}
return 0;
}

int htoi(char s[])
{
	int i,n;
	n=0;
	for(i=0;s[i]!='\0';i++)
	{	if(s[i] >= '0'  && s[i] <= '9')
			n = n * 16 + s[i] - '0';		//权值法进行进制转换，十六进制的权值为16
		if (s[i] >= 'a' && s[i] <= 'f') 	//如果字符是十六进制10到15的话
			n = n * 16 + s[i] - 'a' + 10;	//权值法
		if (s[i] >= 'A' && s[i] <= 'F')		//如果字符是十六进制10到15的话
			n = n * 16 + s[i] - 'A' + 10;
	}
	return n;
}