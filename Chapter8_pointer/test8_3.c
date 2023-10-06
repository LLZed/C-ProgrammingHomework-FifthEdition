/*
写三个函数：1、输入十个整数；2、将其中最小的与第一个对换，把最大的与最后一个对换；3、输出十个数。
*/

#include <stdio.h>
#include <stdlib.h>
#define N 10
//输入函数
void INPUT(int arry[]){
    int i;
    for(i=0;i<N;i++)
        scanf("%d",&arry[i]);
}

//处理函数
void DEAL(int arry[]){
    int i,flagmin,flagmax,t;
        flagmin=0;//假设一开始当前位置是最小数
        flagmax=0;//假设一开始当前位置是最大数
    for(i=0;i<N-1;i++){
        if(arry[flagmin] > arry[i+1]){
            flagmin=i+1;//标记此位置是最小数
        }
        if(arry[flagmax] < arry[i+1]){
            flagmax=i+1;//标记此位置是最大数
        } 
    }
    t=arry[0];
    arry[0]=arry[flagmin];
    arry[flagmin]=t;
    t=arry[N-1];
    arry[N-1]=arry[flagmax];
    arry[flagmax]=t;
}
//输出函数
void OUTPUT(int a[]){
    int i;
    for(i=0;i<N;i++)
        printf("%d ",a[i]);
}
int main(){
    int arry[N];//用于存放十个整数的数组
    printf("请输入十个整数:\n");
    INPUT(arry);//调用输入函数
    DEAL(arry);
    OUTPUT(arry);
    printf("\n");
    system("pause");
    return 0;
}