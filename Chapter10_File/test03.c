//3.从键盘输入一个字符串，将其中的小写字母全部转换成大写字，然后输出到一个磁盘文件test中保存，输入的字符串以“！”结束

#include <stdio.h>          //包含头文件
#include <stdlib.h>         //包含头文件
#include <string.h>

int main(){
    char *s;        //指向字符串的指针
    s=(char*)malloc(100*sizeof(char));      //开辟空间     
    FILE *fp;        //定义文件指针
    //用只写的方式打开文件test
    if((fp=fopen("test3.txt","w")) == NULL){
        printf("file can't open!\n");
        system("pause");
        exit(0);
    }

    printf("输入字符串（以\"!\"结束）：");      //用\"来输出英文双引号"
    //scanf("%s",s);  //不能输入空格，不用这个
    //gets(s);        //输入字符串,gets函数存在安全性问题，因为它无法防止缓冲区溢出。
    fgets(s, 100, stdin);   //使用更安全的函数fgets(s, 100, stdin)来代替。
    printf("%s\n",s);     //检测输入
    int i=0;
    while(*(s+i)!='!'){
        if(*(s+i)>='a' && *(s+i)<='z')
            *(s+i)=*(s+i)-32;       //小写转大写
        fputc(*(s+i),fp);        //写入到文件中
        i++;
    }
    fclose(fp);         //用完关闭文件
    //检验是否成功写入文件
    if((fp=fopen("test3.txt","r"))==NULL)       //用只读的方式打开文件test
        printf("-1");
    char *str;
    int n=strlen(s)+1;
    free(s);
    str = malloc(n * sizeof(char));//没有为str分配内存空间。在之后的fgets(str,n,fp)中，由于str没有被初始化，它指向的内存位置是未知的，因此导致了段错误。
    fgets(str,n,fp);      
    printf("%s\n",str);
    fclose(fp);
    free(str);                                //释放空间

    system("pause");
    return 0;
}
