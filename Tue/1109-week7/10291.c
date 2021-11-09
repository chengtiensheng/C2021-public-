#include<stdio.h>

int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int a[605][605];
    for(int i=r-1;i>=0;i--)
    {
        for(int j=0;j<c;j++) scanf("%d",&a[i][j]);
    }
    int type,len;
    while(scanf("%d %d",&type,&len)!=EOF)
    {
        if(type==1)
        {
            for(int i=1;i<=len;i++)
            {
                for(int j=0;j<c;j++)
                {
                    a[r-2*len-1+i][j]+=a[r-i][j];
                }
            }
            r-=len;
        }
        if(type==2)
        {
            for(int j=1;j<=len;j++)
            {
                for(int i=0;i<r;i++)
                {
                    a[i][c-2*len-1+j]+=a[i][c-j];
                }
            }
            c-=len;
        }

        if(type==3)
        {
            for(int i=1;i<len;i++)
            {
                for(int j=1;i+j<=len;j++)
                {
                    a[r-len-1+j][c-len-1+i]+=a[r-i][c-j];
                    a[r-i][c-j]=0;
                }
            }
        }
    }
    for(int i=r-1;i>=0;i--)
    {
        for(int j=0;j<c;j++) printf("%d ",a[i][j]);
        printf("\n");
    }
}
