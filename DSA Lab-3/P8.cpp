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
		adj[x-1][y-1]=1;
	}
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		dfs(x-1);
		if(visited[y-1]==0)
			printf("No\n");
		else
			printf("Yes\n");
		for(int i=0;i<nodes;i++)
			visited[i]=0;	
	}
	return 0;
}
