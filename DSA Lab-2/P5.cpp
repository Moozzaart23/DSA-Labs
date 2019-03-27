#include<stdio.h>
#include<math.h>
int visited[100005]={0};
int adj[10000][10000];
int f[100005]={0};
int d;
int x[100005];int t=0;
int y[100005]={0};int m=0;
int nodes;int edges=0;
void dfs(int s)
{
	printf("%d ",s+1);
	x[t++]=(s+1);
	visited[s]=1;
	for(int i=0;i<nodes;i++)
	{
		if(visited[i]==0 && adj[s][i])
			dfs(i);
	}
}
void call(int y[],int m)
{
	int o=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d ",adj[y[i]-1][y[j]-1]);
		}
		printf("\n");
	}
}
int main()
{
	scanf("%d %d",&nodes,&d);
	for(int i=0;i<d;i++)
	{
		//scanf("%d",&f[i]);
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x-1][y-1]=1;
		adj[y-1][x-1]=1;
	}
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			int x=abs(f[i]-f[j]);
			if(x>=d)
			{
				adj[i][j]=1;
				edges++;
			}
			else
				adj[i][j]=0;
		}
	}
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
	int c=0;
	printf("\n");
	for(int i=0;i<nodes;i++)
	{
		if(visited[i]==0)
		{
			dfs(i);
			c++;
			printf("\n");
			x[t++]=-1;
		}
	}
	printf("The number of connected components are= %d\n",c);
	for(int i=0;i<t;i++)
	{
		if(x[i]!=-1)
			y[m++]=x[i];
		else
		{
			call(y,m);
			int y[100005]={0};
			m=0;
			printf("\n");
		}
		printf("%d ",x[i]);
	}
}
