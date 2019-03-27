#include<stdio.h>
int n;
int a[100005];
int k;
void binSearch()
{
	int low=0;int high=n;
	while(low<high)
	{
		int mid=(low+high)/2;
		if(a[mid]==k)
		{
			printf("Naruto %d",(mid+1));
			return ;
		}
		if(a[mid]<k)
			low=mid+1;
		else
			high=mid;
	}
	printf("Sasuke %d",(low+1));
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
