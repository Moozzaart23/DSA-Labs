#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,a[1005][1005],b[1005][1005],ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            b[i][j]=a[i][j]+b[i-1][j]+b[i][j-1]-b[i-1][j-1];
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=0;k<i;k++)
                for(int l=0;l<j;l++)
                    if(b[i][j]-b[k][j]-b[i][l]+b[k][l]==1)
                        ans++;
    printf("%d",ans);                
    return 0;
}
