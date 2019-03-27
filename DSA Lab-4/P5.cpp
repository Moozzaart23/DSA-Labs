#include<stdio.h>
#include<limits.h>
int n;
int a[100005];
int m;
int max=INT_MIN;
int high=0;
int find(int x)
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans+=(x/a[i]);
	}
	return ans;
}
void binSearch()
{
	int low=1;
	while(low<high)
	{
		int mid=(low+high)/2;
		int check=find(mid);
		if(check<m)
			low=mid+1;
		else
			high=mid;
	}
	printf("%d ",high);
}
int main()
{
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]>max)
			max=a[i];
	}
	printf("%d\n",max);
	high=max*m;
	binSearch();
}
