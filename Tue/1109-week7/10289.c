#include<stdio.h>
int main()
{
    int h,w;
    scanf("%d %d",&h,&w);
    int a[505][505]={0},t,x,y;
    while(scanf("%d %d %d",&t,&y,&x)!=EOF)
    {
        if(t==0)
        {
            a[x][y]=1;
            continue;
        }
        a[x][y]=1;
        if(t==1)
        {

            int dx[8]={-1,0,1,-1,1,-1,0,1};
            int dy[8]={-1,-1,-1,0,0,1,1,1};
            for(int i=0;i<8;i++)
            {
                int tmpx=x+dx[i],tmpy=y+dy[i];
                while(tmpx>=0&&tmpx<h&&tmpy>=0&&tmpy<w&&a[tmpx][tmpy]==0)
                {
                    a[tmpx][tmpy]=1;
                    tmpx+=dx[i];
                    tmpy+=dy[i];
                }
            }
        }
        if(t==2)
        {
            int dx[4]={-1,-1,1,1};
            int dy[4]={-1,1,-1,1};
            for(int i=0;i<4;i++)
            {
                int tmpx=x+dx[i],tmpy=y+dy[i];
                while(tmpx>=0&&tmpx<h&&tmpy>=0&&tmpy<w&&a[tmpx][tmpy]==0)
                {
                    a[tmpx][tmpy]=1;
                    tmpx+=dx[i];
                    tmpy+=dy[i];
                }
            }
        }
        if(t==3)
        {
            int dx[4]={-1,0,0,1};
            int dy[4]={0,-1,1,0};
            for(int i=0;i<4;i++)
            {
                int tmpx=x+dx[i],tmpy=y+dy[i];
                while(tmpx>=0&&tmpx<h&&tmpy>=0&&tmpy<w&&a[tmpx][tmpy]==0)
                {
                    a[tmpx][tmpy]=1;
                    tmpx+=dx[i];
                    tmpy+=dy[i];
                }
            }
        }

    }
    for(int i=0;i<h;i++)
        {
            for(int j=0;j<w;j++) printf("%d ",a[i][j]);
            printf("\n");
        }
}
