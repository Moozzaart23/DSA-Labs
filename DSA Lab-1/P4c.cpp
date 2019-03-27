#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
}node;
void traverse(node *headref)
{
	node *start=(headref);
	while(start->next!=(headref))
	{
		printf("%d->",start->data);
		start=start->next;
	}
	printf("%d\n",start->data);
}
void insertAtEnd(node **headref,int x)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=x;
	if(*headref==NULL)
	{
		*headref=temp;
		temp->next=(*headref);
		return;
	}
	node *lastnode=(*headref);
	while(lastnode->next!=(*headref))
	{
		lastnode=lastnode->next;
	}
	lastnode->next=temp;
	temp->next=(*headref);
}
void end(node *headref,int x)
{
	node *start=headref;
	node *nex=headref;
	int k=0;
	while(start->next!=headref && k<x)
	{
		start=start->next;
		k++;
	}
	if(k<x)
		printf("Less Nodes");
	else
		printf("%d\n",start->data);
}
int main()
{
	int n;
	scanf("%d",&n);
	node *head=NULL;
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		insertAtEnd(&head,x);
	}
	traverse(head);
	int a;
	scanf("%d",&a);
	end(head,a);
}
