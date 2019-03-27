#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int data;
	struct Node *next;
}node;
int ct[100005]={0};int t=0;
void traverse(node *headref)
{
	while(headref!=NULL)
	{
		printf("%d-> ",headref->data);
		headref=headref->next;
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
	}
}
void end(node *headref,int k)
{
	//node *prevnode=headref;
	node *lastnode=headref;
	/*for(int i=1;i<k;i++)
	{
		lastnode=lastnode->next;
		if(lastnode==NULL)
		{
			printf("There are less elements \n");
			return;
		}
	}*/
	/*while(lastnode->next!=NULL)
	{
		prevnode=prevnode->next;
		lastnode=lastnode->next;
	}
	printf("%d \n",prevnode->data);*/
	int x=0;
	while(lastnode->next!=NULL && x<k)
	{
		//prevnode=prevnode->next;
		lastnode=lastnode->next;
		x++;
	}
	if(x<k)
		printf("Less Nodes");
	else
		printf("%d\n",lastnode->data);
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
