#include<stdio.h>
#include<string.h>
char a1[2]={'I','\0'};
char b[3]={'D','\0'};
char c[4]={'S','W','\0'};
char d[3]={'S','O','\0'};
int a[100005];
int t=0;
void print()
{
	for(int i=0;i<t;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
int Search(int x)
{
	int ind=-1;
	for(int i=0;i<t;i++)
	{
		if(a[i]==x)
		{
			return i;
		}
	}
}
void insert(int x)
{
	int i=0;
	for(i=(t-1);(i>=0 && a[i]>x);i--)
	{
		a[i+1]=a[i];
	}
	a[i+1]=x;
	t=t+1;
	print();
}
void delet(int x)
{
	int pos=Search(x);
	for(int i=pos;i<t;i++)
		a[i]=a[i+1];
	t=t-1;
	print();
}
void swap(int x,int y)
{
	int pos1=Search(x);
	int pos2=Search(y);
	int temp=a[pos1];
	a[pos1]=a[pos2];
	a[pos2]=temp;
	print();
}
void sort()
{
	for(int i=0;i<t-1;i++)
	{
		for(int j=0;j<t-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	print();
}
int main()
{
	int x;
	while(1)
	{
		scanf("%d",&x);
		if(x==-1)
			break;
		else
			a[t++]=x;
	}
	int n;
	scanf("%d",&n);
	while(n--)
	{
		char ac[2];
		scanf("%s",ac);
		if(strcmp(ac,a1)==0)
		{
			int item;
			scanf("%d",&item);
			insert(item);
		}
		if(strcmp(ac,b)==0)
		{
			int item;
			scanf("%d",&item);
			delet(item);
		}
		if(strcmp(ac,c)==0)
		{
			int item1,item2;
			scanf("%d%d",&item1,&item2);
			swap(item1,item2);
		}
		if(strcmp(ac,d)==0)
		{
			sort();
		}
	}
	return 0;
}
