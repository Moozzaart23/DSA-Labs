#include<stdio.h>
int q[10005];
int rear = 0;
int front = 0;
int adj[100][100];
int visited[10000]={0};
int level[10000]={0};
int nodes,edges;
int t;
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

void bfs(int s)
{
	push(s);
	visited[s]=1;
	level[s]=1;
	while(!isempty())
	{
		int p=front1();
		pop();
		for(int i=0;i<nodes;i++)
		{
			if(adj[p][i]==1 && visited[i]==0)
			{
				visited[i]=1;
				push(i);
				level[i]=level[p]+1;
			}
		}
	}
	int max=0;
	for(int i=0;i<nodes;i++)
	{
		if(level[i]>max)
			max=level[i];
	}
	int x=t;int c=0;
	while(x<=max)
	{
		for(int i=0;i<nodes;i++)
		{
			if(level[i]==x)
				c++;
		}
		x=x+1;
	}
	printf("%d\n",c);
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
	scanf("%d",&t);
	bfs(0);
}
