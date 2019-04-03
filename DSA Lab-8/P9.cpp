#include<stdio.h>
#include<math.h>
#define min(a,b) (a<b?a:b)
int n;
int a[100005];
int ss1[10005]={0};int x=0;
int ee1[10005]={0};int y=0;
int max=0;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int start=0;int end=0;
	int s1=0;int e1=0;
	for(int i=0;i<n-1;i++)
	{
		if(a[i+1]<=a[i])
		{
			end=i+1;
		}
		else 
		{
			//printf("l=%d\n",l);
			int l=end-start+1;
			//printf("%d %d\n",start,end);
			//printf("l=%d \n",l);
			/*if(l>max && start==0)
			{
				printf("lol\n");
				s1=start;
				e1=end;
				max=l;
				ss1[x++]=start;
				ee1[y++]=end;
				start=i+1;end=0;
				continue;
			}*/
			if(l>max)
			{
				s1=start;
				e1=end;
				max=l;
				x=0;y=0;
				ss1[x++]=start;
				ee1[y++]=end;
			}
			else if(l==max)
			{
				ss1[x++]=start;
				ee1[y++]=end;
			}
			start=i+1;end=0;
		}
	}
	int l=end-start+1;
	//printf("%d %d\n",start,end);
	//printf("l=%d \n",l);
	if(l>max)
	{
		s1=start;
		e1=end;
		max=l;
		x=0;y=0;
		ss1[x++]=start;
		ee1[y++]=end;
	}
	else if(l==max)
	{
		ss1[x++]=start;
		ee1[y++]=end;
	}
	start=0;end=0;
	//printf("Max= %d\n",max);
	//printf("%d %d\n",x,y);
	int ans=99999999;
	for(int i=0;i<x;i++)
	{
		int anss=0;
		//printf("l= %d %d\n",ss1[i],ee1[i]);
		int m=a[ss1[i]];int o=a[ee1[i]];
		//printf("%d %d\n",m,o);
		for(int j=0;j<ss1[i];j++)
			anss+=abs(a[j]-m);
		for(int j=ee1[i]+1;j<n;j++)
			anss+=abs(a[j]-o);
		ans=min(ans,anss);
		//printf("%d\n",anss);
	}
	printf("%d",ans);
}



/**************OR***************/




/*#include<stdio.h>
#define min(a,b) (a<b?a:b)
#define diff(a,b) (a>b?a-b:b-a)
int a[1000],n,dp[1000][1000];
int ans=1e9;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<=1000;i++)
	{
		for(int j=0;j<=1000;j++)
		{
			dp[i][j]=1e9;
		}
	}
	for(int i=0;i<=1000;i++)
		dp[1][i]=diff(i,a[1]);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=1000;j++)
		{
			for(int k=j;k<=1000;k++)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][k]+diff(a[i],j));
			}
		}
	}
	for(int i=0;i<=1000;i++)
		ans=min(ans,dp[n][i]);
	printf("%d",ans);
}*/
