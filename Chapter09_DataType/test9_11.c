/*
11.有两个链表a和b,设结点中包含学号、姓名。从a链表中删去与b链表中有相同学号的那些结点。
解题思路：
对于b链表中的每一个节点，都从a链表的表头开始查找，如果可以找到，直接删除，如果找不到，继续从a链表表头找下一个b的节点。
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct student			//定义一个结构体类型struct student，有三个成员，并重命名为student
{
	int num;					//学号
	double grade;				//成绩
	struct student *next;		//结构体类型指针
} student;
student *del(student *a, student *b){
	student *pre, *current, *head;		//定义struct student结构体类型的指针变量
	head = a;

	while (b != NULL)
	{
		//重置指针指向a链表的头部
		pre = head;	//pre存放当前节点的地址，一开始时就是存放头部
		current = head->next;	//current存放下一节点的地址
		//a 链表当前节点的学号等于b链表当前节点的学号
		//如果在头节点就是相同学号
		if (pre->num == b->num)
		{
			pre->next = NULL;	
			pre = current;
			current = current->next;
			//更新表头
			head = pre;
		}
		//如果在头节点不是相同学号
		else
		{
			while (pre->next != NULL)
			{
				if (current->num == b->num)
				{
					//找到就删除
					pre->next = current->next;
					break;
				}
				else
				{
					//否则继续遍历
					pre = pre->next;
					current = current->next;
				}
			}
		}
		b = b->next;
	}
	return head;
}
//输出链表函数
void printList(student *root)
{
	printf("----\n");
	int i = 0;
	while (root != NULL)
	{
		printf("student %d -> %d -> %.2lf\n", i, root->num, root->grade);
		root = root->next;	//让root指向下一节点
		i++;
	}
}

int main()
{
	student a[3] = { { 1, 79 }, { 4, 36 }, { 5, 79 } };		//定义struct student结构体类型的数组a并赋初值
	//连接数组元素形成链表
	for (int i = 0; i < 2; i++)
	{
		a[i].next = &a[i + 1];
	}
	a[2].next = NULL;

	printf("链表a:\n");
	printList(&a[0]);

	student b[2] = { { 5, 38 }, { 4, 98 } };			//定义struct student结构体类型的数组b并赋初值
	//连接数组元素形成链表
	for (int i = 0; i < 1; i++)
	{
		b[i].next = &b[i + 1];
	}
	b[1].next = NULL;

	printf("链表b:\n");
	printList(&b[0]);

	student *combine = del(a, b);
	printf("删除之后：\n");
	while (combine != NULL)
	{
		printf("%d -> %.2lf\n", combine->num, combine->grade);
		combine = combine->next;
	}
	system("pause");
	return 0;
}
