#include<stdio.h>
int n;
int a[100005];
int k;
void binSearch()
{
	int low=0;int high=n-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if(a[mid]==k)
		{
			printf("%d",mid+1);
			return;
		}
		if(mid>low && a[mid-1]==k)
		{
			printf("%d",mid);
			return;
		}
		if(mid<high && a[mid+1]==k)
		{
			printf("%d",mid+2);
			return;
		}
		if(a[mid]>k)
			high=mid-2;
		else
			low=mid+2;
	}
	printf("-1");
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	binSearch();
}
