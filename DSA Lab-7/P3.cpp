#include<stdio.h>
int n;
int a[200005];
int parent[200005];
int a1[200005];
int get(int x)
{
	if(parent[x]==x)
		return x;
	else return get(parent[x]);
}
int main()
{
	scanf("%d",&n);
	int root=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		parent[i]=i;
		a1[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(get(a[i])==get(i))
		{
			if(i==a[i] && !root)
				root=i;
			a[i]=0;
		}
		else
		{
			parent[get(i)]=get(a[i]);
		}
	}
	//still no root found,get that
	if(!root)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)
			{
				root=i;
				break;
			}
		}
	}
	//put the 0 element as root
	//printf("%d\n",root);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			a[i]=root;
		}
	}
	int c=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a1[i])
			c++;
	}
	printf("%d\n",c);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
}
