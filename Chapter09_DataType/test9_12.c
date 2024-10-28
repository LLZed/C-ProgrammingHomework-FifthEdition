/*
12.建立一个链表,每个结点包括:学号、姓名、性别、年龄。输入一个年龄，如果链表中的结点所包含的年龄等于此年龄,则将此结点删去。
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct student)
typedef struct student	//定义一个结构体类型struct student，有三个成员，并重命名为student
{
	char num[10];		//学号
	char name[20];	//姓名
	char sex[10];	//性别
	int age;		//年龄
	struct student *next;
} student;
//输出链表函数
void printList(student *head)
{
	printf("List data:\n");
	while (head != NULL)
	{
		printf("num:%s  name: %s  sex: %s  age: %d\n", head->num, head->name,head->sex,  head->age);
		head = head->next;//让head指向下一节点
	}
}

int main()
{
	student *head,*current,*p,*pre;	//current表示当前指向的结点,pre指向current的上一个结点
	int find=0;		//在数据找到待删除元素时find=1，否则find=0
	//建立链表
	pre=current=head=(student *)malloc(LEN);
	while(1)
	{
		printf("input num:");
		scanf("%s",current->num);
		printf("input name:");
		scanf("%s",current->name);
		printf("input sex:");
		scanf("%s",current->sex);
		printf("input age:");
		scanf("%d",&current->age);

		if(strcmp(current->num, "0") ==0 && strcmp(current->name, "0") ==0 && strcmp(current->sex, "0") ==0 && current->age == 0)
			break;		//跳出循环
		else
		{
			p=(student *)malloc(LEN);
			pre=current;	//标记当前current所指向的值不为零的结点
			current->next=p;
			current=p;
		}
	}
	pre->next=NULL;
	printList(head);

	//删除指定结点
	int n;
	printf("请输入要删除的年龄：\n");
	scanf("%d", &n);
	pre=current=head;		//使当前结点指向头结点
	while (current != NULL)
	{
		//如果头结点需要删除，则更新头结点
		if (head->age == n)
		{
			head = head->next;
			current = head;
			find=1;
			printf("The first was deleted!\n");
		}
		//如果不是头结点
		else
		{
			//删除节点，重新链接
			if (current->age == n)
			{
				pre->next = current->next;
				find=1;
				break;		//删除完就退出循环
			}
			//继续遍历寻找
			pre = current;
			current = current->next;
		}
	}
	//如果没有找到要删除的，则进行提示
	if(find==0)
		printf("age=%d not been found!\n",n);
	//如果找到要删除的并且删除掉了
	if(find==1)
		printf("Alreadly deleted!\nRemaining data:\n",n);
	printList(head);
	system("pause");
	return 0;
}


/*
12.建立一个链表,每个结点包括:学号、姓名、性别、年龄。输入一个年龄，如果链表中的结点所包含的年龄等于此年龄,则将此结点删去。

#include <stdio.h>
#include <stdlib.h>
typedef struct student	//定义一个结构体类型struct student，有三个成员，并重命名为student
{
	int num;		//学号
	char sex[10];	//性别
	char name[100];	//姓名
	int age;		//年龄
	struct student *next;
} student;
//输出链表函数
void printList(student *root)
{
	printf("----\n");
	while (root != NULL)
	{
		printf("num:%d, sex: %s, name: %s, age: %d\n", root->num, root->sex, root->name, root->age);
		root = root->next;//让root指向下一节点
	}
}

int main()
{
	student a[] = { { 1, "woman", "apple", 12 }, { 4, "woman", "banbana", 36 }, { 5, "man", "candy", 79 }, { 5, "man", "danny", 36 }, { 4, "man", "enjoy", 98 } };
	for (int i = 0; i < 4; i++)
	{
		a[i].next = &a[i + 1];
	}
	a[4].next = NULL;

	printList(&a[0]);

	int n;
	printf("请输入要删除的年龄：\n");
	scanf("%d", &n);
	student *pre = a, *current = a->next, *head;

	head = a;
	while (current != NULL)
	{
		//如果头结点需要删除，则更新头结点
		if (head->age == n)
		{
			pre->next = NULL;
			pre = current;
			current = current->next;
			head = pre;
		}
		else
		{
			//删除节点，重新链接
			if (current->age == n)
			{
				pre->next = current->next;
			}
			pre = current;
			current = current->next;
		}
	}
	printList(head);
	system("pause");
	return 0;
}
*/
