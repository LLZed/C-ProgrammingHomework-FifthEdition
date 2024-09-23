/*19.
(1) 编写一个函数new,对n个字符开辟连续的存储空间,此函数应返回一个指针(地址),指向字符串开始的空间。
    new(n)表示分配n个字节的内存空间。
(2)写一函数free,将前面用new函数占用的空间释放。free§表示将p(地址)指向的单元以后的内存段释放。
解题思路：封装malloc函数申请空间，封装free函数释放空间；
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char* new(int n);//指针函数，返回值是一个字符指针
    void Free(char* p);//空间释放函数
    int n;//要对n个字符开创空间
    char *str=NULL;
    printf("enter n:");
    scanf("%d",&n);
    printf("before new p : %p  %s\n", str, str);//申请空间之前，查看指针的地址和指向空间数据
    str=new(n);
    printf("after new p : %p  %s\n", str, str);//申请空间之后，查看指针的地址和指向空间数据

    printf("输入n个字符:");
    getchar();//消化掉上一个回车符
    gets(str);

    printf("before free p : %p  %s\n", str, str);//释放空间之前，查看指针的地址和指向空间数据
    Free(str);
    printf("after free p : %p  %s\n", str, str);//释放空间之后，查看指针的地址和指向空间数据
    system("pause");
    return 0;
}
char* new(int n){
    char* p0;
    p0=(char*)malloc(n+1);//开辟n+1个类型为char型、长度为字符长度的连续空间，首地址赋给p0。如果开辟n个输入n个会出错
    return p0;
}
void Free(char * p){
    free(p);//释放开辟的空间
}

/*
#include <stdio.h>
#define NEWSIZE 100        //指定开辟存储区的最大容量
char newbuf[NEWSIZE];
char *newp=newbuf;

char *new(int n){
    if(newp+n <= newbuf+NEWSIZE)        //开辟区位超过newbuf数组的大小
    {
        newp+=n;        //指向存储区的末尾
        return(newp-n);     //返回指向存储区的开始位置的指针
    }
    else
        return(NULL);   //当存储区不够分配时返回空指针
}

void free(char *p){
    if(p >= newbuf && p < newbuf+NEWSIZE)
        newp=p;         
}
//这样下次再开辟新区域时就从newp指向的字节开始分配，相当于释放了此段空间，使其可再分配作其他用途
*/
