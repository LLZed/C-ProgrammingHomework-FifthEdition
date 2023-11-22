/*
12.建立一个链表,每个结点包括:学号、姓名、性别、年龄。输入一个年龄，如果链表中的结点所包含的年龄等于此年龄,则将此结点删去。
*/

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
