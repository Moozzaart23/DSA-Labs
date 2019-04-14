#include<stdio.h>
int main()
{
	int g;
	scanf("%d",&g);
	while(g--)
	{
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		int a[n];
		int b[m];
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<m;i++)
			scanf("%d",&b[i]);
		int t=0;int s=0;
		int sum=0;int c=0;
		while(sum+a[t]<=k && t<n)
		{
			sum+=a[t];
			t=t+1;
		}
		//printf("%d\n",sum);
		c=t;
		while(s<m && t>=0)
		{
			sum+=b[s];
			s=s+1;
			while(sum>k && t>0)
			{
				t=t-1;
				sum-=a[t];
			}
			if(sum<=k && c<t+s)
				c=t+s;
		}
		printf("%d\n",c);
	}
}
