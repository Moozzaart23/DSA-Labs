#include<stdio.h>
int main()
{
	char a[100005];
	gets(a);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int f,r,k;
		scanf("%d %d %d",&f,&r,&k);
		f=f-1;
		r=r-1;
		for(int j=0;j<k;j++)
		{
			char temp=a[r];
			for(int i=r;i>=(f+1);i--)
			{
				char t=a[i];
				a[i]=a[i-1];
			}
			a[f]=temp;
		}
	}
	puts(a);
}
