#include<stdio.h>
#include<string.h>
char a[100005];
char b[100005];
int call()
{
	int t=0;
	for(int i=0;i<strlen(a);i++)
	{
		if(a[i]==b[t])
			t++;
	}
	return t;
}
int main()
{
	gets(a);
	gets(b);
	int l=strlen(a);
	int l1=strlen(b);
	int t;
	int arr[100005]={0};
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&arr[i]);
	}
	int i=0;
	for(i=0;i<t;i++)
	{
		int x=arr[i];
		x=x-1;
		a[x]='#';
		int m=call();
		if(m!=strlen(b))
			break;
	}
	printf("%d ",(i));
}
