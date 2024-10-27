/*
7.动态链表的学习，在第9章例9.9和例9.10的基础上,写一个函数del,用来删除动态链表中指定的节点,也就是写一个函数建立有3名学生数据的单向动态链表,
详见《C语言程序设计》P312,并加上一个del函数用于删除指定链表结点。
思路：从一个动态链表中删除某个结点并不是真正的从内存中把它抹除，而是从链表中分离开来，只要撤销原来的链接关系即可，可以用学号做节点标识，
输入学号，找到学号对应的需要删除的节点，把待删除节点的前驱和后继重新链接。

*/

*/

#include <stdio.h>
#include <stdlib.h>		//包含malloc函数，system函数等
#define LEN sizeof(struct Student)		    //定义LEN的值为结构体的长度

struct Student							    //定义一个结构体类型，有三个成员
{
	long num;							    //学号（长整型）
 	float score;						    //成绩（浮点型）
 	struct Student * next;				    //指向结构体类型数据的指针变量成员next（指针类型的成员，它指向结构体类型数据，就是它所在的结构体类型）
};
    
int n;									    //全局变量n

//写一个creat函数创建动态链表
struct Student *creat(void)				    //定义函数，此函数返回一个指向链表头的指针
{
	struct Student * head;				    //指向结构体类型数据的指针变量head，它可以指向结构体变量也可以指向结构体数组中的元素
	struct Student * p1,* p2;			    //指向结构体类型数据的指针变量p1和p2
	n=0;
	p1=p2=(struct Student * )malloc(LEN);	//开辟一个结构体类型的新单元,并使p1和p2指向新单元
	printf("请输入学生学号和成绩（逗号隔开）：\n(若输入0,0表示结束)\n");
	scanf("%ld,%f",&p1->num,&p1->score);	// 输入第1个学生的学号和成绩
	head=NULL;								//此时head的值为空，不指向任何地址；
	while(p1->num != 0)						//当输入的学号不为零时,则输入的是第1个结点的数据
	{
		n=n+1;								//n为结点1的标记
		if(n==1)							//当n为1时表示此时是结点1，要把结点的地址给到head，使head指向结点1
			head=p1;						//把p1的值赋给head，即使head指向新开辟的结点，p1所指向的新开辟的结点就成为链表中第1个结点
		else 
			p2->next=p1;					//当不是首节点时将p1的值赋给p2->next
		p2=p1;								//在连接好两个结点后，使p2也指向新结点，为下次连接做准备
		p1=(struct Student *)malloc(LEN);	//开辟动态存储区，把起始地址赋给p1
		scanf("%ld,%f",&p1->num,&p1->score);// 输入其他学生的学号和成绩
	}
	p2->next=NULL;							//开辟完输入完数据后使p2不指向任何结点，此时已经创建好一个有数据的动态链表
	return head;							//返回链表头地址；
}

//写一个del函数删除链表中指定的结点,可以用学号作为要删除的结点的标志
struct Student * del(struct Student *p,long num)
{
    struct Student *p1,*p2;			         //指向结构体类型数据的指针变量p1和p2
    if(p == NULL)							 //如果是空表的话
    {
        printf("\nlist null\n");
        return p;
    }
    p1=p;                                   //使p1指向第1个结点
    while (num!=p1->num && p1->next!=NULL)	//当p1的num成员不等于要删除的num而且不是空表，即p1指向的不是所要找的结点且后面还有结点时
    {
        p2=p1;							//p2指向当前p1指向的结点
		p1=p1->next;					//p1后移一个结点，指向下一个结点
    }//执行完这段p2指向的始终是p1所指向结点的前一个结点
    if(num==p1->num)						//当p1的num成员等于要删除的num，找到了
    {
    	if(p1==p)								//如果p1此时指向的是首结点										
        	p=p1->next;							//把第二个结点的地址赋给p
    	else 
        	p2->next=p1->next;					//否则将下一个结点地址赋给前一个结点地址变量
    	printf("delete:%ld\n",num);
    	n=n-1;									//结点数-1
    }
    else 
		printf("%ld not been found!\n",num);  //找不到该结点
	return p;
}

//写一个main函数调用这个creat函数
int main()
{
	struct Student *pt,*pt1;					            //定义结构体指针变量；
    long number;
	pt1=pt=creat();								            //调用函数，函数返回所创建的链表的第1个结点的地址，用两个指向
	while(pt!=NULL)							                //依次输出各结点的数据
	{
		printf("\nnum:%ld\nscore:%5.1f\n",pt->num,pt->score);
		pt=pt->next;                                        //使结点指向下一个结点
	}
                                                     
    printf("what is num you want delete:\n");
    scanf("%ld",&number);									//输入想要删除的数据
    pt1 = del(pt1,number);									//调用函数删除数据
    
	while(pt1!=NULL)							            //依次输出删除后各结点的数据
	{
		printf("\nnum:%ld\nscore:%5.1f\n",pt1->num,pt1->score);
		pt1=pt1->next;
	}

    system("pause");
	return 0;
}
