#include<stdio.h>
int main()
{
    int nowr,nowc;
    char key[3][15]={"qwertyuiop","asdfghjkl","zxcvbnm"};
    char c;
    scanf("%c",&c);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<strlen(key[i]);j++)
        {
            if(key[i][j]==c)
            {
                nowr=i;
                nowc=j;
            }
        }
    }
    int t;
    int dr[6]={0,-1,-1,0,1,1},dc[6]={1,1,0,-1,-1,0};
    while(scanf("%d",&t)!=EOF)
    {
        nowr+=dr[t];
        nowc+=dc[t];
        if(nowr>2||nowr<0||nowr>=strlen(key[nowr])||nowr<0)
        {
            nowr-=dr[t];
            nowc-=dc[t];
            continue;
        }
        printf("%c\n",key[nowr][nowc]);
    }
}
