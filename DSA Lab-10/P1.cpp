#include<stdio.h>
int n,k;
int a[10005];
int b[10005];
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
void sort(int a[])
{
	for(int i=0;i<k;i++)
	{
		int ind=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]>a[ind])
			{
				ind=j;
			}
		}
		if(ind!=i)
			swap(&a[ind],&a[i]);
	}
}
void check()
{
	printf("%d ",a[0]+b[0]);
	k=k-1;
	int p=0;int q=0;int u=1;int v=1;
	while(k--)
	{
		if(a[u]+b[p]>a[q]+b[v])
		{
			printf("%d ",a[u]+b[p]);
			u++;
			if(u==n)
			{
				p++;
				u=p+1;
			}
		}
		else if(a[u]+b[p]<a[q]+b[v])
		{
			printf("%d ",a[q]+b[v]);
			v++;
			if(v==n)
			{
				q++;
				v=q+1;
			}
		}
		else
		{
			if(k>=2)
			{
				printf("%d %d ",a[u]+b[p],a[q]+b[v]);
				k=k-1;
				u++;
				if(u==n)
				{
					p++;
					u=p+1;
				}
				v++;
				if(v==n)
				{
					q++;
					v=q+1;
				}
			}
			else
			{
				printf("%d ",a[u]+b[p]);
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	sort(a);
	sort(b);
	check();
}
