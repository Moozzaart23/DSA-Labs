#include<stdio.h>
#include<limits.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
typedef struct Node
{
	int l,r,i;
}node;
void sort(node a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j].l>a[j+1].l)
			{
				int temp=a[j].l;
				a[j].l=a[j+1].l;
				a[j+1].l=temp;
				int temp1=a[j].r;
				a[j].r=a[j+1].r;
				a[j+1].r=temp1;
				int temp2=a[j].i;
				a[j].i=a[j+1].i;
				a[j+1].i=temp2;
			}
			if(a[j].l==a[j+1].l && a[j].r>a[j+1].r)
			{
				int temp=a[j].l;
				a[j].l=a[j+1].l;
				a[j+1].l=temp;
				int temp1=a[j].r;
				a[j].r=a[j+1].r;
				a[j+1].r=temp1;
				int temp2=a[j].i;
				a[j].i=a[j+1].i;
				a[j+1].i=temp2;
			}
		}
	}
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		node a[100005];
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[i].l=x;
			a[i].r=y;
			a[i].i=i;
		}
		sort(a,n);
		int p[n];
		for(int i=0;i<n;i++)
		{
			p[i]=0;
		}
		int ar=a[0].r;
		int br=0;
		p[a[0].i]=1;
		int one=1;int two=0;
		for(int i=1;i<n;i++)
		{
			if(a[i].l<=ar)
			{
				++one;
				p[a[i].i]=1;
				ar=max(ar,a[i].r);
			}
			else if(a[i].l<=br)
			{
				++two;
				p[a[i].i]=2;
				br=max(br,a[i].r);
			}
			else
			{
				if(one<two)
				{
					++one;
					p[a[i].i]=1;
					ar=a[i].r;
				}
				else
				{
					++two;
					p[a[i].i]=2;
					br=a[i].r;
				}
			}
		}
		if(one==0 || two==0)
		{
			printf("-1\n");
			continue;
		}
		for(int i=0;i<n;i++)
		{
			/*if(p[i]==1)
				printf("CA ");
			else
				printf("IM ");*/
			printf("%d ",p[i]);
		}
		printf("\n");
	}
}
