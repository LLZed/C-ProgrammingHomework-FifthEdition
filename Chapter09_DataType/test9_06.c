//13人围成一圈，从第1个人开始顺序报数1，2，3.凡是报到3的退出圈子。找到最后留在圈子里的人是原来的几号。要求用链表实现。（在第八章第5题用的是指针实现）
//思路：创建一个环形链表，给链表中的每一个节点从1~13编号，然后开始淘汰过程，对于淘汰的节点，序号置为0，淘汰完成之后，找到序号不为0的即为最后留下的。
#include<stdio.h>
#include<stdlib.h>
#define N 13                        //宏定义一个全局变量N，宏展开为13

struct people                       //声明一个结构体类型struct people              
{
    int number;                     //成员，用来存放一开始的顺序号
    struct people *next;            //成员，指向结构体类型的指针，用于链表结点链接
};

int main()                                  
{
    struct people link[N],*head;   //定义结构体数组和结构体指针变量                                      
    head=link;                     //将第一个结点的起始地址赋给head指针,让head 指向link[0]
//按顺序排号,1~13编号 
    for(int i=0;i<N;i++)
    {
        link[i].number=i+1;       //从1到13编号
		if(i == N-1)
			link[N-1].next=link;          //使最后一个结点指向第1个结点，形成环链，即最后一个回到第一个结点
		else  
        	link[i].next=&link[i+1];   //使结点指向下一个结点，把结点连接起来                
    }

    int count=N;
    int i = 1;
	while (count > 1)			//当剩余的人数超过一个时，执行循环
	{  
		//如果找到第3个了就淘汰，赋0表示淘汰该结点
		if (i == 3)
		{
            //被淘汰的节点，number置为0
			printf("第 %d 位置被淘汰\n", head->number);
			head->number = 0;
			count--;
		}
		head = head->next;	//使head指向下一个结点。head->next在程序开始，就是指向的链表首节点。而在循环遍历的时候，利用head=head->next,依次指向每一个节点。
		i++;				//从1开始报数
		//报超过3了就重新报数
		if (i > 3){
			i = 1;
		}
	}

	printf("--------------\n");
	while (head->number == 0)
	{
        //非0节点即为最后留下的
		head = head->next;		//使head指向下一个结点
		if (head->number != 0)
		{
			printf("留到最后的是 %d \n", head->number);
			break;
		}
	}
	system("pause");
	return 0;  
}


