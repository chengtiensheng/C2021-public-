#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int dig_num(long long t)
{
    bool app[10]={0};
    while(t>0)
    {
        app[t%10]=1;
        t/=10;
    }
    int cnt=0;
    for(int i=0;i<10;i++) if(app[i])cnt++;
    return cnt;
}
int main()
{
    long long a,b,x;

    while(scanf("%lld %lld %lld",&a,&b,&x)!=EOF)
    {
        while(1)
        {
            int tmp=x;
            int dg1=tmp%10,dg2=-1;

            bool fin=1;
            while(tmp>0)
            {
                //printf("%d\n",&tmp);
                if(dg1==tmp%10)
                {
                    tmp/=10;
                    continue;
                }
                if(dg2==tmp%10)
                {
                    tmp/=10;
                    continue;
                }
                if(dg2==-1)
                {
                    dg2=tmp%10;
                    tmp/=10;
                    continue;
                }
                fin=0;
                tmp/=10;
            }
            if(fin)
            {
                printf("%lld\n",x);
                break;
            }

            x=(a*x)%b;
        }

    }
}
