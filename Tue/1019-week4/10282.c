#include<stdio.h>
int l(int n)
{
    int cnt=0;
    while(n>0)
    {
        n/=10;
        //printf("%d\n",n);
        cnt++;
    }
    return cnt;
}
int main()
{
    int t=l(9999);
    int k,L,n;
    scanf("%d %d",&k,&L);
    int left=L;
    while(scanf("%d",&n)&&n!=0)
    {

        int times=n%k;
        int len=l(n);
        //printf("LEN:%d\n",len);
        if(left<len*times)
        {
            if(L<len*times) continue;
            printf("\n");

            for(int i=0;i<times;i++) printf("%d",n);
            left=L-len*times;
            continue;
        }
        for(int i=0;i<times;i++) printf("%d",n);
        left-=len*times;
    }
}

