/*
3.写一个函数printf，打印一个学生的成绩数组，该数组中有5个学生的数据记录，每个记录包含num，name，score[3]。
用主函数输入这些记录，用printf函数输出这些记录。
*/
#include<stdio.h>
#include<stdlib.h>
#define N 5                                     //宏定义一个全局变量N，宏展开为5

struct student                                  //声明一个结构体类型struct student
{
    char num[10];                               //成员
    char name[10];
    float score[3];    
}student5[N];                                   //定义一个struct student类型的结构体变量，是一个结构体类型数组
int main()
{
    void print(struct student student[]);       //函数声明
    int i,j;
    //输入学生的数据
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
    print(student5);                            //调用函数输出
    system("pause");
}

void print(struct student student[])            //定义一个print函数，用来输出学生成绩
{
    int i,j;
    for(i=0;i<N;i++)
    {
        printf("%s,%s",student5[i].num,student5[i].name);
        for(j=0;j<3;j++)
            printf(" %-5.2f ",student5[i].score[j]);
        printf("\n");
    }
}
