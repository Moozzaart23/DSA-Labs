#include<stdio.h>
#include<limits.h>
typedef struct Edge
{
	int a,b,id;
}edge;
int nodes;int t=0;
int adj[100][100];
int adj2[100][100];
int adj3[100][100];
int visited[100005]={0};
int cut[100005]={0};
int u=0;
void dfs(int s,int x)
{
	visited[s]=1;
	if(s==x)
		return;
	//visited[s]=1;
	for(int i=0;i<t;i++)
	{
		if(visited[i]==0 && adj[s][i])
			dfs(i,x);
	}
}
int visited2[100005]={0};
void dfs2(int s)
{
	visited2[s]=1;
	printf("%d ",s);
	for(int i=0;i<t;i++)
	{
		if(visited2[i]==0 && adj3[s][i])
			dfs2(i);
	}
}
int main()
{
	scanf("%d",&nodes);
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			adj[i][j]=0;
			adj2[i][j]=0;
			adj3[i][j]=0;
		}
	}
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			int x;
			scanf("%d",&x);
			if(adj2[j][i]!=1 && x==1)
				adj2[i][j]=1;
		}
	}
	edge b[1000];
	printf("\n");
	/*for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			printf("%d ",adj2[i][j]);
		}
		printf("\n");
	}*/
	printf("\n");
	//int t=0;
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			if(adj2[i][j]==1)
			{
				b[t].a=i;
				b[t].b=j;
				b[t].id=t;
				t++;
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<t;j++)
		{
			if(i==j)
				continue;
			if( (b[i].a==b[j].a) || (b[i].a==b[j].b) ||  (b[i].b==b[j].a) ||  (b[i].b==b[j].b) )
			{
				adj[b[i].id][b[j].id]=1;
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<t;j++)
		{
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=0;i<t;i++)
	{
		int c=0;
		for(int j=0;j<t;j++)
		{
			if(i==j)
				continue;
			if(visited[j]==0)
			{
				dfs(j,i);
				c++;
			}
		}
		for(int j=0;j<t;j++)
			visited[j]=0;
		if(c>1)
			cut[u++]=i;
	}
	printf("%d \n",u);
	for(int i=0;i<u;i++)
		printf("%d ",cut[i]);
	printf("\n");
	int r=cut[0];
	int nodes1=0;
	int edges1=0;
	for(int i=0;i<t;i++)
	{
		if(i==r)
			continue;
		for(int j=0;j<t;j++)
		{
			if(j==r)
				continue;
			//printf("%d ",adj[i][j]);
			adj3[nodes1][edges1++]=adj[i][j];
		}
		//printf("\n");
		nodes1=nodes1+1;
		edges1=0;
	}
	t=t-1;
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<t;j++)
		{
			printf("%d ",adj3[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i=0;i<t;i++)
	{
		if(visited2[i]==0)
		{
			dfs2(i);
			printf("\n");
		}
	}
	
}
