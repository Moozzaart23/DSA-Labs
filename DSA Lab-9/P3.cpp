#include<stdio.h>
int main()
{
	int max=100001;
	int a[max];
	for(int i=0;i<max;i++)
		a[i]=-1;
	a[0]=0;
	a[1]=1;
	a[2]=2;
	a[3]=3;
	for(int i=0;i<max;i++)
	{
		if(a[i]==-1 || (a[i]>a[i-1]+1))
			a[i]=a[i-1]+1;
		for(int j=1;j<=i && j*i<max;j++)
		{
			if(a[i*j]==-1 || (a[j*i]>a[i]+1))
				a[j*i]=a[i]+1;
		}
	}
	
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",a[x]);
	}
}
