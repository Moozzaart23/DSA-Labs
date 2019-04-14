#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];int b[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for(int i=0;i<n;i++)
	{
		int curr=a[i]-b[i];
		int j=i+1;
		while(curr>=0)
		{
			curr+=a[j]-b[j];
			j=(j+1)%n;
			if(j==i)
			{
				printf("%d",i);
				return 0;
			}
		}
	}
}
