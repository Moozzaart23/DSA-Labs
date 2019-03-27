#include<stdio.h>
#include<limits.h>
#define max(a,b)  (a>b?a:b)
int q[100005];
int rear = 0;
int front = 0;
int adj[1000][1000];
int visited[100005]={0};
int alice[100005]={0};
int bob[100005]={0};
int n,x;
void push(int x)
{
        q[rear] = x;
        rear=rear+1;
}
void pop()
{  
    front = front + 1;
}
int front1()
{
	int x=front;
	return q[x];
}
int isempty()
{
	if(front>=rear)
		return 1;
	else
		return 0;
}

void bfs(int s,int f)
{
	int q[100005];
	int rear = 0;
	int front = 0;
	int visited[100005]={0};
	push(s);
	visited[s]=1;
	if(f==0)
		alice[s]=0;
	else
		bob[s]=0;
	while(!isempty())
	{
		int p=front1();
		pop();
		for(int i=0;i<n;i++)
		{
			if(adj[p][i]==1 && visited[i]==0)
			{
				visited[i]=1;
				push(i);
				if(f==0)
					alice[i]=alice[p]+1;
				else
					bob[i]=bob[p]+1;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			adj[i][j]=0;
		}
	}
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x-1][y-1]=1;
		adj[y-1][x-1]=1;
	}
	bfs(0,0);
	bfs(x-1,1);
	int ans=alice[x-1];
	for(int i=0;i<n;i++)
	{
		if(alice[i]>bob[i])
			ans=max(ans,alice[i]);
	}
	printf("%d",2*ans);
}
