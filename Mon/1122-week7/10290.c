#include<stdio.h>
int main()
{
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int a[205][205];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    }
    int maxsum=0;
    for(int i=k;i<=n-k+1;i++)
    {
        for(int j=k;j<=m-k+1;j++)
        {
            int sum=0;
            for(int l=1;l<k;l++)
            {
                sum+=a[i-l][j-k+1+l];
                sum+=a[i-k+1+l][j+l];
                sum+=a[i+l][j+k-1-l];
                sum+=a[i+k-1-l][j-l];
            }
            //printf("%d ",sum);
            maxsum=maxsum>sum? maxsum:sum;
        }
    }
    printf("%d",maxsum);
}
