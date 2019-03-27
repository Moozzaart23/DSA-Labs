#include<stdio.h>
int nodes,edges;
int adj[100][100];
int visited[100005]={0};
void dfs(int s)
{
	visited[s]=1;
	for(int i=0;i<nodes;i++)
	{
		if(adj[s][i] && visited[i]==0)
			dfs(i);
	}
}
int main()
{
	scanf("%d %d",&nodes,&edges);
	int ans[100005]={0};
	int a=0;
	for(int i=0;i<edges;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x][y]=1;
		adj[y][x]=1;
	}
	//for(int i=0;i<nodes;i++)
	//{
		dfs(0);
		/*int j;
		for(j=0;j<nodes;j++)
		{
			if(visited[j]==0)
				break;
		}
		if(j==nodes)
		{
			ans[a++]=(i+1);
		}
		for(int i=0;i<nodes;i++)
			visited[i]=0;		
	}
	if(a==0)
	{
		printf("No");
		return 0;
	}
	printf("Yes\n");
	for(int i=0;i<a;i++)
	{
		printf("%d ",ans[i]);
	}*/
	return 0;
}
