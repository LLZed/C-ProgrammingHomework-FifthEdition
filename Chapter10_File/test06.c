/*
6.将第5题 stud 文件中的学生数据,按平均分进行排序处理,将已排序的学生数据存入一个新文件stu_sort 中。
要保证test5File.txt文件和本程序文件在同一目录下
或者#define FILE_PATH "test5File.txt" // 数据文件的路径
这样可以将数据文件的路径保存在一个字符串变量中，然后在程序中使用该变量来打开文件。这样，你可以更灵活地指定文件的路径，而不仅仅局限于同一目录下。
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
}Stu[N];      //定义一个struct student类型的结构体数组，有10个struct student类型的结构体元素，同时定义一个结构体指针

int main()
{
    void print(struct student student[],int n);   //函数声明
    void aver(struct student student[],int n);   //函数声明
    void Sort(struct student student[],int n);
    void readfile(char *filename,char* way,struct student *array,int n);   //读取文件函数声明
    void inputfile(char *filename,char* way,struct student *array,int n);

    readfile("test5File.txt","r",Stu,N);//以只读的方式打开文件test5File.txt,并且把文件数据读取到结构体数组中，要保证文件和程序文件在同一目录下
    printf("num  name    score1 score2 score3  ave\n--------------------------------------\n");
    print(Stu,N);
    printf("按平均分排序后:\n");
    printf("num  name    score1 score2 score3  ave\n--------------------------------------\n");
    Sort(Stu,N);
    print(Stu,N);
    inputfile("test6stud_sortFile.txt","w+",Stu,N);
    system("pause");
    return 0;
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
//冒泡法排列
void Sort(struct student student[],int n){
    struct student temp;//必须定义同类型的交换变量才可以正确赋值
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<N;j++)
            if(student[i].ave < student[j].ave){
                temp=student[i];
                student[i]=student[j];
                student[j]=temp;
            }
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
