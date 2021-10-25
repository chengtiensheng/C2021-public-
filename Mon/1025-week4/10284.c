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

    while(scanf("%lld %lld %lld",&a,&b,&x))
    {
        while(1)
        {
            if(dig_num(x)<3)
            {
                printf("%lld\n",x);
                break;
            }

            x=(a*x)%b;
        }

    }
}
