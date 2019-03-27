#include<stdio.h>
int n;
int a[100005];
int k;
int binSearch(int low,int high,int target)
{
	if(low>high)
		return -1;
	int mid=(low+high)/2;
	if(a[mid]==target)
		return mid;
	if(a[low]<=a[mid])
	{
		if(target>=a[low] && target<=a[mid])
			return binSearch(low,mid+1,target);
		return binSearch(mid+1,high,target);
	}
	if(target>=a[mid] && target<=a[high])
		return binSearch(mid+1,high,target);
	return binSearch(low,mid-1,target);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&k);
	int ans=binSearch(0,n-1,k);
	if(ans==-1)
		printf("Element Not Found\n");
	else
		printf("%d",(ans+1));
}
