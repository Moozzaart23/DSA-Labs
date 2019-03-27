#include<stdio.h>
#include<limits.h>
int nodes;
int adj[100][100];
int min=INT_MAX;
int path[10005];
int visited[100005]={0};
int visited2[100005]={0};
int cost=0;
int cost2=0;
int k=0;
int b[100005]={0};
void dfs(int i,int p)
{
    int j;
    for(j=0;j<nodes;j++)
    {
        if(adj[i][j])
        {
            if(j==p)
            {
                cost+=adj[i][j];
                if(cost<min)
                {
                	min=cost;
				}
                cost-=adj[i][j];
                visited[j]=0;
                break;
            }
            else if((!visited[j])&&(j!=p))
            {
                cost+=adj[i][j];
                b[k++]=j;
                visited[j]=1;
                dfs(j,p);
                cost-=adj[i][j];
                k--;
                visited[j]=0;
            }
        }
    }
}
void dfs2(int i,int p)
{
    int j;
    for(j=0;j<nodes;j++)
    {
        if(adj[i][j])
        {
            if(j==p)
            {
                cost2+=adj[i][j];
                if(cost2==min)
                {
					printf("%d ",p);
				    for(int t=0;t<k;t++)
				    {
				        printf("%d ",b[t]);
				    }
				    printf("%d",p);
				    printf("\n");
				}
                cost2-=adj[i][j];
                visited2[j]=0;
                break;
            }
            else if((!visited2[j])&&(j!=p))
            {
                cost2+=adj[i][j];
                b[k++]=j;
                visited2[j]=1;
                dfs2(j,p);
                cost2-=adj[i][j];
                k--;
                visited2[j]=0;
            }
        }
    }
}
int main()
{
	int edges;
	scanf("%d",&nodes);
	scanf("%d",&edges);
	for(int i=0;i<edges;i++)
	{
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		adj[x][y]=z;
	}
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			if(adj[i][j])
			{
				cost=adj[i][j];
				b[k++]=j;
            	visited[j]=1;
            	dfs(j,i);
            	visited[j]=0;
            	k=0;
            	cost=0;
			}
		}
	}
	
	if(min==INT_MAX)
	{
		printf("There exists no cycle in the graph\n");
		return 0;
	}
	printf("The minimum cost is %d \n and the cycles are\n",min);
	for(int i=0;i<nodes;i++)
	{
		for(int j=0;j<nodes;j++)
		{
			if(adj[i][j])
			{
				cost2=adj[i][j];
				b[k++]=j;
            	visited2[j]=1;
            	dfs2(j,i);
            	visited2[j]=0;
            	k=0;
            	cost2=0;
			}
		}
	}
	return 0;
}
