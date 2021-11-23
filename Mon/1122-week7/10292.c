#include<stdio.h>
int mx(int a,int b,int c)
{
    int r=a;
    a=a>b? a:b;
    a=a>c? a:c;
    return a;
}
int main()
{
    int n;
    scanf("%d",&n);
    int h[100005]={0};
    int t,x;
    while(scanf("%d %d",&x,&t)!=EOF)
    {
        int dx[4][3]={{0,1,1},{0,0,-1},{0,0,0},{0,1,0}};
        int ad[4][3]={{1,1,0},{1,2,2},{1,2,1},{1,1,1}};
        for(int i=0;i<4;i++)
        {
            if(t==i)
            {
                int tmph=mx(h[x],h[x+1]+dx[t][1],h[x+2]+dx[t][2]);
                h[x]=tmph+ad[t][0];
                h[x+1]=tmph+ad[t][1];
                h[x+2]=tmph+ad[t][2];
            }
        }/*
        if(t==0)
        {
            int tmph=h[x];
            tmph=(h[x+1]+1)>tmph? h[x+1]+1:tmph;
            tmph=(h[x+2]+1)>tmph? h[x+2]+1:tmph;
            h[x]=tmph+1;
            h[x+1]=tmph+1;
            h[x+2]=tmph;
        }
        if(t==1)
        {
            int tmph=h[x];
            tmph=(h[x+1])>tmph? h[x+1]:tmph;
            tmph=(h[x+2]-1)>tmph? h[x+2]-1:tmph;
            h[x]=tmph+1;
            h[x+1]=tmph+2;
            h[x+2]=tmph+2;
        }
        if(t==2)
        {
            int tmph=h[x];
            tmph=(h[x+1])>tmph? h[x+1]:tmph;
            tmph=(h[x+2])>tmph? h[x+2]:tmph;
            h[x]=tmph+1;
            h[x+1]=tmph+2;
            h[x+2]=tmph+1;
        }
        if(t==3)
        {
            int tmph=h[x];
            tmph=(h[x+1]+1)>tmph? h[x+1]+1:tmph;
            tmph=(h[x+2])>tmph? h[x+2]:tmph;
            h[x]=tmph+1;
            h[x+1]=tmph+1;
            h[x+2]=tmph+1;
        }*/
        //for(int i=0;i<n;i++) printf("%d ",h[i]);
        //printf("\n");
    }
    for(int i=0;i<n;i++) printf("%d ",h[i]);
}
