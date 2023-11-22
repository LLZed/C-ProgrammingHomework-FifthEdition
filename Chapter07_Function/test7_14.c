/************************************************************
输入10个学生5门课的成绩,分别用函数实现下列功能:
①计算每个学生的平均分;
②计算每门课的平均分;
③找出所有50个分数中最高的分数所对应的学生和课程;
④计算平均分方差:（公式看书上）
*************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 5
float score[N][M];
int r,c;
float a_student[N],a_cour[M];//10个学生平均成绩，5门课平均成绩
int main()
{
    int i,j;
    float h;
    void input();           //输入函数声明
    void aver_student();    //学生平均成绩函数声明
    void aver_cour();       //课程平均成绩函数声明
    float highest();        //最好成绩函数声明
    float s_var();          //计算平均分方差函数声明
    input();            //函数调用
    aver_student();     //函数调用
    aver_cour();        //函数调用
    printf("\n NO.   cour1    cour2    cour3    cour4    cour5    aver\n");//输出课程成绩和平均分
    for(i=0;i<N;i++)            //十个学生
    {
        printf("\n NO %2d ", i + 1);        //输出是第几个学生
		for (j = 0; j < M; j++)             //5门课程
			printf("%8.2f",score[i][j]);    //输出每个学生的每门课程成绩
		printf("%8.2f\n", a_student[i]);    //输出每个学5门生课程成绩平均分
	}
	printf("\naverage:");                  //输出每门课的平均分
	for (j = 0; j < M; j++)
		printf("%8.2f", a_cour[j]);
	printf("\n");
	h = highest();
	printf("highest:%7.2f   NO. %2d   course %2d\n", h, r, c);
	printf("variance %8.2f\n", s_var());
    system("pause");
    return 0;
}

//输入成绩
void input()
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("请输入学生%2d成绩:\n",i+1);
        for (int j = 0; j < M; j++)
            scanf("%f",&score[i][j]);      
    }   
}
//计算10个学生的平均成绩
void aver_student()
{
    int i,j;
    float s;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
            s=s+score[i][j];
        a_student[i]=s/5.0;
    }
}
//计算5门课的平均分
void aver_cour()
{
    int i,j;
    float s;
    for(j=0;j<M;j++)
    {
        s=0;
        for(i=0;i<N;++i)
            s=s+score[i][j];
            a_cour[j]=s/(float)N;
    }
}
//找出最高分数及对应的学生和课程
float highest()
{
    float high;
    int i,j;
    high=score[0][0];
    for(i=0;i<M;i++)
        for (j = 0; j < M; ++j)
            if(score[i][j]>high)
            {
                high=score[i][j];
                r=i+1;//数组行号i从0开始，学生号r从1开始，故i+1
                c=j+1;
            }      
    return high;
}
//计算方差
float s_var()
{
    int i;
    float sumx,sumxn;
    sumx=0.0;
    sumxn=0.0;
    for ( i = 0; i < N; i++)
    {
        sumx+=a_student[i]*a_student[i];
        sumxn+=a_student[i];
    }
    return (sumx/N-(sumxn/N)*(sumxn/N));
}