/*
9.有一磁盘文件 employee,内存放职工的数据。每个职工的数据包括职工姓名、职号、性别、年龄、住址、工资、健康状况、文化程度。
今要求将职工名、工资的信息单独抽出来另建一个简明的职工工资文件。
*/
#include <stdio.h>          //包含头文件
#include <stdlib.h>         //包含头文件
#include <string.h>
#define N 10

//声明一个结构体类型struct student
struct employee{
    char  name[10]; //职工姓名
    char  num[10];  //职号
    char  sex[2];  //性别
    int age;        //年龄
    char addr[20];
    float salary;
    char health[8];
    char class[10];//文化程度
}Emp[N];
struct employeepart{
    char  name[10]; //职工姓名
    float salary;
}Emppart[N];

int main()
{
//写入文件
    FILE *fp;//定义文件指针
    int i;
//读取文件数据
    if((fp=fopen("employee","r"))==NULL){
        printf("can't open file!\n");
        system("pause");
        exit(0);
    } 
    for(i=0;i<N;i++)
    {
        fscanf(fp,"%s %s %s %d %s %f %s %s", Emp[i].name,Emp[i].num,Emp[i].sex,&Emp[i].age,Emp[i].addr,&Emp[i].salary,Emp[i].health,Emp[i].class);
    }
    fclose(fp);
        
//输出结构体变量
    for(i=0;i<N;i++){
        printf("%s %s %s %d %s %5.2f %s %s", Emp[i].name,Emp[i].num,Emp[i].sex,Emp[i].age,Emp[i].addr,Emp[i].salary,Emp[i].health,Emp[i].class);
        printf("\n");
    }
    printf("职工姓名  工资:\n");
    for(i=0;i<N;i++)
    {
        for(int j=0;j<10;j++)
            Emppart[i].name[j]=Emp[i].name[j];
        Emppart[i].salary=Emp[i].salary;
    }
//输出结构体变量
    for(i=0;i<N;i++){
        printf("%s %5.2f", Emppart[i].name,Emp[i].salary);
        printf("\n");
    }
//写入新文件
    if((fp=fopen("employee.txt","w"))==NULL){
        printf("can't open file!\n");
        system("pause");
        exit(0);
    } 
    for(i=0;i<N;i++)
    {
        fprintf(fp,"%s  %f",Emppart[i].name,Emppart[i].salary);
        fprintf(fp,"\n");
    }
    fclose(fp);

    system("pause");
    return 0;
}
