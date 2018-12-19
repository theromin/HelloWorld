#include <stdio.h>
#include <stdlib.h>

typedef struct preList
{
	int num;
	struct preList *next;
}List;

void CreateList(List **head);//传地址
void read(List *head);

int main()
{
	List *p=NULL;
	CreateList(&p);
	read(p);
	system("pause");
	return 0;
}

void CreateList(List **head)
{
	int num;
	List *tail, *p;
	while (~scanf("%d", &num))
	{
		p = (List*)malloc(sizeof(List));
		p->num = num;
		p->next = NULL;
		if (*head == NULL)
			*head = p;		
		else
			tail->next = p;
		tail = p;
	}
}

/*
List *CreateList()//返回头指针
{
	int num;
	List *tail, *p;
	List *head;
	head=tail=NULL;
	while (~scanf("%d", &num))
	{
		p = (List*)malloc(sizeof(List));
		p->num = num;
		p->next = NULL;
		if(head==NULL)
			head=p;
		else
			tail->next = p;
		tail = p;
	}
	return head;
}
*/

/*
List *CreateList()//尾插法
{
	int num;
	List *head, *p;
	head=NULL;
	while (~scanf("%d", &num))
	{
		p = (List*)malloc(sizeof(List));
		p->num = num;
		p->next = head;
		head=p;
	}
	return head;
}
*/
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
