#include<stdio.h>
int s[100005];
int s1[100005];
int top=-1;
int top1=-1;
int min=0;
int isempty()
{
	if(top<0)
		return 1;
	else
		return 0;
}
void push(int x)
{
	if(isempty())
	{
		//min=x;
		s[++top]=x;
		s1[++top1]=x;
		return;
	}
	s[++top]=x;
	int min=s1[top1];
	if(x<s1[top1])
	{
		s1[++top1]=x;
		//min=x;
	}
	else
		s1[++top1]=min;
}
int pop()
{
	int x=top;
	top=top-1;
	top1=top1-1;
	return s[x];
}
int getmin()
{
	return s1[top1];
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int m;
		printf("0 for push,1 for pop, 2 for min element\n");
		scanf("%d",&m);
		switch(m)
		{
			case 0:
			{
				int x;
				printf("Enter element to be pushed\n");
				scanf("%d",&x);
				push(x);
				break;
			}
			case 1:
			{
				int a=pop();
				printf("Popped elemeny is %d\n",a);
				break;
			}
			case 2:
			{
				printf("Minimum element is %d\n",getmin());
				//getmin();
				break;
			}
			default:
				printf("Wrong Choice\n");
		}
	}
}
