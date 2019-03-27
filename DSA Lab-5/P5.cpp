#include<stdio.h>
int n;
int a[100005];
int sum=0;
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
void print(int ind1,int ind2)
{
	int c=0;int m=0;
	for(int i=n-1;i>=0;i--)
	{
		if(i!=ind1 && i!=ind2)
		{
			m++;
			if(a[i]==0)
				c++;
		}
	}
	if(m==0)
	{
		printf("No such Number");
		return;
	}
	if(c==m)
	{
		printf("0");
		return;
	}
	int h=0;
	for(int i=n-1;i>=0;i--)
	{
		if(i!=ind1 && i!=ind2)
		{
			if(h==0 && a[i]==0)
				continue;
			else
			{
				printf("%d",a[i]);
				h=1;
			}
		}
	}
}
void func()
{
	//printf("%d\n",sum);
	if(sum%3==0)
	{
		print(-1,-1);
		return;
	}
	int rem=sum%3;
	if(rem==1)
	{
		int x=-1;int y=-1;
		for(int i=0;i<n;i++)
		{
			if(a[i]%3==1)
			{
				//printf("lol\n");
				print(i,-1);
				return;
			}
			if(a[i]%3==2)
			{
				if(x==-1)
					x=i;
				else if(y==-1)
					y=i;
			}
		}
		if(x!=-1 && y!=-1)
			print(x,y);
	}
	else
	{
		//printf("lol2\n");
		int x=-1;int y=-1;
		for(int i=0;i<n;i++)
		{
			if(a[i]%3==2)
			{
				//printf("lol\n");
				print(i,-1);
				return;
			}
			if(a[i]%3==1)
			{
				if(x==-1)
					x=i;
				else if(y==-1)
					y=i;
			}
		}
		if(x!=-1 && y!=-1)
			print(x,y);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort();
	func();
}
