/*
10.已有a,b两个链表,每个链表中的结点包括学号、成绩。要求把两个链表合并, 按学号升序排列。
解题思路：
首先合并两个链表，然后采用选择排序，给合并之后的链表进行排序。
*/

#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct student)      //定义LEN的值为结构体的长度

struct student                          //定义一个结构体类型struct student，有三个成员
{
    long num;                           //学号（长整型）
    float score;                        //成绩（浮点型）
    struct student *next;               //指向结构体类型数据的指针变量成员next（指针类型的成员，它指向结构体类型数据，就是它所在的结构体类型）
};                           

int n,sum=0;                            //定义全局变量
int main()
{
    //函数声明
    struct student *creat(void);
    void print(struct student *head);
    struct student *merge(struct student *a, struct student *b);

    struct student *ahead,*bhead;                       //定义两个结构体变量
    printf("input list a:\n");
    ahead=creat();
    sum+=n;
    print(ahead);

    printf("\ninput list b:\n");
    bhead=creat();
    sum+=n;
    print(bhead);
    struct student *combine = merge(ahead, bhead);      //调用函数合并链表并且排序
    //遍历链表输出所有成员
    printf("\nThere are %d records:\n",sum);
    while (combine != NULL)
    {
        printf("%d  %.2lf\n", combine->num, combine->score);
        combine = combine->next;
    }
    system("pause");
    return 0;
}

//creat函数创建动态链表
struct student *creat(void)				    //定义函数，此函数返回一个指向链表头的指针
{
	struct student * head;				    //指向结构体类型数据的指针变量head，它可以指向结构体变量也可以指向结构体数组中的元素
	struct student * p1,*p2;			    //指向结构体类型数据的指针变量p1和p2
	n=0;
	p1=p2=(struct student * )malloc(LEN);	//开辟一个结构体类型的新单元,并使p1和p2指向新单元
	printf("请输入学生学号和成绩（逗号隔开）：\n(若输入0,0表示结束)\n");
	scanf("%ld,%f",&p1->num,&p1->score);	//输入第1个学生的学号和成绩
	head=NULL;								//此时head的值为空，不指向任何；
	while(p1->num!=0)						//当输入的学号不为零时,则输入的是第1个结点的数据
	{
		n=n+1;								//n为结点1的标记
		if(n==1)							//当n为1时表示此时是结点1，要把结点的地址给到head，使head指向结点1
			head=p1;						//把p1的值赋给head，即使head指向新开辟的结点，p1所指向的新开辟的结点就成为链表中第1个结点
		else 
            p2->next=p1;					//将p1的值赋给p2->next
		p2=p1;								//在连接好两个结点后，使p2也指向新结点，为下次连接做准备
		p1=(struct student *)malloc(LEN);	//开辟动态存储区，把起始地址赋给p1
		scanf("%ld,%f",&p1->num,&p1->score);//输入其他学生的学号和成绩
	}
	p2->next=NULL;							//开辟完后使p2不指向任何结点
	return head;							//返回链表头地址；
}

struct student *merge(struct student *a, struct student *b)
{
    //先把链表a和链表b合并
    struct student *head = a;   //用链表a的首结点做头结点
    while (a->next != NULL)
    {
        a = a->next;
    }
    a->next = b;
	//选择排序，每次选最小的，放在未排序的链表头部
    struct student *pre;        //定义一个结构体变量
    pre = head;                 //使pre指向head
    while (pre->next != NULL)   //当pre的next指向不是空时
    {
        a = pre->next;          //使a指向下一个结点  
        while (a != NULL)       //如果下一结点不是空
        {
            if (pre->num > a->num)  //比较pre指向的当前结点和a指向的结点
            {
                //交换两个结点的数据
                int num = pre->num;
                double score = pre->score;
                pre->num = a->num;
                pre->score = a->score;
                a->num = num;
                a->score = score;
            }
            a = a->next;    
        }
        pre = pre->next;
    }
    return head;
}

//输出链表函数
void print(struct student *head){
	struct student *p;
	printf("\nNow these records are:\n");
	p=head;
	if(head != NULL)
		do{
			printf("%ld %5.1f\n", p -> num,p -> score);
			p=p->next;
		}while(p != NULL);
} 

/*
//另一种合并方法
struct student * merge2(struct student *ah,struct student *bh)
{
    struct student *pa1,*pa2,*pb1,*pb2;
    pa2=pa1=ah;
    pb2=pb1=bh;
    do{
        while((pb1->num > pa1->num)&&(pa1->next != NULL))   //当链表b当前结点的num值比链表a当前结点的num值大且pa1指向的结点的next值不为空
        {
            pa2=pa1;            //使pa2指向pa1
            pa1=pa1->next;      //pa1指向下一个结点
        }
        if(pb1->num <= pa1->num)
        {
            if(ah==pa1)     //如果是首结点
                ah=pb1;     //把pb1作为首结点
            else
                pa2->next=pb1;  //把pb1结点接到pa1的上一个结点
            pb1=pb1->next;      //使pb1指向下一个结点
            pb2->next=pa1;      //使pb1上次指向的结点接到pa1
            pa2=pb2;            
            pb2=pb1;  
        }
    }while((pa1->next!=NULL)||(pa1==NULL && pb1!=NULL));
    //如果是链表b接到链表a最后一个结点
    if((pb1!=NULL) && (pb1->num > pa1->num) && (pa1->next==NULL))
        pa1->next=pb1;
    return ah;
}
*/
