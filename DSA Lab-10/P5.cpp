#include<stdio.h>
int n;
int a[100];
int b[100];int t=0;
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
int parent(int i)
{
	return (i-1)/2;
}
void insert(int x)
{
	t=t+1;
	int i=t-1;
	b[i]=x;
	while(i!=0 && b[parent(i)]<=b[i])
	{
		swap(&b[parent(i)],&b[i]);
		i=parent(i);
	}
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
		insert(a[i]);
	}
	heapify();
	for(int i=0;i<n;i++)
		printf("%d ",b[i]);
}
