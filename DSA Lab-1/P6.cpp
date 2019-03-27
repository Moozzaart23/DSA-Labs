#include<stdio.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	int low=min(a,b);
	int high=max(a,b);
	while(low<=high)
	{
		int flag=0;
		for(int i=2;i<=(low/2);i++)
		{
			if(low%i==0)
			{
				flag=1;
				break;
			}
		}
			if(flag==0)
				printf("%d ",low);
			low++;
	}
	return 0;
}
