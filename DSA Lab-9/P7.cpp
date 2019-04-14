#include <stdio.h>
#include <stdlib.h>
int n,m,s[1000],d[1000],fp[1000],t,src[1000],dest[1000],k[1000],ans;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void sort()
{
    for(int i=0;i<m;i++)
        for(int j=0;j<m-1;j++)
            if(s[j]>s[j+1])
            {
                swap(&s[j],&s[j+1]);
                swap(&d[j],&d[j+1]);
                swap(&fp[j],&fp[j+1]);
            }
}
void recurr(int src,int dest,int k,int i,int c,int sum)
{
    if(c>k)
        return;
    if(src==dest)
    {
        if(sum<ans)
            ans=sum;
    }
    while(s[i]!=src)
        i++;
    while(s[i]==src)
    {
        recurr(d[i],dest,k,i+1,c+1,sum+fp[i]);
        i++;
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&s[i],&d[i],&fp[i]);
    scanf("%d",&t);
    for(int i=0;i<t;i++)
        scanf("%d%d%d",&src[i],&dest[i],&k[i]);
    sort();
    printf("\n");
    for(int i=0;i<t;i++)
    {
         ans=9999;
         recurr(src[i],dest[i],k[i]+1,0,0,0);
         printf("%d\n",ans);
    }
    return 0;
}
