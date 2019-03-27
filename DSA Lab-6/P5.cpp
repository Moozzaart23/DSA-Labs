#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data,ind;
	struct Node *next;
}node;
node *front=NULL;
node *front2=NULL;
void add(int x)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;
	if(front==NULL)
	{
		//temp->ind=1;
		front=temp;
	}
	else
	{
		node *trav=front;
		while(trav->next!=NULL)
		{
			trav=trav->next;
		}
		//temp->ind=(trav->ind)+1;
		trav->next=temp;
	}
}
void add2(int x)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;
	if(front2==NULL)
	{
		//temp->ind=1;
		front2=temp;
	}
	else
	{
		node *trav=front2;
		while(trav->next!=NULL)
		{
			trav=trav->next;
		}
		//temp->ind=(trav->ind)+1;
		trav->next=temp;
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
	printf("\n");
}
void print2()
{
	node *trav=front2;
	while(trav!=NULL)
	{
		printf("%d ",trav->data);
		trav=trav->next;
	}
	printf("\n");
}
void sort()
{
	node *trav=front;
	node *trav2=front2;
	while(trav!=NULL && trav2!=NULL)
	{
		if(trav->data<trav2->data)
		{
			printf("%d ",trav->data);
			trav=trav->next;
		}
		else
		{
			printf("%d ",trav2->data);
			trav2=trav2->next;
		}
	}
	if(trav!=NULL)
	{
		while(trav!=NULL)
		{
			printf("%d ",trav->data);
			trav=trav->next;
		}
	}
	if(trav2!=NULL)
	{
		while(trav2!=NULL)
		{
			printf("%d ",trav2->data);
			trav2=trav2->next;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		add(x);
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int x;
		scanf("%d",&x);
		add2(x);
	}
	//print();
	//print2();
	sort();
	return 0;
}
