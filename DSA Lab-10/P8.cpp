#include<stdio.h>

int main()
{
    int n,i,j,k;
    scanf("%d%d",&n,&k);
    char p[n+1];
    int a[n],vis[n];
    for(i=0;i<n;i++)
    {
        vis[i]=0;
    }
    scanf("%s",p);
    for(j=0;j<k;j++)
    {
        int t=0,dif=0,ct=0;
        for(i=0;i<n;i++)
        {
            if(vis[i])
            {
                if(ct>dif)
                {
                    dif=ct;
                    t=i;
                    ct=0;
                }
            }
            else
            {
                ct++;
            }
        }
        if(ct>dif)
        {
            dif=ct;
            t=i;
        }
        if(dif%2==1)
        {
            a[t-((dif+1)/2)]=j+1;
            vis[t-((dif+1)/2)]=1;
        }
        else
        {
            if(p[j]=='L')
            {
                a[t-((dif/2)+1)]=j+1;
                vis[t-((dif/2)+1)]=1;
            }
            else
            {
                a[t-(dif/2)]=j+1;
                vis[t-(dif/2)]=1;
            }
        }
    }
    int q;
    scanf("%d",&q);
    int r[q];
    for(i=0;i<q;i++)
    {
        int x;
        scanf("%d",&x);
        if(vis[x-1])
        {
            r[i]=a[x-1];
        }
        else
        {
            r[i]=-1;
        }
    }
    for(i=0;i<q;i++)
    {
        printf("%d\n",r[i]);
    }
    return 0;
}
