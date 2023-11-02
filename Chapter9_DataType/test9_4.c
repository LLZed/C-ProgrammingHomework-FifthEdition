/*
4.在第3题的基础上,编写一个函数input,用来输入5个学生的数据记录。
第3题:写一个函数输入printf，打印一个学生的成绩数组，该数组中有5个学生的数据记录，每个记录包含num，name，score[3]，用printf函数输出这些记录。
*/

#include<stdio.h>
#include<stdlib.h>
#define N 5

struct student              //声明一个结构体类型struct student
{
    char num[10];
    char name[10];
    float score[3];    
}student5[N];               //定义一个struct student类型的结构体变量，是一个结构体类型数组
int main()
{
    void input(struct student student[]);
    void print(struct student student[]);
    input(student5);        //调用函数输入
    print(student5);        //调用函数输出
    system("pause");
    return 0;
}
//输入函数定义
void input(struct student student[])//参数是struct student结构体类型的变量
{
    int i,j;
    //遍历数组，输入数据
    for(i=0;i<N;i++)
    {
        printf("input No.%d student's num:\n",i+1);
        scanf("%s",&student5[i].num);
        printf("input No.%d student's name:\n",i+1);
        scanf("%s",&student5[i].name);
        for(j=0;j<3;j++)
        {
            printf("input student's score %d:\n",j+1);
            scanf("%f",&student5[i].score[j]);
        }
        printf("\n");
    }
}
//输出函数定义
void print(struct student student[])//参数是struct student结构体类型的变量
{
    int i,j;
    //遍历数组，输出数据
    for(i=0;i<N;i++)
    {
        printf("%s,%s",student5[i].num,student5[i].name);
        for(j=0;j<3;j++)
            printf(" %-5.2f ",student5[i].score[j]);
        printf("\n");
    }
}