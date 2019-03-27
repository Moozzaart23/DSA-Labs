#include<stdio.h>
#define min(a,b) ((a<b)?a:b)
#define max(a,b) ((a>b)?a:b)

int a[1000],c[1000],n,m,sum=0;

int power(int x)
{
    if(x==0)
    {
        return 1;
    }
    else
    {
        return 2*power(x-1);
    }
}

int pro(int i)
{
    int t=sum/i;
    int b[n],p,j;
    int po=power(n),mini=100000;
    for(p=0;p<po;p++)
    {
        int s=0;
        for(j=0;j<n;j++)
        {
            if(p&(1<<j))
            {
                s++;
            }
        }
        if(s==i)
        {
            for(int h=0;h<n;h++)
            {
                b[h]=0;
            }
            for(j=0;j<n;j++)
            {
                if(p&(1<<j))
                {
                    b[j]=t;
                }
            }
            int su=0;
            for(j=0;j<n;j++)
            {
                su+=((max(a[j],b[j])-min(a[j],b[j]))*c[j]);
            }
            mini=min(mini,su);
        }
    }
    return mini;
}

int main()
{
    int i,mi=1000000,num=0,hi=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&c[i]);
    }
    for(i=1;i<=n;i++)
    {
        if(sum%i==0)
        {
            int val=pro(i);
            if(val<mi)
            {
                mi=val;
                num=i;
                hi=sum/i;
            }
        }
    }
    printf("%d, %d, %d\n",mi,num,hi);
    return 0;
}
