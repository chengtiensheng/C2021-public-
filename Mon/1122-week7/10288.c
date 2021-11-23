#include<stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    static int a[105][105][105];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++) a[i][j][k]=n*n*i+n*j+k;
        }
    }
    int type,r;
    while(m--)
    {
        scanf("%d %d",&type,&r);
        int tmp[105][105];
        if(type==0)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    tmp[j][n-1-i]=a[r][i][j];
                }
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    a[r][i][j]=tmp[i][j];
                }
            }
        }
        if(type==1)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    tmp[j][n-1-i]=a[i][j][r];
                }
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    a[i][j][r]=tmp[i][j];
                }
            }
        }

    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++) printf("%d ",a[i][j][k]);
            printf("\n");
        }
    }
}
