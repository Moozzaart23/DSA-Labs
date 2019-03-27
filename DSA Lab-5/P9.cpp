#include<stdio.h>
#include<limits.h>
#define min(a,b) ((a<b)?a:b)
int n;
int a[100005];int f[100005]={0};
int N=0;
int dp(int l,int r)
{
	if(a[r]<=2*a[l])
	{
		return f[a[l]]-1+f[a[r]]-1;
	}
	else
	{
		int g=f[a[l]]+dp(l+1,r);
		int h=f[a[r]]+dp(l,r-1);
		printf("%d %d\n",g,h);
		return min(g,h);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		f[x]++;
	}
	for(int i=0;i<5001;i++)
	{
		if(f[i])
		{
			a[N++]=i;
		}
	}
	int maxi=dp(0,N-1);
	printf("%d",maxi);
}
