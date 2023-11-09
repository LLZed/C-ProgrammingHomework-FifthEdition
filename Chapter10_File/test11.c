/*
11.从键盘输入若干行字符(每行长度不等),输入后把它们存储到一磁盘文件中。再从该文件中读入这些数据,将其中小写字母转换成大写字母后在显示屏上输出。
*/
#include <stdio.h>          //包含头文件
#include <stdlib.h>         //包含头文件
#include <string.h>
#define N 80

int main(){
    char str[N],c;        //指向字符串数组    
    FILE *fp;        //定义文件指针
    //用只写的方式打开文件test
    if((fp=fopen("test11.txt","w")) == NULL){
        printf("file can't open!\n");
        system("pause");
        exit(0);
    }

    int flag=1;
    while(flag==1){
        printf("input string:\n");    
        fgets(str, 100, stdin);   //使用更安全的函数fgets
        fprintf(fp,"%s",str);//写入到文件中
        printf("continue?(Y or N) ");
        c=getchar();
        if((c=='N')|| (c=='n'))
            flag=0;
        getchar();//消化回车符
    }
    fclose(fp);//关闭文件
    //用只读的方式打开文件test
    if((fp=fopen("test11.txt","r")) == NULL){
        printf("file can't open!\n");
        system("pause");
        exit(0);
    }
    //当从文件中读取的是字符串时
    while(fscanf(fp,"%s",str)!=EOF){
        for(int i=0;str[i]!='\0';i++)
            if(str[i]>='a' && str[i]<='z')
                str[i]=str[i]-32;       //小写转大写
        printf("%s\n",str);
    }
    fclose(fp);         //用完关闭文件

    system("pause");
    return 0;
}