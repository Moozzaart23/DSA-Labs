#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int c=0;
int y=0;
void update(char b[]);
void rev(char b[])
{
	char a[1000];
	int l=strlen(b);
	for(int i=(l-1);i>=0;i--)
	{
		a[l-1-i]=b[i];
	}
	a[l++]='\0';
	if(y==0)
		printf("%s ",a);
	else
		update(a);
}
void update(char b[])
{
	int l=strlen(b);
	
	for(int i=0;i<l;i++)
	{
		if(c%2==0)
		{
			int x=b[i];
			if(y==0)
			{
				x=x+3;
				if(x>122)
					x=x-26;
			}
			else
			{
				x=x-3;
				if(x<97)
					x=x+26;
			}
			b[i]=(char)x;
		}
		c++;
		
	}
	if(y==0)
		rev(b);
	else
		printf("%s ",b);
}
int main()
{
	char a[1000];
	gets(a);
	int l=strlen(a);
	a[l]=' ';
	
	scanf("%d",&y);
	char b[1000];
	int t=0;
	for(int i=0;i<=l;i++)
	{
		if(a[i]==' ')
		{
			b[t++]='\0';
			if(y==0)
				update(b);
			else
				rev(b);
			char b[1000];
			t=0;
		}
		else
		{
			b[t++]=a[i];
		}
	}
}
