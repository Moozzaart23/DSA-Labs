#include<stdio.h>
#include<limits.h>
#define max(a,b) (a>b?a:b)
int adj[100][100];
int nodes;
int max=0;
int cost2=0;
int visited[100005]={0};int k=0;
int temp[100005]={0};
int o=0;
int x1,y1;

int minnode(int cost[],int visited[])
{
	int min=INT_MAX;
	int ind=-1;
	for(int i=0;i<nodes;i++)
	{
		if(visited[i]==0 && cost[i]<min)
		{
			min=cost[i];
			ind=i;
		}
	}
	return ind;
}


void dfs(int i,int j,int d,int tr)
{
	temp[k++]=i+1;
	if(tr==d && i==j)
	{
		int f1=0;int f2=0;
		for(int t=0;t<k;t++)
		{
			if(temp[t]==x1)
			{
				for(int m=(t+1);m<k;m++)
				{
					if(temp[m]==y1)
						f1=1;
				}
			}
			//printf("%d ",temp[t]);
		}
		if(f1==0)
		{
			//printf("\nabove\n");
			max++;
		}
			//max++;
		//printf("\n");
		k--;
		return;
	}
	visited[i]=1;
	for(int m=0;m<nodes;m++)
	{
		if(adj[i][m]==1 && !visited[m])
		{
			dfs(m,j,d,tr+1);
		}
	}
	visited[i]=0;
	k--;
}
void findCost(int p)
{
	int cost[100005];
	int visited[100005];
	for(int i=0;i<nodes;i++)
	{
		cost[i]=INT_MAX;
		visited[i]=0;
	}
	visited[p]=1;
	if(adj[p][p]==0)
		cost[p]=-1;
	else
		cost[p]=1;
	
	for(int i=0;i<nodes;i++)
	{
		if(adj[p][i])
		{
			cost[i]=adj[p][i];
		}
	}
	for(int i=0;i<nodes;i++)
	{
		int u=minnode(cost,visited);
		if(u!=-1)
			visited[u]=1;
		for(int j=0;j<nodes;j++)
		{
			int x=(cost[u]+adj[u][j]);
			if(visited[j]==0 && adj[u][j] && (x<cost[j]))
			{
				cost[j]=cost[u]+adj[u][j];
			}
		}
	}
	for(int i=0;i<nodes;i++)
	{
		if(cost[i]!=-1)
		{
			//max=max(max,cost[i]);
			//printf("The shortest cost between %d and %i is %d \n",(p+1),(i+1),cost[i]);
			//printf("The all possible shortest paths are:- \n");
			dfs(p,i,cost[i],0);
		}
		//if(cost[i]==o)
			//printf("%d %d \n",(p),(i));
	}
	//printf("\n");
}
int main()
{
	int edges;
	scanf("%d",&nodes);
	//scanf("%d",&edges);
	scanf("%d%d",&x1,&y1);
	edges=nodes-1;
	for(int i=0;i<edges;i++)
	{
		int x,y,z;
		scanf("%d %d",&x,&y);
		adj[x-1][y-1]=1;
		adj[y-1][x-1]=1;
	}
	
	//printf("Shortest Paths are:- \n");
	for(int i=0;i<nodes;i++)
		findCost(i);
	printf("The number is %d \n",max);
	return 0;
}
