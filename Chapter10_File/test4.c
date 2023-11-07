//4.有两个磁盘文件A和B，各存放一行字母，今要求把这两个文件中的信息合并（按字母顺序排列），输出到一个新文件中

#include <stdio.h>          //包含头文件
#include <stdlib.h>         //包含头文件
#include <string.h>

int main(){
    FILE *fp,*fpA,*fpB;     //定义文件指针
    char str[100];
    char *strSort(char str[]);
    //按读写的方式打开文件C
    if((fp=fopen("C.txt","w+"))==NULL){
        printf("can't open file C!\n");
        system("pause");
        exit(0);
    }
    //按读写的方式打开文件A
    if((fpA=fopen("A.txt","r+"))==NULL){
        printf("can't open file A!\n");
        system("pause");
        exit(0);
    }
    //按读写的方式打开文件B
    if((fpB=fopen("B.txt","r+"))==NULL){
        printf("can't open file B!\n");
        system("pause");
        exit(0);
    }
   
    printf("fileA:");
    //循环将在遇到文件结束符EOF时停止。
    fgets(str, sizeof(str), fpA);//无论文件中的字符数量是多少，fgets函数都会在读取到换行符、文件结束符或达到指定的字符数时停止读取。
    printf("%s\n", str);
    int len=strlen(str);    //得到A文件里字符串的长度
    printf("fileB:");
    fgets(str+len, sizeof(str), fpB);//无论文件中的字符数量是多少，fgets函数都会在读取到换行符、文件结束符或达到指定的字符数时停止读取。
    printf("%s\n", str+len);
    //此时str就是两文件字符串的合并
    printf("%s\n",str);

    //排列字符
    char *string=strSort(str);
    printf("排列后的字符:%s\n",string);

    fputs(string,fp);

    fclose(fp);
    fclose(fpA);
    fclose(fpB);

    system("pause");
    return 0;
}
//冒泡法排序字符
char *strSort(char str[]){
    int i,j,len;
    len=strlen(str);
    for(i=0;i<len-1;i++)
        for(j=i+1;j<len;j++)
            if(str[i]>str[j]){
                char t=str[i];
                str[i]=str[j];
                str[j]=t;
            }
    return str;
}