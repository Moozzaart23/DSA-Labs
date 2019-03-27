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

void search(node *headref,int srch)
{
	int c=1;
	printf("The element %d is found in positions ",srch);
	while(headref!=NULL)
	{
		if(headref->data==srch)
		{
			printf("%d, ",c);
			ct[t++]=c;
		}
		headref=headref->next;
		c++;
	}
	printf("\n");
}

void Delete(node **headref,int b)
{
	node *temp;node *start=*headref;node *dup;
	while(start!=NULL && start->next!=NULL)
	{
		if(start->data==b)
		{
			temp=start;
			while(temp->next!=NULL)
			{
				if(start->data==temp->next->data)
				{
					dup=temp->next;
					temp->next=temp->next->next;
					free(dup);
					
				}
				else
				   temp=temp->next;
			}
			break;
		}
		start=start->next;
	}
}


void swap(node *headref,int b)
{
	node *start=headref;
	node *start2=headref->next;
	while(start->next->data!=b)
	{
		start=start->next;
		start2=start2->next;
	}
	int x=start->data;
	start->data=start2->data;
	start2->data=x;
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
	search(head,a);
	Delete(&head,a);
	traverse(head);
	swap(head,a);
	traverse(head);
	
}
