#include<stdio.h>
#include<string.h>
int main()
{
    char s[100005];
    int ans=0;
    while(scanf("%s",s)!=EOF)
    {
        int sz=strlen(s);
        char tmp[100005];
        int now=0;
        for(int i=0;i<=sz;i++)
        {
            if(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z')||('0'<=s[i]&&s[i]<='9')||s[i]=='_')
            {
                tmp[i-now]=s[i];
                //printf("%c",s[i]);
            }
            else
            {
                if(s[i]=='?')
                {
                    ans++;
                    now=i+1;
                    continue;
                }
                tmp[i-now]='\0';
                //printf("%s\n",tmp);
                if(strcmp(tmp,"while")==0||strcmp(tmp,"for")==0||strcmp(tmp,"if")==0||strcmp(tmp,"case")==0)
                {
                    ans++;
 
                }
                now=i+1;
                continue;
 
            }
        }
    }
    printf("%d",ans);
}
