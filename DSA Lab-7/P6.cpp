#include<stdio.h>
#include<string.h>
#include<math.h>
int n,k;
char a[1000];
int edges[100005]={0};int t=0;
char adj[100][100]={'0'};
int r=0;
int find(char x[])
{
	int i=0;
	int l=strlen(x);
	for(i=0;i<r;i++)
	{
		int flag=0;
		for(int j=0;j<l;j++)
		{
			if(adj[i][j]!=x[j])
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			return 1;
		}
	}
	return 0;
}
void insert(char x[])
{
	//r=r+1;
	for(int i=0;i<strlen(x);i++)
	{
		adj[r][i]=x[i];
	}
	r=r+1;
}
void dfs(char node[])
{
	for(int i=0;i<k;i++)
	{
		char c[100005]={'0'};
		int j=0;
		for(j=0;j<strlen(node);j++)
		{
			c[j]=node[j];
		}
		c[j++]=a[i];
		//printf("c= %s\n",c);
		if(!find(c))
		{
			//printf("%s\n",c);
			insert(c);
			char d[100005]={'0'};
			for(int j=1;j<strlen(c);j++)
			{
				d[j-1]=c[j];
			}
			//printf("d= %s\n",d);
			dfs(d);
			edges[t++]=i;
		}
	}
}
void calc()
{
	char b[100005]={'0'};
	for(int i=0;i<n-1;i++)
	{
		b[i]=a[0];
	}
	//printf("b= %s\n",b);
	dfs(b);
	//for(int i=0;i<t;i++)
		//printf("%d ",edges[i]);
	char ans[100005]={'0'};int len=0;
	int l=pow(k,n);
	for(int i=0;i<l;i++)
		ans[len++]=a[edges[i]];
	for(int i=0;i<strlen(b);i++)
		ans[len++]=b[i];
	printf("%s",ans);
}
int main()
{
	scanf("%d%d",&n,&k);
	scanf("%s",&a);
	calc();
}
