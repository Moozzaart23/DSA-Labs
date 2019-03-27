#include<stdio.h>
int s[100005];
int top=-1;
int n,m;
int adj[100][100];
int adj1[100][100];
int c[100005];
int vis[100005]={0};
int minn=1;int mincnt=1;
int cc=0;
int ans=0;
void push(int x)
{
	s[++top]=x;
}
void pop()
{
	top=top-1;
}
int front2()
{
	return s[top];
}
int isempty()
{
	if(top<0)
		return true;
	else
		return false;
}
void dfs1(int s)
{
	vis[s]=1;
	for(int i=0;i<n;i++)
	{
		if(!vis[i] && adj[s][i])
			dfs1(i);
	}
	push(s);
}
void dfs2(int s)
{
	if(c[s]<minn)
	{
		minn=c[s];
		mincnt=1;
	}
	else if(c[s]==minn && !vis[s])
	{
		mincnt++;
	}
	vis[s]=1;
	for(int i=0;i<n;i++)
	{
		if(!vis[i] && adj1[s][i])
			dfs2(i);
	}
}
int main()
{
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			adj[i][j]=0;
			adj1[i][j]=0;
		}
	}
	scanf("%d",&m);
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x-1][y-1]=1;
		adj1[y-1][x-1]=1;
	}
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			dfs1(i);
		}
	}
	for(int i=0;i<n;i++)
		vis[i]=0;
	int ways=1;
	while(!isempty())
	{
		int top=front2();
		pop();
		if(!vis[top])
		{
			vis[top]=1;
			minn=c[top];
			mincnt=1;
			dfs2(top);
			ans+=minn;
			ways*=mincnt;
			cc++;
		}
	}
	printf("%d %d",ans,ways);
}
