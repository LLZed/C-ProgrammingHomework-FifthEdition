/*16.
输入一个字符串,内有数字和非数字字符,例如：A123x456 17960? ,302tab5876，将其中连续的数字作为一个整数,
依次存放到一数组a中。例如,123放在a[0],456放在a[1]…统计共有多少个整数,并输出这些数。
解题思路： 
        遇到数字字符，则开始统计连续数字字符的个数，统计完毕后，
        则从右往左每次乘以10（除了个位数）作为数字的单位，最终相加得到数字；
        然后越过这个数字，从后边继续查找。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 50

int main(){
    char str[N];//定义字符数组存放输入的字符串
    int a[20],sum;//定义一个整型数组存放整数,sum是整数的个数
    int fun(char *p1,int *p2);//函数声明，函数的形参是字符型指针和整型指针，返回值是返回整数的个数
    printf("enter string:\n");
    gets(str);
    printf("string:%s\n",str);
    sum=fun(str,a);//调用函数，实参是字符数组和整型数组首地址
    printf("number of the string are:\n");
    for(int i=0;i<sum;i++)
        printf("%d ",a[i]);
    printf("\n共有%d个整数。\n",sum);
    system("pause");
    return 0;
}
int fun(char *p1,int *p2){
    int i=0,j=0,k=0,flag=0;//k用于统计连续的数字个数，flag是首次读到数字标记位
    int str_len=strlen(p1);
    while(i<str_len){       //当当前指向的字符不是空字符时
        //当前指向的字符是数字时
        if(*(p1+i)>='0' && *(p1+i)<='9'){
            if(flag==0){ 
                *(p2+j)=0;//如果是第一次读到数字，先赋给初值
                k++;//如果是第一次读到数字,k+1
            }
            *(p2+j)=(*(p2+j)) * 10 + *(p1+i)-'0';
            flag=1;//下一个元素再继续读到是数字时记为不是第一次读到数字
        }
        //当前指向的字符不是数字且已经读到过数字时
        if((*(p1+i)<'0' || *(p1+i)>'9') && flag==1){        //这里或判断要加上括号，不然在出现连续的非数字时会出错，因为|| 和&&优先级不同
            j++;//存放下一个整数到下一个数组元素
            flag=0;//读到数字标记位赋0
        }
        i++;//指向下一个字符
    }
    return k;
}
