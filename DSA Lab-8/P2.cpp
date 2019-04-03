#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int n,a[20],b[20],vis[20],arr[20],p;
double ans=1e9;

void rec(int x,int y)
{
    if(y>n)
        return;
    vis[x]=1;
    arr[p++]=x;
    if(y==n)
    {
        int tans=0,t=0;
        for(int i=1;i<=n;i++)
        {
            tans+=max(0,t-a[arr[i]])+b[arr[i]];
            t=max(a[arr[i]],t)+b[arr[i]];
        }
        ans=min(ans,tans);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            rec(i,y+1);
            vis[i]=0;
            p--;
        }   
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]);
    rec(0,0);
    printf("%lf",ans/n);
    return 0;
}
