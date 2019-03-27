#include<stdio.h>
#include<limits.h>
int a[100][100];
int n;
int func()
{
	for(int i=0;i<n;i++)
	{
		int min=a[i][0];
		//int ind=0;
		for(int j=1;j<n;j++)
		{
			if(a[i][j]<min)
			{
				min=a[i][j];
				//ind=j;
			}
		}
		int c[10005]={0};int t=0;
		for(int p=0;p<n;p++)
		{
			if(a[i][p]==min)
			{
				c[t++]=p;
			}
				
		}
		/*for(int r=0;r<t;r++)
		{
			printf("%d ",c[r]);
		}
		printf("\n");*/
		int k=0;
		for(int r=0;r<t;r++)
		{
			int ind=c[r];
			for(k=0;k<n;k++)
			{
				if(a[k][ind]>min)
					break;
			}
			if(k==n)
			{
				printf("%d \n",min);
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int s=func();
	if(s==0)
		printf("No Saddle Points");
	return 0;
}
