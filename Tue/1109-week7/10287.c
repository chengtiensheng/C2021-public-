#include<stdio.h>
int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int a[1005][1005];
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++) scanf("%d",&a[i][j]);
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            int cnt=0;
            if(j>0&&a[i][j-1]==a[i][j]) cnt++;
            if(i>0&&a[i-1][j]==a[i][j]) cnt++;
            if(j<c-1&&a[i][j+1]==a[i][j]) cnt++;
            if(i<r-1&&a[i+1][j]==a[i][j]) cnt++;
            if(cnt>=2)
            {
                if(j>0&&a[i][j-1]==a[i][j]) a[i][j-1]=0;
                if(i>0&&a[i-1][j]==a[i][j]) a[i-1][j]=0;
                if(j<c-1&&a[i][j+1]==a[i][j]) a[i][j+1]=0;
                if(i<r-1&&a[i+1][j]==a[i][j]) a[i+1][j]=0;
                a[i][j]=0;
            }
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++) printf("%d ",a[i][j]);
        printf("\n");
    }
}
