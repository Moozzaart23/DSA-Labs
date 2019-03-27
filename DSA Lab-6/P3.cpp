#include<stdio.h>
int n,m;
int adj[100][100];
int visited[100005]={0};
int leaf[100005]={0};int l=0;
int cats[100005]={0};
int temp[100005]={0};int k=0;
int ans=0;
void dfs(int s,int p)
{
	temp[k++]=s;
	if(s==p)
	{
		if(k>m)
		{
			for(int i=0;i<=(k-m-1);i++)
			{
				int c=0;
				for(int j=i;j<=(i+m);j++)
				{
					c+=cats[temp[j]];
				}
				if(c==(m+1))
				{
					ans++;
					break;
					c=0;
				}
			}
			/*for(int i=0;i<k;i++)
				printf("%d ",temp[i]+1);
			printf("\n");*/
		}
		//else if(k==m)
			//ans++;
		//printf("\n");
		k--;
		return;
	}
	//count=0;
	visited[s]=1;
	for(int m=0;m<(n);m++)
	{
		if(adj[s][m] && !visited[m])
		{
			//count+=cats[m];
			dfs(m,p);
		}
	}
	visited[s]=0;
	k--;
	//count=count-cats[s];
}
void check()
{
	for(int i=1;i<n;i++)
	{
		int c=0;
		for(int j=0;j<n;j++)
		{
			if(adj[i][j]==1)
				c++;
			//printf("%d ",adj[i][j]);
		}
		if(c==1)
		{
			leaf[i]=1;
			l++;
		}
		//printf("\n");
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			adj[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",&cats[i]);
	}
	for(int i=0;i<(n-1);i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x-1][y-1]=1;
		adj[y-1][x-1]=1;
	}
	check();
	for(int i=0;i<n;i++)
	{
		if(leaf[i]==1)
		{
			//printf("%d ",i);
			dfs(0,i);
			//count=0;
			//printf("%d\n",ans);
		}
	}
	 //printf("%d %d\n",l,ans);
	printf("%d",(l-ans));
	//dfs(0,4);
}
