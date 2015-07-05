#ifndef _DLIST_H
#define _DLIST_H

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}Node;

Node *dcreatList(int num);

void dshowList(Node *h);

void dinsertList(Node *h,int data,int pos);

void ddelList(Node *h,int pos);

void dreverse(Node *h);

void destroy(Node *h);

#endif
