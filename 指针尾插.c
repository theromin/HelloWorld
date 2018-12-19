/*
键盘输入若干个整数（键盘 ^Z结束输入），按照输入顺序创建链表。

链表创建完成后，依序访问链表每个结点并输出各结点数据值及该结点的地址。

注意：可实现两种情形的链表：

a.不带附加头结点的单链表。

b. 带附加头结点的单链表。
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct preList
{
	int num;
	struct preList *next;
}List;

void CreateList(List **head);//传地址
//List *CreateList();//返回头指针
void read(List *head);

int main()
{
	//List *head=NULL;
	List *p=NULL;
	//head=CreateList();
	CreateList(&p);
	//read(head);
	read(p);
	system("pause");
	return 0;
}

void CreateList(List **head)
{
	int num;
	List *tail, *p;
	//List *head;
	//head=tail=NULL;
	while (~scanf("%d", &num))
	{
		p = (List*)malloc(sizeof(List));
		p->num = num;
		p->next = NULL;
		//if(head==NULL)
		//	head=p;
		if (*head == NULL)
			*head = p;		
		else
			tail->next = p;
		tail = p;
	}
	//return head;
}

void read(List *head)
{
	List *p = head;
	if (head == NULL)return;
	do
	{
		printf("%d %x\n", p->num, &p->num);
		p = p->next;
	} while (p!= NULL);
}
