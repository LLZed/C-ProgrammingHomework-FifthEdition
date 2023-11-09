/*
9_1.有一磁盘文件 employee,内存放职工的数据。每个职工的数据包括职工姓名、职号、性别、年龄、住址、工资、健康状况、文化程度。
建立这个存放职工数据的磁盘文件。
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

int main()
{
//写入文件
    FILE *fp;//定义文件指针
    int i;
    printf("输入职工姓名、职号、性别、年龄、住址、工资、健康状况、文化程度:\n");    
    for(i=0;i<N;i++){
        scanf("%s %s %s %d %s %f %s %s", Emp[i].name,Emp[i].num,Emp[i].sex,&Emp[i].age,Emp[i].addr,&Emp[i].salary,Emp[i].health,Emp[i].class);
    }
    //输出结构体变量
     for(i=0;i<N;i++){
        printf("%s %s %s %d %s %5.2f %s %s", Emp[i].name,Emp[i].num,Emp[i].sex,Emp[i].age,Emp[i].addr,Emp[i].salary,Emp[i].health,Emp[i].class);
        printf("\n");
    }

    if((fp=fopen("employee","w"))==NULL){
        printf("can't open file!\n");
        system("pause");
        exit(0);
    } 
    for(i=0;i<N;i++)
    {
        fprintf(fp,"%s %s %s %d %s %5.2f %s %s",Emp[i].name,Emp[i].num,Emp[i].sex,Emp[i].age,Emp[i].addr,Emp[i].salary,Emp[i].health,Emp[i].class);//格式输出数据到文件中
        fprintf(fp,"\n");//输出换行符到文件中
    }
    fclose(fp);

    system("pause");
    return 0;
}



