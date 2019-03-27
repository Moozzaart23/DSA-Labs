#include<stdio.h>
typedef struct Node
{
	int data,vis;
}node;
node a[100005];
int n,m;
int b[100005];
int c[100005];
int t=0;
void sort()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j].data>a[j+1].data)
			{
				int temp=a[j].data;
				a[j].data=a[j+1].data;
				a[j+1].data=temp;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		a[i].data=x;
		a[i].vis=0;
	}
	for(int i=0;i<m;i++)
		scanf("%d",&b[i]);
	sort();
	for(int i=0;i<m;i++)
	{
		int x=b[i];
		for(int j=0;j<n;j++)
		{
			if(a[j].data==x)
			{
				c[t++]=x;
				a[j].vis=1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(a[i].vis==0)
		{
			c[t++]=a[i].data;
			a[i].vis=1;
		}
	}
	for(int i=0;i<t;i++)
	{
		printf("%d ",c[i]);
	}
}
