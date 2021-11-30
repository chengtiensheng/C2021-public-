#include<stdio.h>
int main()
{
    int n,sum=0,prod=1,now=0;
    int ma[256];
    for(int i=0;i<255;i++) ma[i]=-1;
    ma['!']=1;
    ma['@']=2;
    ma['#']=3;
    ma['$']=4;
    ma['%']=5;
    ma['^']=6;
    ma['&']=7;
    ma['(']=9;
    ma[')']=0;

    //const char *s="!@#$%^&";
    char c;
    while(scanf("%c",&c)!=EOF)
    {
        //
        if(ma[c]!=-1)
        {
            printf("%d %d\n",ma[c],now);
            now=now*10;
            now+=ma[c];
            continue;
        }
        prod=now*prod;
        printf("%d\n",prod);
        if(c=='+')
        {
            sum=sum+prod;
            prod=1;
            now=0;
        }
        if(c=='*') now=0;

        //printf("%d",sum);
    }
    sum=sum+prod*now;
    printf("%d",sum);
}
