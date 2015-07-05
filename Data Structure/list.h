#ifndef _LIST_H
#define _LIST_H

typedef struct node
{
	int data;
	struct node *next;
}Node;

Node *creatList(int num);
void showList(Node *h);
void insertList(Node *h,int data,int pos);
void delList(Node *h,int pos);
void reverse(Node *h);
void destroy(Node *h);

#endif
