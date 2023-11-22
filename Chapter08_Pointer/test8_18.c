/*
编一程序,输入月份号,输出该月的英文月名。例如，输入3,则输出"March" ,要求用指针数组处理。
解题思路：首先定义字符串指针数字，数组中每一个元素都存放一个字符串指针，每个指针指向不同字符串的位置。
则输入月份数字后，根据下标获取对应月份字符串的地址即可
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int num;//月份号
    char* Month[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};//存放月份单词
    while(1){
        printf("enter the number of month: ");
        scanf("%d",&num);
        if(num>=1 && num<=12)
            printf("%s\n", Month[num-1]);
        else
            printf("Input error, Month should be greater than 0 and less than 12.\n");
    }
    system("pause");
    return 0;
}