/*
7.将第 6 题已排序的学生成绩文件进行插入处理。
插入一个学生的3门课程成绩,程序先计算新插入学生的平均成绩,然后将它按成绩高低顺序插入,插入后建立一个新文件。
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
}Stu[N],s,*p;      //定义一个struct student类型的结构体数组，有6个struct student类型的结构体元素，同时定义一个结构体指针

int main()
{
    void print(struct student student[],int n);   //函数声明
    void readfile(char *filename,char* way,struct student *array,int n);   //读取文件函数声明
    void inputfile(char *filename,char* way,struct student *array,int n);

    printf("input num:");
    scanf("%s", s.num);
    printf("input name:");
    scanf("%s", s.name);
    for(int j=0;j<3;j++){
        printf("input student's score %d:\n",j+1);
        scanf("%f",&s.score[j]);
    }
    s.ave = (s.score[0] + s.score[1] + s.score[2]) / 3.0;
    p=&s;//用结构体指针指向结构体变量，好调用函数

    readfile("test6stud_sortFile.txt", "r", Stu, N);
    print(Stu, N);
    int i,t;
    for(i=0;s.ave < Stu[i].ave && i<N;i++);//执行空语句来计数i，找到插入位置
    inputfile("test7stud_Insert.txt", "w", Stu, i);//把比插入的学生的平均成绩大的先写入文件
    inputfile("test7stud_Insert.txt", "a", p, 1);//用追加形式打开文件，不然会刷新文件内容，然后把要插入的学生写入文件
    inputfile("test7stud_Insert.txt", "a", &Stu[i], N-i);//再把剩下的数据也写入文件

    system("pause");
    return 0;
}

//输出结构体变量
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

//从文件读取
void readfile(char *filename,char* way,struct student *array,int n)
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
        fscanf(fp,"%s",array[i].num);//格式读取文件数据到结构体变量中
        fscanf(fp,"%s",array[i].name);//格式读取文件数据到结构体变量中
        for(j=0;j<3;j++)
            fscanf(fp," %f ",&array[i].score[j]);//格式读取文件数据到结构体变量中
        fscanf(fp," %f ",&array[i].ave);
    }
    fclose(fp);
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