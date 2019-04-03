#include<stdio.h>
#include<string.h>
char s[100005];
int top=-1;
void push(char x)
{
	s[++top]=x;
}
void pop()
{
	top=top-1;
}
char front()
{
	return s[top];
}
int isempty()
{
	if(top<0)
		return 1;
	else
		return 0;
}
int main()
{
	char c[100005];
	scanf("%s",&c);
	int i=0;
	for(i=0;i<strlen(c);i++)
	{
		if(c[i]=='(' || c[i]=='{' || c[i]=='[')
			push(c[i]);
		else if(c[i]==')' || c[i]=='}' || c[i]==']')
		{
			char x=front();
			if((x=='(') && (c[i]=='}' || c[i]==']'))
			{
				printf("No");
				return 0;
			}
			if((x=='{') && (c[i]==')' || c[i]==']'))
			{
				printf("No");
				return 0;
			}
			if((x=='[') && (c[i]=='}' || c[i]==')'))
			{
				printf("No");
				return 0;
			}
			pop();
		}
	}
	//printf("%d",top);
	if(isempty())
		printf("Yes");
	else
		printf("No");
}
