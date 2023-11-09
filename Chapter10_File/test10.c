/*
10.从第9题的“职工工资文件”中删去一个职工的数据,再存回原文件
*/
#include <stdio.h>          //包含头文件
#include <stdlib.h>         //包含头文件
#include <string.h>
#define N 10

struct employeepart{
    char  name[10]; //职工姓名
    float salary;
}Emppart[N],s;

int main()
{
//输入要删除职工名字
    printf("input name:");
    scanf("%s", s.name);

//写入文件
    FILE *fp;//定义文件指针
    int i,n;
//读取文件数据
    if((fp=fopen("employee.txt","r"))==NULL){
        printf("can't open file!\n");
        system("pause");
        exit(0);
    } 
    for(i=0;i<N;i++)
    {
        fscanf(fp,"%s %f", Emppart[i].name,&Emppart[i].salary);
    }
    fclose(fp);
    
//输出结构体变量
    for(i=0;i<N;i++){
        printf("%s %5.2f", Emppart[i].name,Emppart[i].salary);
        printf("\n");
    }
//寻找要删除的
    for(i=0;i<N;i++)
    {
        //如果找到要删除的员工，就把后面的数据都往前存放，覆盖掉被找到的员工
        if(strcmp(s.name,Emppart[i].name)==0){
            for(int j=i;j<n-1;j++){
                strcpy(Emppart[j].name , Emppart[j+1].name);
                Emppart[j].salary = Emppart[j+1].salary;
            }
            n=N-1;
            break;
        }
        //如果没有找到，说明不在文件中
        if(i==N-1){
            n=N;
            printf("要删除的职工不在文件中\n");
        }
    }
//输出结构体变量
    printf("\n");
    for(i=0;i<n;i++){
        printf("%s %5.2f", Emppart[i].name,Emppart[i].salary);
        printf("\n");
    }
//写入原文件
    if((fp=fopen("employee.txt","w"))==NULL){
        printf("can't open file!\n");
        system("pause");
        exit(0);
    } 
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%s  %f",Emppart[i].name,Emppart[i].salary);
        fprintf(fp,"\n");
    }
    fclose(fp);

    system("pause");
    return 0;
}
