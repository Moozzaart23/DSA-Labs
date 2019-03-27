#include<stdio.h>
#include<string.h>
int l=0;
char ans[100005];
int  check(char b[])
{
	int l=strlen(b);
	int n=strlen(b);
	if(l%2==0)
		l=l/2;
	else
		l=(l/2)+1;
	for(int i=0;i<l;i++)
	{
		if(b[i]!=b[n-i-1])
			return 0;
	}
	return 1;
}
int check1(char b[])
{
	int l=strlen(b);
	int n=strlen(b);
	if(l%2==0)
		l=l/2;
	else
		l=(l/2)+1;
	for(int i=0;i<l-1;i++)
	{
		if(b[i+1]-b[i]<0)
			return 0;
	}
	return 1;
}
void change(char b[])
{
	int n=strlen(b);
	for(int i=0;i<n;i++)
	{
		ans[i]=b[i];
	}
}
int main()
{
	char a[100005];
	scanf("%s",&a);
	//printf("%s\n",a);
	int n=strlen(a);
	for(int i=0;i<=(n-2);i++)
	{
		for(int j=i+2;j<n;j++)
		{
			char b[10005]={'0'};int t=0;
			for(int k=i;k<=j;k++)
			{
				b[t++]=a[k];
			}
			//printf("%s\n",b);
			//printf("%d %d\n",check(b),check1(b));
			if(check(b) && check1(b))
			{
				//printf("%s\n",b);
				int n=strlen(b);
				if(n>l)
				{
					//ans=b;
					for(int i=0;i<n;i++)
					{
						ans[i]=b[i];
					}
					l=n;
				}
				else if(n==l)
				{
					int i;
					for(i=0;i<n;i++)
					{
						if(ans[i]!=b[i] && b[i]<ans[i])
						{
							change(b);
						}
					}
					
				}
			}
		}
	}
	if(l!=0)
		printf("%s",ans);
	else
		printf("-1");
}
