#include<stdio.h>
#include<limits.h>
int q[10005];
int rear = 0;
int front = 0;
int adj[100][100];
int visited[10000]={0};
int level[10000]={0};
int nodes,edges;
int t;
int uni[100005]={0};
int m=0;
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
	int c=0;int min=INT_MAX;
	for(int i=0;i<nodes;i++)
	{
		if(uni[c]==(i+1) && level[i]<min)
		{
			min=(i+1);
			c++;
		}
		
	}
	printf("%d",min);
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
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d",&uni[i]);
	}
	bfs(0);
}
