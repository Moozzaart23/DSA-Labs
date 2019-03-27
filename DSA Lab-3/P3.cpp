#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data,ind;
	struct Node *next;
}node;
node *front=NULL;
void add(int x)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;
	if(front==NULL)
	{
		temp->ind=1;
		front=temp;
	}
	else
	{
		node *trav=front;
		while(trav->next!=NULL)
		{
			trav=trav->next;
		}
		temp->ind=(trav->ind)+1;
		trav->next=temp;
	}
}
void pro(int k)
{
	if(k==1)
	{
		return ;
	}
	node *trav=front,*end=NULL,*start=front;
	node *temp=(node *)malloc(sizeof(node));
	temp->data=-1;
	temp->ind=-1;
	temp->next=NULL;
	while(start!=end)
	{
		trav=start;
		temp->data=start->data;
		temp->ind=start->ind;
		while(trav->next!=end)
		{
			trav->data=trav->next->data;
			trav->ind=trav->next->ind;
			trav=trav->next;
		}
		trav->data=temp->data;
		trav->ind=temp->ind;
		end=trav;
		if((start->ind)%k==0)
		{
			start=start->next;
		}
	}
}
void print()
{
	node *trav=front;
	while(trav!=NULL)
	{
		printf("%d ",trav->data);
		trav=trav->next;
	}
}
int main()
{
	int k;
	scanf("%d",&k);
	int x;
	while(1)
	{
		scanf("%d",&x);
		if(x==-1)
			break;
		else
			add(x);
	}
	pro(k);
	print();
	return 0;
}
