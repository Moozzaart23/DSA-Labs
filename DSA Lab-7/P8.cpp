#include<stdio.h>
#include<math.h>
int n;
int check(int n)
{
	int p=-1;
	while(n)
	{
		int d=n%10;
		if(p==-1)
			p=d;
		else
		{
			if(abs(d-p)!=1)
				return 0;
		}
		p=d;
		n/=10;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		if(check(i))
			printf("%d ",i);
	}
}
