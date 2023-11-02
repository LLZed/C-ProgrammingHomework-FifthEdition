//定义一个结构体变量包含年、月、日,用一个函数计算该日是该年的第几天,由主函数将年、月、日传递给days函数,计算后将日子数传回主函数输出。
#include<stdio.h>
#include<stdlib.h>

struct date //声明一个结构体类型struct date
{
    int year;
    int month;
    int day;
}date1;     //定义一个struct date类型的结构体变量date1

void main()
{
    int days(int y,int m,int d);
    int n;  //存放计算好的天数
    printf("输入日期(年.月.日):");
    scanf("%d.%d.%d",&date1.year,&date1.month,&date1.day);
    printf("%d/%d/%d/",date1.year,date1.month,date1.day);
    n=days(date1.year,date1.month,date1.day);
    printf(" is the %dth day in this year.\n",n);
    system("pause");
}

int days(int y,int m,int d)
{
    int i,days=0;
    int day_arr[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//每月的天数,这里要多加一个月（0天），因为月份从1开始但是数组从0开始
    for(i=0;i<date1.month;i++)
            days+=day_arr[i];                               //把m月前的天数都加起来
    days=days+date1.day;                                            //再加上m月的天数，几号就是几天
    if((date1.year%4==0) && (date1.year%100!=0) || (date1.year%400==0))              //如果年份求余4为0说明是闰年，2月份是29天，最后结果要加1
        return (days+1);
    else
        return (days);
}