#include<stdio.h>
#include<math.h>
typedef struct Node
{
	int data,dig;
}node;
node a[100005];
int n;
void sort()
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			int x=a[j].data*pow(10,a[j+1].dig)+a[j+1].data;
			int y=a[j+1].data*pow(10,a[j].dig)+a[j].data;
			//printf("%d %d\n",x,y);
			if(x>y)
			{
				int temp=a[j].data;
				a[j].data=a[j+1].data;
				a[j+1].data=temp;
				int temp2=a[j].dig;
				a[j].dig=a[j+1].dig;
				a[j+1].dig=temp2;
			}
		}
	}
}
void check()
{
	for(int i=0;i<n;i++)
	{
		int copy=a[i].data;
		int d=0;
		while(copy!=0)
		{
			d++;
			copy/=10;
		}
		a[i].dig=d;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].data);
	}
	check();
	//for(int i=0;i<n;i++)
		//printf("%d %d\n",a[i].data,a[i].dig);
	sort();
	//for(int i=0;i<n;i++)
		//printf("%d %d\n",a[i].data,a[i].dig);
	for(int i=n-1;i>=0;i--)
		printf("%d",a[i].data);
}
