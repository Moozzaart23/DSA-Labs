#include<stdio.h>
int min[1000]={0};int mi=0;
int max[1000]={0};int ma=0;
double m=0;
int parent(int i)
{
	return (i-1)/2;
}
void swap(int *x,int *y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
void insert(int x)
{
	ma=ma+1;
	int i=ma-1;
	max[i]=x;
	while(i!=0 &&  max[parent(i)]<max[i])
	{
		swap(&max[i],&max[parent(i)]);
		i=parent(i);
	}
}
void insert1(int x)
{
	mi=mi+1;
	int i=mi-1;
	min[i]=x;
	while(i!=0 && min[parent(i)]>min[i])
	{
		swap(&min[i],&min[parent(i)]);
		i=parent(i);
	}
}
void heapify(int i)
{
	int p=parent(i);
	while(p!=0 &&  max[parent(i)]<max[i])
	{
		swap(&max[i],&max[parent(i)]);
		heapify(p);
	}
}
void heapify1(int i)
{
	int p=parent(i);
	while(p!=0 && min[parent(i)]>min[i])
	{
		swap(&max[i],&max[parent(i)]);
		heapify(p);
	}
}
void get(int e)
{
	if(mi==ma)
	{
		if(e<m)
		{
			insert(e);
			if(ma>=0)
				m=max[0];
		}
		else
		{
			insert1(e);
			if(mi>=0)
				m=min[0];
			//printf("lol\n");
		}
	}
	else if(ma>mi)
	{
		if(e<m)
		{
			int y=max[0];
			swap(&max[0],&max[ma-1]);
			ma=ma-1;
			//heapify(parent(ma+1));
			heapify(0);
			//insert(parent(ma+1));
			insert1(y);
			insert(e);
		}
		else
		{
			insert1(e);
		}
		//printf("hoho %d %d\n",min[0],max[0]);
		m=(double)(max[0]+min[0])/2;
	}
	else if(mi>ma)
	{
		if(e<m)
		{
			insert(e);
		}
		else
		{
			//printf("hehe\n");
			int y=min[0];
			swap(&min[0],&min[mi-1]);
			mi=mi-1;
			//heapify1(parent(mi+1));
			heapify1(0);
			//insert1();
			insert(y);
			insert1(e);
		}
		//printf("hehe %d %d\n",min[0],max[0]);
		m=(double)(max[0]+min[0])/2;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[100];
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&a[i]);
		//get(x);
		//printf("%d ",m);
	}
	for(int i=0;i<n;i++)
	{
		get(a[i]);
		printf("%.2lf ",m);
	}
}
