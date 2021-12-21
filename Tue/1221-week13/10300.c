#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int count(int a,int b,int op)
{
    if(op==1) return a+b;
    if(op==2) return a-b;
    if(op==3) return a*b;
    if(op==4) return a/b;
}
int isop(char c)
{
    if(c=='+')return 1;
    if(c=='-')return 2;
    if(c=='*') return 3;
    if(c=='/') return 4;
    return 0;
}
int expr(char *s,int mp[],int *valid)
{
    //printf("%d %d\n",sz,*valid);
    int sz=mp[0];
    if(*valid==0) return -1;
    if((s[0]!='(')||(s[sz-1]!=')'))
    {
        *valid=0;
        return -1;
    }
    int tmp1=0,tmp2=0;
    int op=0;
    if(s[1]=='(')
    {
        int cnt=1;
        op=isop(s[mp[1]+1]);
        if(op==0)
        {
            *valid=0;
            return -1;
        }
        tmp1=expr(s+1,mp+1,valid);
        tmp2=expr(s+mp[1]+2,mp+mp[1]+2,valid);
        if(mp[1]+2+mp[mp[1]+2]==sz-1)return count(tmp1,tmp2,op);
        *valid=0;
        return -1;
    }
    for(int i=1;i<sz-1;i++)
    {
        if(!isdigit(s[i])&&!isop(s[i]))
        {
            *valid=0;
            return -1;
        }
        if(isop(s[i]))
        {
            if(i==sz-2||i==1)
            {
                *valid=0;
                return -1;
            }
            op=isop(s[i]);
            for(int j=i+1;j<sz-1;j++)
            {
                if(!isdigit(s[j]))
                {
                    *valid=0;
                    return -1;
                }
                tmp2*=10;
                tmp2+=s[j]-'0';
            }
            return count(tmp1,tmp2,op);
        }
        tmp1=tmp1*10;
        tmp1+=s[i]-'0';
    }
    *valid=0;
    return -1;
}
int main()
{
    char s[1000005];
    static int mp[1000005],le[500005];
    while(scanf("%s",s)!=EOF)
    {
        //printf("%s",s);
        int sz=strlen(s),valid=1;
        for(int i=0;i<sz;i++) mp[i]=0;
        int cnt=0;
        for(int i=0;i<sz;i++)
        {
            if(s[i]=='(')
            {
                cnt++;
                le[cnt]=i;
            }
            if(s[i]==')')
            {
                mp[le[cnt]]=i-le[cnt]+1;
                cnt--;
            }
            if(cnt<0)
            {
                valid=0;
                break;
            }
        }
        //for(int i=0;i<sz;i++) printf("%d ",mp[i]);
        //printf("\n");
        if(cnt!=0)
        {
            printf("invalid\n");
            continue;
        }
        mp[0]=sz;
        int ret=expr(s,mp,&valid);
        if(valid==1)printf("%d\n",ret);
        else printf("invalid\n");
    }
}
