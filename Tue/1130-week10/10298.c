#include<stdio.h>
int main()
{
    char s[10005];
    int cnt[26][26][26]={0};
    while(scanf("%s",&s)!=EOF)
    {
        int t=strlen(s);
        for(int i=0;i<=t-3;i++)
        {
            cnt[s[i]-'a'][s[i+1]-'a'][s[i+2]-'a']++;
        }
    }

    int posa,posb,posc;
    int mx=0;
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            for(int k=0;k<26;k++)
            {
                if(cnt[i][j][k]>mx)
                {
                    //printf("%d\n",cnt[i][j][k]);
                    mx=cnt[i][j][k];
                    posa=i;
                    posb=j;
                    posc=k;
                }
            }
        }
    }
    printf("%c%c%c\n",posa+'a',posb+'a',posc+'a');
    cnt[posa][posb][posc]=0;
    mx=0;
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            for(int k=0;k<26;k++)
            {
                if(cnt[i][j][k]>mx)
                {
                    mx=cnt[i][j][k];
                    posa=i;
                    posb=j;
                    posc=k;
                }
            }
        }
    }
    printf("%c%c%c\n",posa+'a',posb+'a',posc+'a');
    cnt[posa][posb][posc]=0;
    mx=0;
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<26;j++)
        {
            for(int k=0;k<26;k++)
            {
                if(cnt[i][j][k]>mx)
                {
                    mx=cnt[i][j][k];
                    posa=i;
                    posb=j;
                    posc=k;
                }
            }
        }
    }
    printf("%c%c%c",posa+'a',posb+'a',posc+'a');
}
