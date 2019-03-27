#include<stdio.h>
void sort(int a[],int n)
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
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int m;
	scanf("%d",&m);
	int xbox[100005];
	int ps[100005];
	int x,y=0;
	for(int i=0;i<m;i++)
	{
		xbox[i]=101;
		ps[i]=101;
	}
	for(int i=0;i<m;i++)
	{
		int cost;
		char item[10005];
		scanf("%d",&cost);
		gets(item);
		//puts(item);
		if(item[1]=='X')
			xbox[x++]=cost;
		else
			ps[y++]=cost;
		//printf("%d %d\n",x,y);
	}
	sort(xbox,x);
	sort(ps,y);
	/*for(int i=0;i<x;i++)
		printf("%d ",xbox[i]);
	printf("\n");
	for(int i=0;i<y;i++)
		printf("%d ",ps[i]);*/
	int ind1,ind2=0;
	int nos=0;
	int cost=0;
	for(int i=0;(i<a && ind2<y);i++)
	{
		nos++;
		ind2++;
		cost+=ps[i];
	}
	//printf("%d %d\n",nos,cost);
	for(int i=0;(i<b && ind1<x);i++)
	{
		nos++;
		ind1++;
		cost+=xbox[i];
	}
	//printf("%d %d\n",nos,cost);
	//printf("%d %d",ind1,ind2);
	int k=0;
	while((k<c)&&(ind1<x || ind2<y))
	{
		if(xbox[ind1]<=ps[ind2])
		{
			//printf("lol\n");
			//printf("%d\n",xbox[ind1]);
			cost+=xbox[ind1++];
		}
		else
		{
			//printf("lol2\n");
			//printf("%d\n",ps[ind2]);
			cost+=ps[ind2++];
		}
		k++;
		nos++;
	}
	printf("%d %d",nos,cost);
}
