#include<stdio.h>
int a[10000];
int sum=0;
int temp[10005];
int x=0;
int b=0;
int n,k;
int ans=0;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		//printf("Lol\n");
		char c;
		scanf(" %c",&c);
		if(c=='G')
			a[i]=0;
		else if(c=='R')
			a[i]=1;
		else if(c=='Y')
			a[i]=2;	
	}
	for(int i=1;i<=n;i++)
	{
		//printf("Lol\n");
		a[i]+=sum;
		if((a[i]+1)%3==0)
		{
			temp[b++]=1;
			sum+=1;
			ans+=1;
		}
		else if((a[i]+2)%3==0)
		{
			temp[b++]=2;
			sum+=2;
			ans+=2;
		}
		else
		{
			temp[b++]=0;
		}
		if(i>=k)
			sum-=temp[x++];
	}
	printf("%d",ans);
}
