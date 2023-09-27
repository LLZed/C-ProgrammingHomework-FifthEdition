#include <stdio.h>
#include <stdlib.h>
int main(){
	struct student {
	int num;
	char name[10];
	float score;} 
s[5]={{1,"lili",98.5},{9,"xiaohua",66}},*p=s;
printf("%d,%s,%f\n",s->num,s->name,s->score);
printf("%d\n",*p++);
printf("%d\n",(p++)->num);
system("pause");
return 0;
}