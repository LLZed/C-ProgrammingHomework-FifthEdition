/*写几个函数:
①输入10个职工的姓名和职工号;
②按职工号由小到大顺序排序,姓名顺序也随之调整;
③要求输入一个职工号,用折半查找法找出该职工的姓名,从主函数输入要查找的职工号,输出该职工姓名。*/
//输入成绩
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
int main()
{
    void input(int num[],char name[][N]);//函数声明，输入函数，形参是一个整型数组和一个二维字符串数组
    void sort(int num[],char name[N][N]);//函数声明，排序函数，形参是一个整型数组和一个二维字符串数组
    void search(int n,int num[],char name[N][N]);//函数声明，查找函数，形参是一个整型变量，一个整型数组和一个二维字符串数组

    int num[N],number,flag=1,c;
    char name[N][N];
    input(num,name);	//函数调用
    sort(num,name);		//函数调用
    while(flag==1)		//当标志flag=1时
    {
        printf("\n input number to look for:");
		scanf("%d",&number);
		search(number,num,name);		//调用搜索函数
		printf("continue to not(Y/N)?\n");//询问是否继续搜索
        getchar();//用来接收scanf()后的回车键的,如果没有这个getchar，那scanf后，会有一个回车符存在输入流的缓冲区内，那么再使用gets的时候，就会取得这个回车符，gets认为输入结束，就不会让用户输入姓名了。		
        c=getchar();		//输入Y或N
		if(c=='N' || c=='n')
        	flag=0;
    }
    system("pause");
    return 0;
}

void input(int num[],char name[N][N])
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("input No.:");
        scanf("%d",&num[i]); 
        printf("input name:");
		getchar();	//用来接收scanf()后的回车键的,如果没有这个getchar，那scanf后，会有一个回车符存在输入流的缓冲区内，那么再使用gets的时候，就会取得这个回车符，gets认为输入结束，就不会让用户输入姓名了。
        gets(name[i]);
        printf("\n");
    }   
}

void sort(int num[],char name[N][N])//选择排序法按照职工号由小到大排序
{
    int i,j,min,temp;	//定义几个变量，temp用于交换职工号
    char temp2[N];	//定义一个字符串数组，用于交换名字
	for (i = 0; i < N - 1; i++)		//总共有10个人，要比较10-1次
	{
		min = i;	//先让第一个为最小
		for (j = i; j<N; j++)		//与后面的每个都进行比较
			if (num[min]>num[j])  	//如果当前职工号比最小处职工号还要小
				min = j;			//将j作为最小角标，找出最小职工号的位置
		temp = num[i];				//把当前i处的职工号赋给temp
		strcpy(temp2, name[i]); 	//把当前i处的职工姓名赋给temp2
		num[i] = num[min];			//把找到的最小的职工号赋给i处的职工号变量
		strcpy(name[i], name[min]); //把找到的最小的职工姓名也相应转移
		num[min] = temp;
		strcpy(name[min], temp2);
	}
	printf("\n result:\n");
	for (i = 0; i < N; i++)
		printf("\n %5d%10s", num[i], name[i]);
}

void search(int n,int num[],char name[N][N])
{
int top, bott, mid, loca, sign;
	top = 0;		//起始为0
	bott = N - 1;	//末端为N-1
	loca = 0;		//用于标记当前位置
	sign = 1;		//用于标记是否找对，1表示未找到
	if ((n<num[0]) || (n>num[N - 1]))	//判断要找的是否在区间内
		loca = -1;
	while ((sign == 1) && (top <= bott))
	{
		mid = (bott + top) / 2;		//折半查找
		if (n == num[mid])
		{
			loca = mid;
			printf("NO. %d , his name is %s.\n", n, name[loca]);
			sign = -1;		//表示找到了
		}
		else if (n < num[mid])
			bott = mid - 1;
		else
			top = mid + 1;
	}
	if (sign == 1 || loca == -1)
    	printf("%d not been found.\n", n);
}