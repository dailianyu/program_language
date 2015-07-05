// 双向链表的，创建，插入，删除，倒序

#include <stdio.h>
#include <malloc.h>

#include "dlist.h"

Node *dcreatList(int num)
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
		p->prev = r;//add 1
		r = p;
		p->data = 100+i;
	}

	r->next = NULL;

	return H;
}

void dshowList(Node *h)
{
	Node *p = h->next;

	while(p)
	{
		printf("%d\n",p->data);
		p = p->next;
	}
}

void dshowList2(Node *h)
{
	Node *p = h;

	while(p->next)
	{
		p = p->next;
	}

	while(p!=h)
	{
		printf("%d\n",p->data);
		p = p->prev;
	}
}

void destroy(Node *h)
{
	Node *p = h;
	while(p->next)
	{
		ddelList(h,1);
		//dshowList(h);
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

void dinsertList(Node *h,int data,int pos)
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

	if (p->next)
	{
		p->next->prev = q;  // add
	}
	

	p->next = q;

	q->prev = p;   // add
}

void ddelList(Node *h,int pos)
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

	p->prev->next = p->next;
	if(p->next)
	{
		p->next->prev = p->prev;
	}
	free(p);
}

void dreverse(Node *h) // 插入倒序
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

		q->prev = h;
		if (q->next)
		q->next->prev = q;
	}
}

int main()
{
	Node *head;

	head = dcreatList(5);

	dshowList(head);

//	dshowList2(head);

	printf("--------------------\n");

	dinsertList(head,1000,10);

	dinsertList(head,1002,2);

	dinsertList(head,1004,4);

	dinsertList(head,1008,120);

	dshowList(head);


	printf("--------------------\n");
	ddelList(head, 2);
	ddelList(head, 5);
	ddelList(head, 20);
	dshowList(head);
	printf("+++++++++++++++++++++\n");
#if 1
        dreverse(head);
	dshowList(head);
	dshowList2(head);
#endif
        printf("--------------------\n");
	destroy(head);

	return 0;
}

