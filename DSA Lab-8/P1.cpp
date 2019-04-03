#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,lptr,rptr,ind[1005][1005],start[1005],end[1005];
double med,a[100005],b[100005],c[100005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lf",&a[i]);
        b[i]=a[i];
    } 
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(a[i]>a[j])
            {
                int t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
    for(int i=0;i<1005;i++)
        for(int j=0;j<1005;j++)
            ind[i][j]=-1;
    for(int i=1;i<=n;i++)
        ind[(int)a[i]][end[(int)a[i]]++]=i;                
    lptr=(n+1)/2,rptr=(n+2)/2;
    med=(a[lptr]+a[rptr])/2;
    c[n]=med;
    for(int i=n;i>0;i--)
    {
        if(b[i]>med)
        {
            a[ind[(int)b[i]][start[(int)b[i]]++]]=-1;
            if(rptr>lptr)
                rptr=lptr;
            else
            {
                lptr--;
                while(a[lptr]==-1)
                    lptr--;
            }
        }
        else if(b[i]<med)
        {
            a[ind[(int)b[i]][start[(int)b[i]]++]]=-1;
            if(lptr<rptr)
                lptr=rptr;
            else
            {
                rptr++;
                while(a[rptr]==-1)
                    rptr++;
            }
        }
        else
        {
            a[ind[(int)b[i]][start[(int)b[i]]++]]=-1;
            if(lptr==rptr)
            {
                lptr--;
                rptr++;
                while(a[lptr]==-1)
                    lptr--;
                while(a[rptr]==-1)
                    rptr++;
            }
            else
                lptr++;
        }
        med=(a[lptr]+a[rptr])/2;
        c[i-1]=med;
    }
    for(int i=1;i<=n;i++)
        printf("%.1f\n",c[i]);
    return 0;
}
