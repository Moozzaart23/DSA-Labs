#include<stdio.h>
int q[10005];
int front=0;
int rear=0;
int isempty()
{
	if(front>=rear)
		return 1;
	else
		return 0;
}
void push(int k)
{
	if(isempty())
	{
		q[rear]=k;
		//printf("lol\n");
		rear=rear+1;
		return;
	}
	int ind=-1;
	//printf("woof");
	for(int i=front;i<rear;i++)
	{
		if(q[i]>=k)
			ind=i;
	}
	ind=ind+1;
	if(ind<front)
	{
		front=front-1;
		q[front]=k;
		return;
	}
	rear=rear+1;
	for(int i=rear;i>ind+1;i--)
	{
		q[i-1]=q[i-2];
	}
	q[ind]=k;
	return;
}
void ch()
{
	//printf("Here\n");
	if(isempty())
	{
		printf("-1\n");
		return;
	}
	int i=0;
	for(i=front;i<rear;i++)
	{
		if(q[i]!=q[i+1])
			break;
	}
	printf("%d\n",i+1);
	return;
}
void cl()
{
	if(isempty())
	{
		printf("-1\n");
		return;
	}
	int i=0;
	for(i=rear;i>=front;i--)
	{
		if(q[i]!=q[i-1])
			break;
	}
	printf("%d\n",(rear-front-i+1));
	return;
}
void diff()
{
	if(isempty())
	{
		printf("-1\n");
		return;
	}
	if(q[front]==q[rear-1])
	{
		//printf("Equal= %d %d\n",front,rear);
		printf("0\n");
		front=front+1;
		return;
	}
	//printf("Equal= %d %d\n",q[front],q[rear-1]);
	printf("%d\n",q[front]-q[rear-1]);
	front=front+1;
	rear=rear-1;
	return;
}
int main()
{
	int qq;
	scanf("%d",&qq);
	for(int i=0;i<qq;i++)
	{
		char s[10005];
		scanf("%s",&s);
		if(s[0]=='P')
		{
			int x;
			scanf("%d",&x);
			push(x);
		}
		else if(s[0]=='C' && s[5]=='H')
		{
			ch();
		}
		else if(s[0]=='C' && s[5]=='L')
		{
			cl();
		}
		else
		{
			diff();
		}
	}
	/*for(int i=front;i<rear;i++)
		printf("%d ",q[i]);*/
}
