#include<stdio.h>
int a[10005];int n;
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
int main()
{
	//int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort();
	int x=0;int y=0;
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
			x=x*10+a[i];
		else
			y=y*10+a[i];
	}
	printf("%d",(x+y));
}
