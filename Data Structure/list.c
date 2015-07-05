// 单向链表的建立，删除，插入，倒序

#include <stdio.h>
#include <malloc.h>
#include "list.h"

Node *creatList(int num)
{
	Node *p,*r,*H;
	int i;

	H = (Node*)malloc(sizeof(Node));
	r = H;
	if(H == NULL)
	{
		return NULL;
	}

	for(i = 0;i < num;i++)
	{
		p = (Node*)malloc(sizeof(Node));
		r->next = p;
		r = p;
		p->data = 100+i;
		
	}

	r->next = NULL;

	return H;
}

void showList(Node *h)
{
	Node *p = h->next;

	while(p)
	{
		printf("%d\n",p->data);
		p = p->next;
	}
}

void destroy(Node *h)
{
	Node *p = h;
	while(p->next)
	{
		delList(h,1);
		//showList(h);
		
	}

	free(p);
}

int getListLen(Node *h)
{
	Node *p = h->next;
	int n=0;

	while(p)
	{
		p = p->next;

		n++;
	}

	return n;
}


void insertList(Node *h,int data,int pos)
{
	int i;
	Node *p = h,*q;
	int len = getListLen(h);
	//printf("len=%d\n",len);
		
	if (pos > len)
	{
		pos = len;
	}
	
	for(i=0;i<pos;i++)
	{
		p=p->next;
	}

	q = (Node*)malloc(sizeof(Node));

	q->data = data;

	q->next = p->next;

	p->next = q;
}


void delList(Node *h,int pos)
{
	int i;
	Node *p = h,*q;
	int len = getListLen(h);
	//printf("len=%d\n",len);
		
	if (pos > len)
	{
		pos = len;
	}
	
	for(i=0;i<pos-1;i++)
	{
		p=p->next;
	}


	q = p->next;

	p->next = q->next;

	free(q);
}

void reverse(Node *h) // 插入倒序
{
	Node *p,*q;
	p = h->next;
	h->next = NULL;

	while (p)
	{
		q = p;
		p = p->next;
		q->next = h->next;
		h->next = q;
	}
}


int main()
{
	Node *head;

	head = creatList(5);

	//showList(head);

	insertList(head,1000,10);

	insertList(head,1002,2);

	insertList(head,1004,4);

	insertList(head,1008,120);

	showList(head);

	printf("--------------------\n");
	delList(head, 2);
	delList(head, 5);
	delList(head, 20);
	showList(head);
	printf("--------------------\n");

	reverse(head);
	showList(head);

	
	printf("--------------------\n");
	destroy(head);

	return 0;
}

