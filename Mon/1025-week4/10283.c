#include<stdio.h>
int main()
{
    int n,sum=0,prod=1,now=0;
    while(scanf("%d",&n))
    {
        if(n==0)
        {
            prod=now*prod;
            break;
        }
        if(n<=7)
        {
            now=now*10;
            now+=n;
            continue;
        }
        prod=now*prod;
        //printf("%d\n",prod);
        if(n==8)
        {
            sum=sum+prod;
            prod=1;
            now=0;
        }
        if(n==9) now=0;

        //printf("%d",sum);
    }
    sum=sum+prod;
    printf("%d",sum);
}
