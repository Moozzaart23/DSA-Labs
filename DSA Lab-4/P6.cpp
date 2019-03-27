#include<stdio.h>
int n;
int a[100005];
int d;
void sort()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
void binSearch()
{
	int low=0;
	int high=1;
	int c=0;
	while(low<n && high<n)
	{
		if(a[high]-a[low]==d)
		{
			printf("%d \n",a[low]+a[high]);
			c++;
			low++;
			high++;
		}
		if(a[high]-a[low]<d)
			high++;
		else
			low++;
	}
	if(c==0)
		printf("-1");
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort();
	scanf("%d",&d);
	printf("The sum of such pairs are\n");
	binSearch();
	return 0;
}
