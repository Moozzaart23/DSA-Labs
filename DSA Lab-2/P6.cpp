#include<stdio.h>
#include<stdlib.h>
int nodes,edges;
int adj[1000][1000];
int adj2[100][100];
int visited[100005]={0};
int m[100005]={0};int o=0;
void dfs(int s,int x)
{
	visited[s]=1;
	if(s==x)
		return;
	for(int j=0;j<nodes;j++)
	{
		if(visited[j]==0 && adj[s][j])
			dfs(j,x);
	}
}
typedef struct Edge
{
	int a;int b;int id;
}edge;
int main()
{
	edge p[10000];
	scanf("%d %d",&nodes,&edges);
	int t=0;
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			//int x;
			//scanf("%d",&x);
			adj2[i][j]=0;
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
	for(int i=0;i<edges;i++)
	{
		for(int j=0;j<edges;j++)
		{
			adj[i][j]=0;
		}
	}
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			if(adj2[i][j]==1)
			{
				p[t].a=(i+1);
				p[t].b=(j+1);
				p[t].id=t;
				t++;
			}
		}                                                                                   
	}
	/*for(int i=0;i<edges;i++)
	{
		printf("%d %d %d\n",p[i].a,p[i].b,p[i].id);
	}*/
	for(int i=0;i<edges;i++)
	{
		for(int j=0;j<edges;j++)
		{
			if(i!=j)
			{
				if(  (p[i].a==p[j].a) || (p[i].a==p[j].b) ||  (p[i].b==p[j].a)  || (p[i].b==p[j].b)  )
				{
					adj[p[i].id][p[j].id]=1;
					adj[p[j].id][p[i].id]=1;
				}
			}
		}
	}
	/*for(int i=0;i<edges;i++)
	{
		for(int j=0;j<edges;j++)
		{
			printf("%d ",adj[i][j]);
		}
		printf("\n");
	}*/
	for(int i=0;i<edges;i++)
	{
		int c=0;
		for(int j=0;j<nodes;j++)
		{
			if(i==j)
				continue;
			if(visited[i]==0)
			{
				dfs(j,i);
				c++;
			}
		}
		for(int j=0;j<=nodes;j++)visited[j]=0;
		if(c>1)
		{
			m[o++]=i;
		}
	}
	if(o==0)
	{
		printf("No components formed\n");
		return 0;
	}
	for(int i=0;i<o;i++)
	{
		printf("%d ",m[i]);
	}
	return 0;
}
