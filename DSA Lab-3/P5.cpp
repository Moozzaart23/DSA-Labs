#include<stdio.h>
#include<limits.h>
#define max(a,b) (a>b?a:b)
int n;
int adj[1000][1000];
int visited[1000][1000];
int rr[8]={-1,-1,-1,0,0,1,1,1};
int cc[8]={-1,0,1,-1,1,-1,0,1};
int maxx=INT_MIN;
int check(int x,int y)
{
	if(   (x>=0 && x<n)  &&   (y>=0 && y<n)  && adj[x][y] && !visited[x][y]    )
		return 1;
	else
		return 0;
}
void dfs(int r,int c,int &co)
{
	visited[r][c]=1;
	for(int k=0;k<8;k++)
	{
		if(check(r+rr[k],c+cc[k]))
		{
			co++;
			dfs(r+rr[k],c+cc[k],co);
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			visited[i][j]=0;
			scanf("%d",&adj[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(adj[i][j] && !visited[i][j])
			{
				int c=1;
				dfs(i,j,c);
				maxx=max(maxx,c);
			}
		}
	}
	printf("%d",maxx);
}
