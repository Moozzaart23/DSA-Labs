#include<stdio.h>
int a[100][100];
int n=0;
int b[100005]={0};
int k=0;


int getPrime(int n)
{
	int p=2;
	while(k<n)
	{
		int flag=0;
		for(int c=2;c<p;c++)
		{
			if(p%c==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			b[k++]=p;
		}
		p++;
	}
}


void rec(int ul,int ll)
{
	if(k<0)
		return;
	if(n%2==0)
	{
		for(int u=ll,v=ll;v<ul;v++)
		{
			a[u][v]=b[k--];
		}
		for(int u=ll+1,v=ul-1;u<ul;u++)
		{
			a[u][v]=b[k--];
		}
		for(int u=ul-1,v=ul-2;v>=ll;v--)
		{
			a[u][v]=b[k--];
		}
		for(int u=ul-2,v=ll;u>ll;u--)
		{
			a[u][v]=b[k--];
		}
	}
	else
	{
		for(int u=ul-1,v=ul-1;v>=ll;v--)
		{
			a[u][v]=b[k--];
		}
		for(int u=ul-2,v=ll;u>=ll;u--)
		{
			a[u][v]=b[k--];
		}
		for(int u=ll,v=ll+1;v<ul;v++)
		{
			a[u][v]=b[k--];
		}
		for(int u=ll+1,v=ul-1;u<(ul-1);u++)
		{
			a[u][v]=b[k--];
		}
	}
	rec(ul-1,ll+1);
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
	getPrime(n*n);
	k=k-1;
	rec(n,0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d   ",a[i][j]);
		}
		printf("\n\n");
	}
}
