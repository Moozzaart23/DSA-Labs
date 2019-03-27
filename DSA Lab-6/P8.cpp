#include<stdio.h>
#include<string.h>
int rr[4]={-1,0,0,1};
int cc[4]={0,-1,1,0};
char grid[100][100];
int n,m;
int check(int r,int c,int ind,char word[])
{
	int l=strlen(word);
	if(ind==l)
		return 1;
	if(r<0 || c<0 || r>=n || c>=m)
		return 0;
	if(grid[r][c]==word[ind])
	{
		int ans=check(r-1,c,ind+1,word)+
				check(r+1,c,ind+1,word)+
				check(r,c-1,ind+1,word)+
				check(r,c+1,ind+1,word);
		return ans;
	}
	else
	{
		return 0;
	}
}
int find(char word[])
{
	int l=strlen(word);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(grid[i][j]==word[0])
			{
				if(check(i,j,0,word))
				{
					return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf(" %c",&grid[i][j]);
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char a[100005];
		scanf("%s",&a);
		if(find(a))
			printf("Yes\n");
		else
			printf("No\n");
	}
}
