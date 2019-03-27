#include<stdio.h>
int check(int n)
{
	if(n<=6)
	{
		return n;
	}
	int max=0;
	for(int i=n-3;i>=1;i--)
	{
		int curr=(n-i-1)*check(i);
		if(curr>max)
			max=curr;
	}
	return max;
}  
int main()
{
	int n;
	scanf("%d",&n);
	int ans=check(n);
	printf("%d ",ans);
}
