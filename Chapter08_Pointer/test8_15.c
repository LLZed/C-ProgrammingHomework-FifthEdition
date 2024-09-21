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
    char number[4][10];     //存放学号
    void inputscore(float (*p)[M],char (*num)[10]);           //输入函数声明
    void inputcourse(char (*p)[20]);           //输入函数声明
    void first_aver(float (*p)[M]);    //第1门成绩平均分函数声明
    void fail(float (*p)[M],char (*num)[10]);         //找不及格函数声明
    void fun(float (*p)[M],char (*num)[10]);     //找平均成绩在90分以上或全部课程成绩在85分以上的学生函数声明
    char course[5][20]; //存放课程名

    inputcourse(course);            //函数调用
    inputscore(score,number);            //函数调用
    printf("\nNumber.      %s        %s         %s          %s        %s\n",course[0],course[1],course[2],course[3],course[4]);//输出课程成绩
    for(int i=0;i<N;i++)            //4个学生
    {
        printf("\n  %s  ", number[i]);        //输出学号
		for (int j = 0; j < M; j++)             //5门课程
			printf("   %6.2f   ",score[i][j]);    //输出每个学生的每门课程成绩
	}
    printf("\n------------------------------------------------------\n");
    first_aver(score);     //函数调用
    fail(score,number);        //函数调用
    fun(score,number);

    system("pause");
    return 0;
}
//输入课程
void inputcourse(char (*p)[20]){
    int i;
    printf("输入课程：");
    for(i=0;i<M;i++)
        scanf("%s",p[i]);    
}
//输入成绩
void inputscore(float (*p)[M],char (*num)[10])
{
    for(int i=0;i<N;i++)
    {   
        printf("请输入学生%d的学号:\n",i+1);
        scanf("%s",num[i]);
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
void fail(float (*p)[M],char (*num)[10]) 
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
            printf("\n有两门以上课程不及格的学生:\n");
            printf("%s\n",num[i]);
            printf("chengji:");
            for(int k=0;k<M;k++)
                printf("%.2f ",*(*(p+i)+k));
            printf("\n平均成绩:%6.2f",sum/M);
        }
        flag=0;
        sum=0.0;
    }
}
//找平均成绩在90分以上或全部课程成绩在85分以上的学生函数声明
void fun(float (*p)[M],char (*num)[10])
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
        if(flag==M || (sum/M)>90)
            printf("\n%s同学是平均成绩在90分以上或全部课程成绩在85分以上的学生\n",num[i]);
        flag=0;
        sum=0.0;
    }
}

