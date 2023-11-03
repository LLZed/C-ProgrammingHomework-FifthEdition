#define _CRT_SECURE_NO_WANRNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    double b,b1,b2,b4,b6,b10;
    b1=100000*0.1;  //满10w的满额奖金
    b2=b1+100000*0.075; //满20w的满额奖金
    b4=b2+200000*0.05;  //满40w的满额奖金
    b6=b4+200000*0.03;  //满60w的满额奖金
    b10=b6+400000*0.015;    //满100w的满额奖金
    printf("请输入利润：");
    scanf("%d",&i);

    // if (i<=100000)
    // {   
    //     b=i*0.1;
    // }
    // else if(i>100000&&i<=200000)
    // {
    //     b=b1+(i-100000)*0.075;
    // }
    // else if(i>20000&&i<=400000)
    // {
    //     b=b2+(i-200000)*0.05;
    // }
    // else if(i>400000&&i<=600000)
    // {
    //     b=b4+(i-400000)*0.03;
    // }
    // else if(i>600000&&i<=1000000)
    // {
    //     b=b6+(i-600000)*0.015;
    // }
    // else if(i>1000000)
    // {
    //     b=b10+(i-10000000)*0.01;
    // }
    //  printf("奖金：%.2lf\n",b); 

    int level=i/100000;
     switch (level)
    {
    case 0/* constant-expression */:
        b=i*0.1;
        break;
    case 1/* constant-expression */:
        b=b1+(i-100000)*0.075;
        break;
    case 2/* constant-expression */:
    case 3/* constant-expression */:
        b=b2+(i-200000)*0.05;
        break;
    case 4/* constant-expression */:
    case 5/* constant-expression */:
        b=b4+(i-400000)*0.03;
        break;
    case 6/* constant-expression */:
    case 7/* constant-expression */:
    case 8/* constant-expression */:
    case 9/* constant-expression */:
        b=b6+(i-600000)*0.015;
        break;
    case 10/* constant-expression */:
        b=b10+(i-10000000)*0.01;
        break;
    }
    printf("奖金：%.2lf\n",b);
    system("pause");    // 防止运行后自动退出，需头文件stdlib.h
    return 0;
}


