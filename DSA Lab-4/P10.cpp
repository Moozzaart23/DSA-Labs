#include<stdio.h>
#include<limits.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[100005]={0};
	int res=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		res=res^a[i];
	}
	printf("%d",res);
}
