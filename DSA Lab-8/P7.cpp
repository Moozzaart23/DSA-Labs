#include<stdio.h>
#include<string.h>
typedef struct Pair
{
	int x,y;
}pair;
pair s[100005];
pair s1[100005];
int n;
int a[100005];
int top=-1;
int top1=-1;
void push(int m,int n)
{
	top=top+1;
	s[top].x=m;
	s[top].y=n;
}
void pop()
{
	top=top-1;
}
pair front()
{
	return s[top];
}
int isempty()
{
	if(top<0)
		return 1;
	else
		return 0;
}
void push1(int m,int n)
{
	top1=top1+1;
	s1[top1].x=m;
	s1[top1].y=n;
}
void pop1()
{
	top1=top1-1;
}
pair front1()
{
	return s1[top1];
}
int isempty1()
{
	if(top1<0)
		return 1;
	else
		return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int left[100005];int right[100005];
	for(int i=0;i<n;i++)
	{
		int c=1;
		while(!isempty() && (front().x>a[i]))
		{
			pair d=front();
			c+=d.y;
			pop();
		}
		push(a[i],c);
		left[i]=c;
	}
	for(int i=n-1;i>=0;i--)
	{
		int c=1;
		while(!isempty1() && (front1().x>=a[i]))
		{
			pair d=front1();
			c+=d.y;
			pop1();
		}
		push1(a[i],c);
		right[i]=c;
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=(left[i]*right[i]*a[i]);
	}
	printf("%d",ans);
}
