#include<stdio.h>
#include<limits.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
typedef struct Node
{
	int l,r,i;
}node;
node b[100005];
node a[100005];
void merge(int low,int high)
{
	int mid=(low+high)/2;
	int fptr=low;
	int sptr=mid+1;int tptr=low;
	while(fptr<=mid && sptr<=high)
	{
		//printf("lol\n");
		if(a[fptr].l<=a[sptr].l)
		{
			b[tptr].l=a[fptr].l;
			b[tptr].i=a[fptr].i;
			b[tptr++].r=a[fptr++].r;
		}
		else if(a[fptr].l==a[sptr].l)
		{
			if(a[fptr].r<a[sptr].r)
			{
				b[tptr].l=a[fptr].l;
				b[tptr].i=a[fptr].i;
				b[tptr++].r=a[fptr++].r;
			}
			else
			{
				b[tptr].l=a[sptr].l;
				b[tptr].i=a[sptr].i;
				b[tptr++].r=a[sptr++].r;
			}
		}
		else if(a[fptr].l>a[sptr].l)
		{
			b[tptr].l=a[sptr].l;
			b[tptr].i=a[sptr].i;
			b[tptr++].r=a[sptr++].r;
		}
	}
	while(fptr<=mid)
	{
		//printf("lol2\n");
		b[tptr].l=a[fptr].l;
		b[tptr].i=a[fptr].i;
		b[tptr++].r=a[fptr++].r;
	}
	while(sptr<=high)
	{
		//printf("lol3\n");
		b[tptr].l=a[sptr].l;
		b[tptr].i=a[sptr].i;
		b[tptr++].r=a[sptr++].r;
	}
	for(int i=low;i<=high;i++)
	{
		a[i].l=b[i].l;
		a[i].r=b[i].r;
		a[i].i=b[i].i;
	}
}
void sort(int low,int high)
{
	if(low>=high)
		return;
	int mid=(low+high)/2;
	sort(low,mid);
	sort(mid+1,high);
	merge(low,high);
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
	
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
		sort(0,n-1);
		/*for(int i=0;i<n;i++)
		{
			printf("%d %d %d\n",a[i].l,a[i].r,a[i].i);
		}*/
		//printf("\n");
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
