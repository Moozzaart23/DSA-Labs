#include<stdio.h>
#include<string.h>
typedef struct Key
{
	char c;
	int f;
}key;
key s[100005];
int front=0;int rear=0;
int isempty()
{
	if(front>=rear)
		return 1;
	else
		return 0;
}
void push(key k)
{
	if(isempty())
	{
		s[rear].c=k.c;
		s[rear].f=k.f;
		rear=rear+1;
		return;
	}
	int n=rear-front;
	int ind=-1;
	int y=k.f;
	for(int i=front;i<rear;i++)
	{
		if(s[i].f>=y)
			ind=i;
	}
	ind=ind+1;
	if(ind<front)
	{
		front=front-1;
		s[front].c=k.c;
		s[front].f=k.f;
		return;
	}
	rear=rear+1;
	for(int i=rear;i>ind+1;i--)
	{
		s[i-1].f=s[i-2].f;
		s[i-1].c=s[i-2].c;
	}
	s[ind].c=k.c;
	s[ind].f=k.f;
	return;
}
void pop()
{
	front=front+1;
}
key front1()
{
	return s[front];
}
int main()
{
	char a[100005];
	scanf("%s",a);
	int c[26]={0};
	for(int i=0;i<strlen(a);i++)
	{
		c[a[i]-'a']++;
	}
	for(char x='a';x<='z';x++)
	{
		if(c[x-'a'])
		{
			key k={x,c[x-'a']};
			push(k);
		}
	}
	char ans[100005];int u=0;
	key p={'#',-1};
	while(!isempty())
	{
		key k=front1();
		pop();
		ans[u++]=k.c;
		//printf("Front= %c %d\n",k.c,k.f);
		//printf("Prev= %c %d\n",p.c,p.f);
		if(p.f>0)
			push(p);
		k.f=k.f-1;
		p=k;
	}
	if(strlen(a)!=u)
		printf("Not Possible");
	else 
		printf("%s",ans);
}
