#include<stdio.h>
int a[100][100];
int vis[100][100];
//int b[100005];
int t=0;
int n;
int sum=0;
int min=999999;
void dfs(int x,int y,int b[],int t)
{
	if(x<0 || y<0 || x>=n || y>=n || vis[x][y]==1)
		return;
	if(x==(n-1))
	{
		for(int i=y;i<n;i++)
		{
			if(a[x][i]<=a[p][p1])
				sum+=0;
			else
				sum+=(a[x][i]-a[p][p1]);
			//sum+=a[x][i];
			//b[t+i-y]=a[x][i];
			//b[t++]=i;
		}
		for(int i=1;i<t+n-y;i++)
		{
			if(b[i]<=b[i-1])
				sum+=0;
			else
				sum+=(b[i]-b[i-1]);
			printf("%d ",b[i]);
		}
		if(sum<min)
			min=sum;
		printf("%d\n",sum);
		//printf("Sum= %d \n",sum);
		sum=0;
		return;
	}
	if(y==(n-1))
	{
		for(int i=x;i<n;i++)
		{
			if(a[i][y]<=a[p][p1])
				sum+=0;
			else
				sum+=(a[i][y]-a[p][p1]);
			//b[t+i-x]=a[i][y];
			//b[t++]=y;
		}
		for(int i=1;i<t+n-x;i++)
		{
			if(b[i]<=b[i-1])
				sum+=0;
			else
				sum+=(b[i]-b[i-1]);
			printf("%d ",b[i]);
		}
		printf("Sum= %d \n",sum);
		printf("%d\n",sum);
		if(sum<min)
		{
			min=sum;
		}
		//b[t++]=-1;
		sum=0;
		return;
	}
	b[t++]=a[x][y];
	vis[x][y]=1;
	//b[t++]=y;
	dfs(x+1,y,b,t);
	dfs(x,y+1,b,t);
	dfs(x-1,y,b,t);
	dfs(x,y-1,b,t);
}







int main()
{
	//int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			//printf("l");
			scanf("%d",&a[i][j]);
			vis[i][j]=0;
		}
	}
	int b[100005];
	//int t=0;
	dfs(0,0,b,0);
	printf("%d",min);
	/*for(int i=0;i<t;i++)
		printf("%d ",b[i]);*/
}
