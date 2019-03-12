/*
设计函数分别求两个一元多项式的乘积与和。
输入格式:
输入分2行，每行分别先给出多项式非零项的个数，
再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。
数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。
输入样例:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
输出样例:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
*/

#include<stdio.h>
#include<stdlib.h>
 
typedef struct node *ptrNode;
typedef ptrNode LinkList;  //头结点
typedef ptrNode Position;//中间节点
typedef int ElementType;
struct node{
	ElementType Coefficient;
	ElementType Exponent;
	Position next;
};
 
int IsEmpty(LinkList L)
{
	return L->next == NULL;
}
 
LinkList creatList(int n)
{
	LinkList head,r,p;
	int coe,exp;
	head = (struct node*)malloc(sizeof(struct node));    //生成新结点
	r = head;
 
	while(n--){
        scanf("%d%d",&coe,&exp);
		p = (struct node*)malloc(sizeof(struct node));
		p->Coefficient = coe;
        p->Exponent = exp;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return head;
}
 
LinkList add_List(LinkList a, LinkList b)
{
	Position ha, hb;
	LinkList c,r,p;
	int temp;
 
	ha = a->next;
	hb = b->next;
 
	c = (struct node*)malloc(sizeof(struct node));
	r = c;
	while((ha != NULL)&&(hb != NULL)){
		p = (struct node*)malloc(sizeof(struct node));
		if(ha->Exponent < hb->Exponent){
			p->Exponent = hb->Exponent;
			p->Coefficient = hb->Coefficient;
			hb = hb->next;
            r->next = p;
            r = p;
		}
		else if(ha->Exponent > hb->Exponent){
			p->Exponent = ha->Exponent;
			p->Coefficient = ha->Coefficient;
			ha = ha->next;
            r->next = p;
            r = p;
		}
		else{
            temp = ha->Coefficient + hb->Coefficient;
            if(temp != 0){
                p->Exponent = ha->Exponent;
                p->Coefficient = temp;
                r->next = p;
                r = p;
            }
            hb = hb->next;
            ha = ha->next;
        }
	}
	if(ha == NULL){
		while(hb != NULL){
			p = (struct node*)malloc(sizeof(struct node));
			p->Exponent = hb->Exponent;
			p->Coefficient = hb->Coefficient;
			hb = hb->next;
			r->next = p;
		    r = p;
		}
	}
	if(hb == NULL){
		while(ha != NULL){
			p = (struct node*)malloc(sizeof(struct node));
			p->Exponent = ha->Exponent;
			p->Coefficient = ha->Coefficient;
			ha = ha->next;
			r->next = p;
		    r = p;
		}
	}
 
	r->next = NULL;
	return c;
}
 
 
LinkList mul_List(LinkList a, LinkList b)
{
	Position ha, hb;
	LinkList c,tempC,r,p;
	ha = a->next;
    hb = b->next;
	//c = (struct node*)malloc(sizeof(struct node));
	//c->next = NULL;
    c = creatList(0);
	if(ha == NULL || hb == NULL){
        return c;
	}
 
	while(ha != NULL ){
        tempC = (struct node*)malloc(sizeof(struct node));
        r = tempC;
        hb = b->next;
        while(hb != NULL){
            p = (struct node*)malloc(sizeof(struct node));
            p->Exponent = ha->Exponent + hb->Exponent;
            p->Coefficient = ha->Coefficient*hb->Coefficient;
			hb = hb->next;
            r->next = p;
            r = p;
        }
        r->next = NULL;
        c = add_List(c,tempC);  //?????为什么不行？结果总是第一次加后的结果
 
//        tempHead = tempC->next;
//        tempC->next = NULL;
//        while(tempHead != NULL){
//            free(tempHead);
//            tempHead = tempHead->next;
//        }
        ha = ha->next;
	}
	return c;
 
}
void printList(LinkList L)
{
	LinkList hc;
	int flag = 0;
 
	hc = L->next;
	if(hc == NULL)
		printf("0 0");
	while(hc != NULL){
		if(flag)
			printf(" ");
		else
			flag = 1;
		printf("%d %d",hc->Coefficient,hc->Exponent);
		hc = hc->next;
	}
}
 
int main(void)
{
    int n1,n2;
	LinkList L1,L2,L3,L4;
 
    scanf("%d",&n1);
	L1 = creatList(n1);
	scanf("%d",&n2);
	L2 = creatList(n2);
 
	L3 = add_List(L1,L2);
    L4 = mul_List(L1,L2);
	printList(L4);
	printf("\n");
	printList(L3);
 
	return 0;
}


/*亲手敲的错误代码
#include <stdio.h>
#include <stdlib.h>

typedef struct prepro
{
	int coe;
	int exp;
	struct prepro *next;
}pro;

pro *readp();
pro *mult(pro *p1, pro *p2);
pro *add(pro *p1, pro *p2);
void print(pro *p);
pro *bynode(pro *p1, pro *p2);

int main()
{
	pro *p1, *p2, *pp, *ps;
	p1 = readp();
	p2 = readp();
	pp = mult(p1, p2);
	print(pp);
	ps = add(p1, p2);
	print(ps);
	system("pause");
	return 0;
}

pro *readp()
{
	pro *p, *head = NULL, *tail;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		pro *p = (pro*)malloc(sizeof(pro));
		scanf("%d%d", &(p->coe), &(p->exp));
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
	}
	return head;
}

void print(pro *p)
{
	pro *k = p;
	if (!k)
		printf("0 0\n");
	else 
		while (k) 
		{
			if (k->next != NULL) 
				printf("%d %d ", k->coe, k->exp);
			else
				printf("%d %d\n", k->coe, k->exp);
			k = k->next;
		}
}

pro *add(pro *p1, pro *p2)
{
	pro *L, *head, *t1, *t2;
	L = (pro*)malloc(sizeof(pro));
	L->next = NULL;
	head = L;
	t1 = p1;
	t2 = p2;
	while (t1 != NULL && t2 != NULL) 
	{
		pro *temp = (pro*)malloc(sizeof(pro));
		temp->next = NULL;
		if (t1->exp > t2->exp)
		{
			temp->coe = t1->coe;
			temp->exp = t1->exp;
			L->next = temp;
			L = temp;
			t1 = t1->next;
		}
		else if (t1->exp < t2->exp)
		{
			temp->coe = t2->coe;
			temp->exp = t2->exp;
			L->next = temp;
			L = temp;
			t2 = t2->next;
		}
		else if (t1->exp == t2->exp) 
		{
			if ((t1->coe + t2->coe) == 0) 
			{
				t1 = t1->next;
				t2 = t2->next;
			}
			else 
			{
				temp->coe = t1->coe + t2->coe;
				temp->exp = t1->exp;
				L->next = temp;
				L = temp;
				t1 = t1->next;
				t2 = t2->next;
			}
		}
	}
	if (t1 == NULL) 
		L->next = t2;
	else if (t2 == NULL)
		L->next = t1;
	return head->next;
}

pro *mult(pro *p1, pro *p2)
{
	pro *L,*head, *t1, *t2, *temp;
	L = (pro*)malloc(sizeof(pro));
	L->next = NULL;
	head = L;
	t1 = p1;
	t2 = p2;
	if (t1 != NULL && t2 != NULL) 
	{
		temp = bynode(p1, t2);
		t2 = t2->next;
		while (t2)
		{
			pro *temp2 = bynode(p1, t2);
			temp = add(temp, temp2);
			t2 = t2->next;
		}
		L->next = temp->next;
	}
	return head->next;
}


pro *bynode(pro *p1, pro *p2) {
	pro *L, *head, *t1;
	L = (pro*)malloc(sizeof(pro));
	L->next = NULL;
	head = L;
	t1 = p1;
	while (t1) {
		pro *temp = (pro*)malloc(sizeof(pro));
		temp->next = NULL;
		temp->coe = t1->coe*p2->coe;
		temp->exp = t1->exp + p2->exp;
		L->next = temp;
		L = temp;
		t1 = t1->next;
	}
	return head;
}
*/
