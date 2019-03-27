#include<stdio.h>
int comp[10005]={0};int t=0;
int v[100005]={0};int m=0;
int a[100005]={0};
int adj[100][100];
int visited[100005]={0};
int n;
void sort()
{
	for(int i=0;i<t-1;i++)
	{
		for(int j=0;j<t-1-i;j++)
		{
			if(comp[j]>comp[j+1])
			{
				int temp=comp[j];
				comp[j]=comp[j+1];
				comp[j+1]=temp;
			}
		}
	}
}
void sort1()
{
	for(int i=0;i<m-1;i++)
	{
		for(int j=0;j<m-1-i;j++)
		{
			if(v[j]>v[j+1])
			{
				int temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
		}
	}
}
void dfs(int s)
{
	visited[s]=1;
	comp[t]=s;
	t=t+1;
	for(int i=0;i<n;i++)
	{
		if(adj[s][i] && !visited[i])
		{
			dfs(i);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&adj[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(!visited[i])
		{
			dfs(i);
			sort();
			for(int j=0;j<t;j++)
			{
				v[m++]=a[comp[j]];
			}
			sort1();
			for(int j=0;j<m;j++)
			{
				a[comp[j]]=v[j];
			}
			int comp[10005]={0};
			t=0;
			int v[100005]={0};
			m=0;
		}
	}
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
