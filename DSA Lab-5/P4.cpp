#include<stdio.h>
#define min(a,b) (a<b?a:b)
typedef struct Node
{
	int first,second;
}node;
node a[100005];
node b[100005];
int n;
void sort()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j].first>a[j+1].first)
			{
				int temp=a[j].first;
				a[j].first=a[j+1].first;
				a[j+1].first=temp;
				int temp1=a[j].second;
				a[j].second=a[j+1].second;
				a[j+1].second=temp1;
			}
		}
	}
}
void sort1()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(b[j].first<b[j+1].first)
			{
				int temp=b[j].first;
				b[j].first=b[j+1].first;
				b[j+1].first=temp;
				int temp1=b[j].second;
				b[j].second=b[j+1].second;
				b[j+1].second=temp1;
			}
		}
	}
}
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
int func()
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		//printf("lol\n");
		if(a[i].second==i)
			continue;
		else
		{
			//printf("lol2\n");
			swap(&a[i].first,&a[a[i].second].first);
			swap(&a[i].second,&a[a[i].second].second);
		}
		if(i!=a[i].second)
			--i;
		ans++;
	}
	return ans;
}
int func1()
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		//printf("lol\n");
		if(b[i].second==(n-1-i))
			continue;
		else
		{
			//printf("lol2\n");
			swap(&b[i].first,&b[n-1-b[i].second].first);
			swap(&b[i].second,&b[n-1-b[i].second].second);
		}
		if((n-1-i)!=b[i].second)
			--i;
		ans++;
	}
	return ans;
}
void print()
{
	for(int i=0;i<n;i++)
	{
		printf("%d %d\n",b[i].first,b[i].second);
	}
	printf("\n");
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		a[i].first=x;
		a[i].second=i;
		b[i].first=x;
		b[i].second=n-1-i;
	}
	//print();
	sort();
	sort1();
	//print();
	int n1=func();
	int n2=func1();
	printf("%d",min(n1,n2));
	//printf("%d %d",n1,n2);
}
