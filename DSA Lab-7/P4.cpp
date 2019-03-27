#include<stdio.h>
int a[10005]={0};
int n,m;
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
	scanf("%d %d",&n,&m);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		a[i]=x;
		sum+=x;
	}
	/*for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");*/
	sort();
	/*for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");*/
	int c=0;int c1=0;
	for(int i=0;i<n;i++)
	{
		c1++;
		if(a[i]>c)
			c++;
	}
	//printf("%d %d\n",c,c1);
	c1+=(a[n-1]-c);
	printf("%d",(sum-c1));
	return 0;
}
