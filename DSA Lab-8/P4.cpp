#include<stdio.h>
int n,k;
int a[100005];
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
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort();
	int i=0;
	for(i=0;i<n;i++)
	{
		if(a[i]>=k)
			break;
		int c=2*a[i+1]+a[i];
		a[i]=-1;
		a[i+1]=c;
		/*for(int l=0;l<n;l++)
			printf("%d  ",a[l]);
		printf("\n");*/
		int j=0;
		for(j=i+2;j<n-1;j++)
		{
			if(c>=a[j])
				continue;
			break;
		}
		//printf("%d\n",j);
		j=j-(i+1);
		//printf("%d\n",j);
		for(int m=i+1;m<=j;m++)
		{
			int temp=a[m];
			a[m]=a[m+1];
		}
		a[j]=c;
		//sort();
		/*for(int l=0;l<n;l++)
			printf("%d ",a[l]);
		printf("\n");*/
	}
	printf("%d",i);
}
