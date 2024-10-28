/*
11.有两个链表a和b,设结点中包含学号、姓名。从a链表中删去与b链表中有相同学号的那些结点。
解题思路：
对于b链表中的每一个节点，都从a链表的表头开始查找，如果可以找到，直接删除，如果找不到，继续从a链表表头找下一个b的节点。
*/
#include <stdio.h>
#include <stdlib.h>
#define LENa 4
#define LENb 5

typedef struct student			//定义一个结构体类型struct student，有三个成员，并重命名为student,即student就表示struct student
{
	int num;					//学号
	char name[10];				//姓名
	struct student *next;		//结构体类型指针
}student;

int main()
{
	//函数声明
	student *del(student *a, student *b);
	void printList(student *head);

	student a[LENa] = { { 101, "wang" }, { 102, "li" }, { 105, "zhang" },{106,"wei"} };		//定义struct student结构体类型的数组a并赋初值
	//连接数组元素形成链表
	for (int i = 0; i < LENa-1; i++)	//因为下面是用到i+1，所以这里i的最大值小于LENa-1
		a[i].next = &a[i + 1];
	a[LENa].next = NULL;

	printf("链表a:\n");
	printList(&a[0]);

	student b[LENb] = { { 103, "zhang" }, { 104, "ma" },{105,"chen"},{107,"guo"},{108,"liu"} };			//定义struct student结构体类型的数组b并赋初值
	//连接数组元素形成链表
	for (int i = 0; i < LENb-1; i++)	//因为下面是用到i+1，所以这里i的最大值小于LENb-1
		b[i].next = &b[i + 1];
	b[LENb].next = NULL;

	printf("链表b:\n");
	printList(&b[0]);

	student *combine = del(a, b);
	printf("删除之后：\n");
	while (combine != NULL)
	{
		printf("%d -> %s\n", combine->num, combine->name);
		combine = combine->next;
	}
	system("pause");
	return 0;
}

student *del(student *a, student *b){
	student *head, *current, *follow;		//定义struct student结构体类型的指针变量,head指向头结点
	head = a;				//头结点赋值
	while (b != NULL)		//当没有比较到最后一个结点时
	{
		//重置指针指向a链表的头部
		current = head;		//current存放当前节点的地址，一开始时就是存放头结点
		follow = head->next;	//current存放下一节点的地址
		//如果a链表当前节点的学号等于b链表当前节点的学号
		//如果在头结点就是相同学号
		if (current->num == b->num)
		{
			current->next = NULL;	
			current = follow;
			follow = follow->next;
			//更新表头
			head = current;
		}
		//如果在头节点不是相同学号
		else
		{
			while (current->next != NULL)
			{
				if (follow->num == b->num)
				{
					//找到就删除
					current->next = follow->next;
					break;
				}
				else
				{
					//否则继续遍历链表a
					current = current->next;
					follow = follow->next;
				}
			}
		}
		b = b->next;
	}
	return head;
}
//输出链表函数
void printList(student *head)
{
	printf("----\n");
	int i = 0;
	while (head != NULL)
	{
		printf("student %d -> %d -> %s\n", i+1, head->num, head->name);
		head = head->next;	//让head指向下一节点
		i++;
	}
}
