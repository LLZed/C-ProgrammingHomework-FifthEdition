//给出年、月、日,计算该日是该年的第几天。
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int date(int y,int m,int d);                        //  函数声明
    int year,month,day,days;                            //定义存放数据的变量
    printf("输入日期(年.月.日):");
    scanf("%d.%d.%d",&year,&month,&day);
    printf("%d/%d/%d/",year,month,day);
    days=date(year,month,day);                          //调用函数
    printf(" is the %dth day in this year.\n",days);
    system("pause");
}
int date(int y,int m,int d)
{
    int days;
    int day_arr[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//每月的天数,这里要多加一个月（0天），因为月份从1开始但是数组从0开始
    int i;
    for(i=0;i<m;i++)
            days+=day_arr[i];                               //把m月前的天数都加起来
    days=days+d;                                            //再加上m月的天数，几号就是几天
    if((y%4==0) && (y%100!=0) || (y%400==0))              //如果年份求余4为0说明是闰年，2月份是29天，最后结果要加1
        return (days+1);
    else
        return (days);
}
