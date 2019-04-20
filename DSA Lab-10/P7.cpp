#include<stdio.h>
int n;
int a[10005];
int count(int i,int j)
{
	//printf("%d %d\n",i,j);
	if((j-i)%2==0)
		return 0;
	int z=0;int o=0;
	for(int x=i;x<=j;x++)
	{
		if(a[x]==0)
			z++;
		else
			o++;
		//printf("%d ",a[x]);
	}
	//printf("\n");
	if(z==o)
		return 1;
	else
		return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	int c=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int x=count(i,j);
			if(x)
				c++;
		}
	}
	printf("%d",c);
}
