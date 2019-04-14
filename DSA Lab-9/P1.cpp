#include<stdio.h>
int n,q,t,block;
int a[100],b[100],c[100],done[100];
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
void sort()
{
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[i])
			{
				swap(&a[i],&a[j]);
				swap(&b[i],&b[j]);
			}
		}
	}
}
int notempty()
{
	for(int i=0;i<n;i++)
		if(done[i]==0)
			return 1;
	return 0;
}
int fetch()
{
	if(block+1==n)
	{
		for(int i=0;i<n;i++)
			if(done[i]==0)
				return i;
	}
	if(t<a[block+1])
	{
		for(int i=0;i<=block;i++)
			if(done[i]==0)
				return i;
		t=a[block+1];
		return (block+1);
	}
	else
	{
		for(int i=block+1;i<(2*n);i++)
			if(done[i%n]==0)
				return (i%n);
	}
	return -1;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d %d",&a[i],&b[i]),done[i]=0;
	sort();
	/*for(int i=0;i<n;i++)
		printf("%d %d\n",a[i],b[i]);*/
	for(int i=0;i<n;i++)
		c[i]=a[i]+b[i];
	scanf("%d",&q);
	t=a[0];
	int i=0;
	block=-1;
	while(notempty())
	{
		if(b[i]>q)
		{
			b[i]=b[i]-q;
			t=t+q;
		}
		else
		{
			t=t+b[i];
			b[i]=t;
			done[i]=1;
		}
		block=i;
		i=fetch();
	}
	double sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=b[i]-c[i];
	}
	printf("%lf",(sum/n));
}
