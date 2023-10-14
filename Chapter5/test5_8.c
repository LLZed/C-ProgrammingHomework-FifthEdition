/*
输出所有的“水仙花数”,所谓“水仙花数”是指一个3位数,其各位数字立方和等于该数本身。
例如,153是水仙花数,因为153=1^3+5^3+3^3。
*/
#include <stdio.h>
#include <stdlib.h>

void main(){
    int a,b,c;//a表示百位数字，b表示十位数字，c表示个位数字
    printf("所有的水仙数(各位数字立方和等于该数本身):\n");
    for(int i=100;i<=999;i++){
        a=i/100;
        b=i/10%10;
        c=i%10;
        if(i==(a*a*a+b*b*b+c*c*c))
            printf("%d\n",i);
        else 
            continue;
    }
    system("pause");
}