#include<stdio.h>
#include<math.h>
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	if(k>=n)
	{
		printf("%d",n);
		return 0;
	}
	if(k==1)
	{
		printf("1");
		return 0;
	}
	int x=1;
	while(x)
	{
		//printf("v=%d\n",x);
		int c=x;int m=0;int sum=c;
		while(c!=0)
		{
			c=c/k;
			//printf("%d\n",c);
			sum+=c;
			m=m+1;
		}
		if(sum>=n)
		{
			printf("%d",x);
			return 0;
		}
		x=x+1;
	}
}
