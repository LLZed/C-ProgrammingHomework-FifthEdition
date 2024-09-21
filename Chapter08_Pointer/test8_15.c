/*
输入4个学生5门课的成绩,分别用函数和指针实现下列功能:
①计算第1门课程的平均分;
②找出有两门以上课程不及格的学生,输出他们的学号和全部课程成绩及平均成绩;
③找出平均成绩在90分以上或全部课程成绩在85分以上的学生;
解题思路： 4个学生，5门课程就是一个4x5的二维数组，
        求第一门课的平均分，就是将第0列数据相加除以学生人数
        遍历每个学生的成绩，判断不及格次数，若大于2则输出信息即可
        统计每个学生总成绩，以及对每门课程成绩进行判断即可
*/
#include <stdio.h>
#include <stdlib.h>
#define N 4
#define M 5

int main()
{
    float score[N][M];
    void input(float (*p)[M]);           //输入函数声明
    void first_aver(float (*p)[M]);    //第1门成绩平均分函数声明
    void fail(float (*p)[M]);         //找不及格函数声明
    void fun(float (*p)[M]);     //找平均成绩在90分以上或全部课程成绩在85分以上的学生函数声明

    input(score);            //函数调用
    printf("\nNO.     cour1      cour2      cour3      cour4      cour5\n");//输出课程成绩
    for(int i=0;i<N;i++)            //4个学生
    {
        printf("\nNO.%2d ", i + 1);        //输出是第几个学生
		for (int j = 0; j < M; j++)             //5门课程
			printf("%6.2f",score[i][j]);    //输出每个学生的每门课程成绩
	}
    printf("\n------------------------------------------------------\n");
    first_aver(score);     //函数调用
    fail(score);        //函数调用
    fun(score);

    system("pause");
    return 0;
}

//输入成绩
void input(float (*p)[M])
{
    for(int i=0;i<N;i++)
    {
        printf("请输入学生%d的成绩:\n",i+1);
        for (int j = 0; j < M; j++)
            scanf("%f",(*(p+i)+j));      
    }   
}

//第1门课的平均成绩
void first_aver(float (*p)[M])
{
    int i,j=0;
    float sum=0.0;
    printf("first_aver:");
    for(i=0;i<N;i++)
        sum=sum + *(*(p+i)+j);
    printf("%6.2f\n",sum/N);
}
//找不及格函数声明
void fail(float (*p)[M]) 
{
    int i,j;
    float sum=0.0;
    int flag=0;//存放不及格门数
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++){
            if(*(*(p+i)+j)<60)
                flag++;
            sum=sum+*(*(p+i)+j);
        }
        if(flag>2){
            printf("有两门以上课程不及格的学生:\n");
            printf("%d\n",i+1);
            printf("chengji:\n");
            for(int k=0;k<M;k++)
                printf("%.2f ",*(*(p+i)+k));
            printf("%d\n",sum/M);
        }
        flag=0;
        sum=0.0;
    }
}
//找平均成绩在90分以上或全部课程成绩在85分以上的学生函数声明
void fun(float (*p)[M])
{
    int i,j;
    float sum=0.0;
    int flag=0;//存放不及格门数
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++){
            if(*(*(p+i)+j)>85)
                flag++;
            sum=sum+*(*(p+i)+j);
        }
        if(flag==M || sum>90)
            printf("%d同学是平均成绩在90分以上或全部课程成绩在85分以上的学生\n",i+1);
        flag=0;
        sum=0.0;
    }
}
