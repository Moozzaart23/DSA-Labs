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
void pop()
{
	front=front+1;
}
int front1()
{
	return q[front];
}
int n;
int a[100005]={0};
void sort()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}
int main()
{
	int k;
	scanf("%d%d",&n,&k);
	
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&a[i]);
		//push(x);
	}
	sort();
	for(int i=0;i<n;i++)
	{
		push(a[i]);
	}
	int sum=0;
	for(int i=0;i<k;i++)
	{
		int m=front1();
		sum+=m;
		pop();
		push(m/2);
	}
	printf("%d",sum);
}
