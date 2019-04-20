#include<stdio.h>
int n;
int a[100];
int check()
{
	for(int i=0;i<=(n-1)/2;i++)
	{
		if(a[2*i+1]<a[i] && 2*i+1<n)
			return 0;
		if(2*i+2<n && a[2*i+2]<a[i])
			return 0;
	}
	return 1;
}
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
void heapify()
{
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[(i-1)/2])
		{
			int j=i;
			while(a[j]>a[(j-1)/2])
			{
				swap(&a[j],&a[(j-1)/2]);
				j=(j-1)/2;
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	if(check())
	{
		printf("Yes heap\n");
	}
	else
	{
		printf("Not Heap\n");
	}
}
