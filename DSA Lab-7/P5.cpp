#include<stdio.h>
#include<limits.h>
int q[10005];
int rear = 0;
int front = 0;
int adj[1000][1000];
int visited[10000]={0};
int dist[100005]={0};
int dist1[100005]={0};
int n,m,s,t;
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
bool isempty()
{
	if(front>=rear)
		return true;
	else
		return false;
}

void bfs(int s,int f)
{
	int q[10005];
	int rear = 0;
	int front = 0;
	int visited[10000]={0};
	push(s);
	visited[s]=1;
	if(f==0)
		dist[s]=0;
	else
		dist1[s]=0;
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
					dist[i]=dist[p]+1;
				else
					dist1[i]=dist1[p]+1;
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			adj[i][j]=0;
		}
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x-1][y-1]=1;
		adj[y-1][x-1]=1;
	}
	bfs(s-1,0);
	bfs(t-1,1);
	for(int i=0;i<n;i++)
		printf("%d %d\n",dist[i],dist1[i]);
	int D=dist[t-1];
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(!adj[i][j])
			{
				if(dist[i]+dist1[j]+1>=D && dist[j]+dist1[i]+1>=D)
					count++;
			}
		}
	}
	printf("%d",count);
}
