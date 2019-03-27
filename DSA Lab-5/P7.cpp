#include<stdio.h>
typedef struct Edge
{
	int l,r;
}edge;
typedef struct Node
{
	int d,in;
}node;
edge x[100005];
int t=0;
int n;
node a[100005];
void find(int k,int y)
{
	for(int i=0;i<n;i++)
	{
		//printf("She %d\n",a[i]);
		if(a[i].d==y)
		{
			//printf("He %d\n",i);
			x[t].l=(k);
			x[t].r=a[i].in;
			t=t+1;
			return;
		}
	}
}
void getcycle()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			//printf("%d %d %d %d\n",i,j,a[i],a[j]);
			if(a[i].d!=0 && a[j].d!=0 && a[i].d==a[j].d && (i!=j))
			{
				//printf("%d %d %d %d\n",a[i],a[j],i,j);
				x[t].l=(a[i].in);
				x[t].r=(a[j].in);
				t=t+1;
				return;
			}
		}
	}
}
void sort()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j].d>a[j+1].d)
			{
				int temp=a[j].d;
				a[j].d=a[j+1].d;
				a[j+1].d=temp;
				int temp2=a[j].in;
				a[j].in=a[j+1].in;
				a[j+1].in=temp2;
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	int zero=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].d);
		if(a[i].d==0)
			zero++;
		a[i].in=(i+1);
	}
	if(zero==0)
	{
		printf("-1");
		return 0;
	}
	sort();
	int one=0;
	for(int i=0;i<(n-1);i++)
	{
		if(a[i+1].d-a[i].d>=2)
		{
			printf("-1");
			return 0;
		}
		if(a[i+1].d-a[i].d==1)
			one++;
	}
	if(one==(n-1))
	{
		printf("-1");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(a[i].d!=0)
		{
			//printf("%d %d\n",i,a[i]);
			find(a[i].in,a[i].d-1);
		}
	}
	getcycle();
	printf("%d\n",t);
	for(int i=0;i<t;i++)
	{
		printf("%d %d\n",x[i].l,x[i].r);
	}
}
