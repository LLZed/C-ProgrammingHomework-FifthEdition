/*
10.已有a,b两个链表,每个链表中的结点包括学号、成绩。要求把两个链表合并, 按学号升序排列。
解题思路：
首先合并两个链表，然后采用选择排序，给合并之后的链表进行排序。
*/

#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct student)      //定义LEN的值为结构体的长度

struct student                          //定义一个结构体类型struct student，有三个成员
{
    long num;                           //学号（长整型）
    float score;                        //成绩（浮点型）
    struct student *next;               //指向结构体类型数据的指针变量成员next（指针类型的成员，它指向结构体类型数据，就是它所在的结构体类型）
};                           

int n,sum=0;                            //定义全局变量

struct student *merge(struct student *a, struct student *b)
{
    //先合并，后排序
    struct student *head = a;
    while (a->next != NULL)
    {
        a = a->next;
    }
    a->next = b;
	//选择排序，每次选最小的，放在未排序的链表头部
    struct student *pre;
    pre = head;
    while (pre->next != NULL)
    {
        a = pre->next;
        while (a != NULL)
        {
            if (pre->num > a->num)
            {
                int num = pre->num;
                double score = pre->score;
                pre->num = a->num;
                pre->score = a->score;
                a->num = num;
                a->score = score;
            }
            a = a->next;
        }
        pre = pre->next;
    }
    return head;
}
int main()
{
    struct student a[3] = {{1, 79}, {4, 36}, {5, 79}};
    for (int i = 0; i < 2; i++)
    {
        a[i].next = &a[i + 1];
    }

    struct student b[2] = {{2, 38}, {6, 98}};
    for (int i = 0; i < 1; i++)
    {
        b[i].next = &b[i + 1];
    }
    struct student *combine = merge(a, b);      //调用函数合并链表并且排序
    //遍历链表输出所有成员
    while (combine != NULL)
    {
        printf("%d -> %.2lf\n", combine->num, combine->score);
        combine = combine->next;
    }
    system("pause");
    return 0;
}
