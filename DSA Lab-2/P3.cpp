#include<stdio.h>
int nodes,edges;
int a,b;
int adj[1000][1000];
int dfs(int pos,int c,int color[])
{
	if(color[pos]!=-1 && color[pos]!=c)
		return 0;
	color[pos] = c;
	if(c==0)
		a++;
	else
		b++; 
	int ans=1;
	for(int i=0;i<nodes;i++)
	{
		if(adj[pos][i])
		{
			if(color[i]==-1)
			{
				ans*=dfs(i,1-c,color); 
			}
			if(color[i] !=-1 && color[i] != 1-c) 
                return 0; 
		}
		if (!ans) 
            return 0; 
	}
	return 1;
}
int check()
{
	int color[100005];
	for(int i=0;i<nodes;i++)
	{
		color[i]=-1;
	}
	for (int i = 0; i < nodes; i++)
	{
		if(color[i]==-1)
		{
			if(dfs(i,0,color)==0)
				return 0;
		}
	}
    return 1;
}
int main()
{
	scanf("%d %d",&nodes,&edges);
	for(int i=0;i<edges;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x-1][y-1]=1;
		adj[y-1][x-1]=1;
	}
	int x=0;
	if(check())
		printf("Yes Bipartite");
	else
		printf("Not Bipartite");
}
