#include<stdio.h>
typedef struct Pair
{
	int c;
	int f;
}pair;
pair a[10005];
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
void sort()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j].c>a[j+1].c)
			{
				int temp=a[j].c;
				a[j].c=a[j+1].c;
				a[j+1].c=temp;
				int tempp=a[j].f;
				a[j].f=a[j+1].f;
				a[j+1].f=tempp;
			}
			else if(a[j].c==a[j+1].c && a[j].f>a[j+1].f)
			{
				int tempp=a[j].f;
				a[j].f=a[j+1].f;
				a[j+1].f=tempp;
			}
		}
	}
}
int main()
{
	int k,w;
	scanf("%d%d%d",&k,&w,&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].f);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].c);
	}
	sort();
	for(int i=0;i<n;i++)
		printf("%d %d\n",a[i].c,a[i].f);
	int j=0;
	for(int i=0;i<k;i++)
	{
		while(j<n&& a[j].c<=w)
		{
			push(a[j].f);
			j++;
		}
		if(isempty())
		{
			printf("%d",i);
			return 0;
		}
		w+=front1();
		pop();
	}
	printf("%d",w);
}
