/*
5.有5个学生，每个学生有 3 门课程的成绩,从键盘输入学生数据(包括学号,姓名,3门课程成绩),计算出平均成绩,
将原有数据和计算出的平均分数存放在磁盘文件 stud （这里存到test5File）中。
*/
#include <stdio.h>          //包含头文件
#include <stdlib.h>         //包含头文件
#include <string.h>
#define N 5

//声明一个结构体类型struct student
struct student{
    char  num[10];
    char  name[10];
    float score[3];
    float ave;    //存放平均分
}Stu[N],*p;      //定义一个struct student类型的结构体数组，有5个struct student类型的结构体元素，同时定义一个结构体指针

int main()
{
    void input(struct student student[],int n);   //输入函数声明
    void print(struct student student[],int n);   //输出函数声明
    void aver(struct student student[],int n);   //函数声明
    void inputfile(char *filename,char* way,struct student *array,int n);   //写入文件函数声明
    p=Stu;      //指针指向Stu结构体数组首地址
    input(p,N);
    aver(p,N);
    printf("num  name    score1   score2   score3  ave\n---------------------------------\n");
    print(p,N);
    inputfile("test5File.txt","w+",Stu,N);//以读写的方式打开文件test5File.txt,并且把长度为N的结构体数组写入文件
    system("pause");
    return 0;
}
//输入
void input(struct student student[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("input No.%d student's num:\n",i+1);
        scanf("%s",student[i].num);
        printf("input No.%d student's name:\n",i+1);
        scanf("%s",student[i].name);
        for(j=0;j<3;j++)
        {
            printf("input student's score %d:\n",j+1);
            scanf("%f",&student[i].score[j]);
        }
        printf("\n");
    }
}
//输出
void print(struct student student[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        printf("%s    ",student[i].num);
        printf("%s    ",student[i].name);
        for(j=0;j<3;j++)
            printf(" %-5.2f ",student[i].score[j]);
        printf(" %-5.2f ",student[i].ave);
        printf("\n");
    }
}
//平均分
void aver(struct student student[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        float sum=0.0;
        for(j=0;j<3;j++)
            sum=sum+student[i].score[j];
        student[i].ave=sum/3.0;
    }
}
//写入文件
void inputfile(char *filename,char* way,struct student *array,int n)
{
    FILE *fp;//定义文件指针
    
    if((fp=fopen(filename,way))==NULL){
        printf("can't open file!\n");
        system("pause");
        exit(0);
    } 
    int i,j;   
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s    ",array[i].num);//格式输出数据到文件
        fprintf(fp,"%s    ",array[i].name);//格式输出数据到文件
        for(j=0;j<3;j++)
            fprintf(fp," %-5.2f ",array[i].score[j]);//格式输出数据到文件中
        fprintf(fp," %-5.2f ",array[i].ave);
        fprintf(fp,"\n");//输出换行符到文件中
    }
    fclose(fp);
}
