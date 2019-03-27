#include<stdio.h>
#include<string.h>
int main()
{
	char a[100005];
	char b[100005];
	gets(a);
	int l=strlen(a);
	for(int i=0;i<l;i++)
	{
		if(a[i]==' ')
		{
			b[i]=' ';
			continue;
		}
		int x=a[i];
		if(x>=65 && x<=90)
		{
			x=x+3;
			if(x>90)
				x=x-26;
		}
		if(x>=97 && x<=122)
		{
			x=x+3;
			if(x>122)
				x=x-26;
		}
		b[i]=char(x);
	}
	puts(b);
}
