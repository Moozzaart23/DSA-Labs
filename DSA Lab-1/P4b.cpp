#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
}node;
void traverse(node *headref)
{
	node *start=headref;
	while(start!=NULL)
	{
		printf("%d->",start->data);
		start=start->next;
	}
	printf("\n");
}
void insertAtEnd(node **headref,int x)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;
	
	if(*headref==NULL)
	{
		temp->prev=NULL;
		*headref=temp;
	}
		
	else
	{
		node *lastnode=*headref;
		while(lastnode->next!=NULL)
		{
			lastnode=lastnode->next;
		}
		lastnode->next=temp;
		temp->prev=lastnode;
	}
}
void end(node *headref,int k)
{
	node *prevnode=headref;
	node *lastnode=headref;
	for(int i=1;i<k;i++)
	{
		//printf("\n lol");
		lastnode=lastnode->next;
		if(lastnode==NULL)
		{
			printf("There are less elements \n");
			return;
		}
	}
	while(lastnode->next!=NULL)
	{
		prevnode=prevnode->next;
		lastnode=lastnode->next;
	}
	printf("%d \n",prevnode->data);
}
int main()
{
	int n;
	node *head=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		insertAtEnd(&head,x);
	}
	traverse(head);
	end(head,3);
}
