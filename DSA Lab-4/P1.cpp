#include<stdio.h>
#include<math.h>
int n,s;
int max=0;
int ans=0;
typedef struct Node
{
	int ind,data;
}node;
node a[100005];
node b[100005];
void func()
{
	int m=pow(2,n);int t=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				//c++;
				b[t].data=a[j].data;
				b[t].ind=a[j].ind;
				t=t+1;
			}
		}
		int sum=0;
		for(int y=0;y<t;y++)
		{
			sum+=(b[y].data+(t*b[y].ind));
		}
		if(sum<=s)
		{
			if(t>max)
			{
				max=t;
				ans=sum;
			}
			if(t==max && sum<ans)
			{
				ans=sum;
			}
		}
		t=0;
	}
}
int main()
{
	scanf("%d%d",&n,&s);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i].data);
		a[i].ind=(i+1);
	}
	/*for(int i=0;i<n;i++)
		printf("%d %d\n",a[i].ind,a[i].data);*/
	func();
	printf("%d %d",max,ans);
}
