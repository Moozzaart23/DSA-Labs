#include<stdio.h>
#define min(a,b) ((a<b)?a:b)
typedef struct Car
{
	int price,tank;
}car;
car c[100005];
int n,k,s,t;
int g[100005]={0};
int g1[100005]={0};
int ans=999999999;
void sort()
{
	for(int i=0;i<k-1;i++)
	{
		for(int j=0;j<k-1-i;j++)
		{
			if(g[j]>g[j+1])
			{
				int temp=g[j];
				g[j]=g[j+1];
				g[j+1]=temp;
			}
		}
	}
}
int check(int r)
{
	for(int i=0;i<k-1;i++)
	{
		if(c[r].tank<g1[i])
			return 0;
	}
	return 1;
}
int main()
{
	scanf("%d %d %d %d",&n,&k,&s,&t);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		c[i].price=x;
		c[i].tank=y;
	}
	for(int i=1;i<=k;i++)
	{
		int x;
		scanf("%d",&x);
		g[i]=x;
	}
	k=k+1;
	g[k]=s;
	k=k+1;
	//printf("%d\n",k);
	sort();
	/*for(int i=0;i<k;i++)
	{
		printf("%d ",g[i]);
	}
	printf("\n");*/
	for(int i=0;i<k-1;i++)
	{
		g1[i]=g[i+1]-g[i];
	}
	/*for(int i=0;i<k-1;i++)
	{
		printf("%d ",g1[i]);
	}*/
	for(int i=0;i<n;i++)
	{
		int x=check(i);
		if(x==0)
			continue;
		int time=0;
		for(int j=0;j<k-1;j++)
		{
			time+=(3*g1[j]-min(2*g1[j],c[i].tank));
		}
		//printf("%d ",time);
		if(time<=t)
		{
			if(c[i].price<ans)
			{
				ans=c[i].price;
			}
		}
	}
	if(ans!=999999999)
		printf("%d ",ans);
	else
		printf("-1");
}
