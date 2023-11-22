/*
给出一百分制成绩,要求输出成绩等级’A’、‘B’、‘C’、‘D’、‘E’。 
90分以上为’A’,8089分为’B’,7079分为’C’ ,60~69分为’D’ ,60分以下为’E’。
*/
#include <stdio.h>
#include <stdlib.h>
/*
int main()
{
	int score;
	printf("enter score:");
	scanf_s("%d", &score);
	if (score >= 90) {
		printf("成绩等级:A\n");
	}else if (score >= 80 && score < 90) {
		printf("成绩等级:B\n");
	}else if (score >= 70 && score < 80) {
		printf("成绩等级:C\n");
	}else if (score >= 60 && score < 70) {
		printf("成绩等级:D\n");
	}else {
		printf("成绩等级:E\n");
	}
	system("pause");
	return 0;
}
*/
int main()
{
	int score;
    char ch;
	printf("enter score:");
	scanf("%d", &score);
    switch(score/10){
        case 9:ch='A';break;
        case 8:ch='B';break;
        case 7:ch='C';break;
        case 6:ch='D';break;
        default:ch='E';break;
    }
	printf("成绩等级:%c\n",ch);
	system("pause");
	return 0;
}

