#include<stdio.h>
int a[100][100];
int n=0;
void rec(int ul,int ll,int val)
{
	if(val==0)
		return;
	if(n%2==0)
	{
		for(int u=ll,v=ll;v<ul;v++)
		{
			a[u][v]=val--;
		}
		for(int u=ll+1,v=ul-1;u<ul;u++)
		{
			a[u][v]=val--;
		}
		for(int u=ul-1,v=ul-2;v>=ll;v--)
		{
			a[u][v]=val--;
		}
		for(int u=ul-2,v=ll;u>ll;u--)
		{
			a[u][v]=val--;
		}
	}
	else
	{
		for(int u=ul-1,v=ul-1;v>=ll;v--)
		{
			a[u][v]=val--;
		}
		for(int u=ul-2,v=ll;u>=ll;u--)
		{
			a[u][v]=val--;
		}
		for(int u=ll,v=ll+1;v<ul;v++)
		{
			a[u][v]=val--;
		}
		for(int u=ll+1,v=ul-1;u<(ul-1);u++)
		{
			a[u][v]=val--;
		}
	}
	rec(ul-1,ll+1,val);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j]=0;
		}
	}
	rec(n,0,(n*n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d   ",a[i][j]);
		}
		printf("\n\n");
	}
}
