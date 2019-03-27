#include<stdio.h>
#include<limits.h>
int a[100][100];
int max=INT_MIN;
int n;
void get(int k)
{
	int sum1[100][100];
	for(int j=0;j<n;j++)
	{
		int sum=0;
		for(int i=0;i<k;i++)
			sum+=a[i][j];
		sum1[0][j]=sum;
		for(int i=1;i<(n-k+1);i++)
		{
			sum+=(a[i+k-1][j]-a[i-1][j]);
			sum1[i][j]=sum;
		}
	}
	for(int i=0;i<(n-k+1);i++)
	{
		int sum=0;
		for(int j=0;j<k;j++)
			sum+=sum1[i][j];
		if(sum>max)
			max=sum;
		for(int j=1;j<(n-k+1);j++)
		{
			sum+=(sum1[i][j+k-1]-sum1[i][j-1]);
			if(sum>max)
				max=sum;
		}
	}
}
int main()
{
	//int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	//for(int i=0;i<n;i++)
	//{
		get(3);
	//}
	printf("%d ",max);
}
