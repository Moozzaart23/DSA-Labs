#include<stdio.h>
#include<string.h>
int main()
{
	char a[100005];
	int freq[26]={0};
	gets(a);
	int l=strlen(a);
	for(int i=0;i<l;i++)
	{
		freq[a[i]-'a']++;
	}
	int e=0;int o=0;
	for(int i=0;i<26;i++)
	{
		if(freq[i]%2==0)
			e++;
		else
			o++;
	}
	if(o>1)
		printf("No");
	else
		printf("Yes");
}
