/*
10个学生，每个学生数据包括学号、姓名、3门课程的成绩
从键盘输入学生数据，输出3门成绩总平均成绩，以及最高分的学生数据(包括学号、姓名、3门课程成绩、平均分数)。
*/  
#include<stdio.h>
#include<stdlib.h>
#define N 10

//声明一个结构体类型struct student
struct student{
    char  num[10];
    char  name[10];
    float score[3];    
}Stu[N],*p;      //定义一个struct student类型的结构体数组，有10个struct student类型的结构体元素，同时定义一个结构体指针
float ave[N];       //定义一个float类型的全局数组
int high=0;         //定义一个int类型的全局变量
int main()
{
    void input(struct student student[]);   //函数声明
    void print(struct student student[]);   //函数声明
    void aver(struct student student[]);   //函数声明
    void highest(float ave[N]);   //函数声明
    p=Stu;      //指针指向Stu结构体数组首地址
    input(p);
    aver(p);
    highest(ave);
    print(p);
    system("pause");
    return 0;
}
//输入
void input(struct student student[])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        printf("input No.%d student's num:\n",i+1);
        scanf("%s",&student[i].num);
        printf("input No.%d student's name:\n",i+1);
        scanf("%s",&student[i].name);
        for(j=0;j<3;j++)
        {
            printf("input student's score %d:\n",j+1);
            scanf("%f",&student[i].score[j]);
        }
        printf("\n");
    }
}
//输出
void print(struct student student[])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        printf("%s,%s",student[i].num,student[i].name);
        for(j=0;j<3;j++)
            printf(" %-5.2f ",student[i].score[j]);
        printf(" %-5.2f ",ave[i]);
        printf("\n");
    }
    printf("%s,%s",student[high].num,student[high].name);
    for(j=0;j<3;j++)
        printf(" %-5.2f ",student[high].score[j]);
    printf(" %-5.2f ",ave[high]);
    printf("\n");
}
//平均分
void aver(struct student student[])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        float sum=0.0;
        for(j=0;j<3;j++)
            sum=sum+student[i].score[j];
        ave[i]=sum/3.0;
    }
}
//最高分学生数据
void highest(float ave[N])
{
    int i;
    for(i=0;i<N;i++)
    {
        if(ave[high]<=ave[i])
            high=i;
    }
}