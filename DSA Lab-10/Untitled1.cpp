#include<stdio.h>
int q[100];int front=0,rear=0;
int n,k;
int isempty()
{
	if(front>=rear)
		return 1;
	else
		return 0;
}
void push(int x)
{
	if(isempty())
	{
		q[rear]=x;
		rear=rear+1;
		return;
	}
	int ind=-1;
	for(int i=front;i<rear;i++)
	{
		if(q[i]>=x)
			ind=i;
	}
	ind=ind+1;
	if(ind<front)
	{
		front=front-1;
		q[front]=x;
		return;
	}
	rear=rear+1;
	for(int i=rear;i>ind+1;i--)
	{
		q[i-1]=q[i-2];
	}
	q[ind]=x;
}
void pop()
{
	front=front+1;
}
int front1()
{
	return q[front];
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		push(x);
	}
	int sum=0;
	while(k--)
	{
		int m=front1();
		sum+=m;
		pop();
		push(m/2);
	}
	printf("%d ",sum);
}
