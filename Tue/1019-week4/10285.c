#include<stdio.h>
int main()
{
    int max1=0,max2=0,max3=0,sec1=0,sec2=0,sec3=0,prev1=0,prev2=0,prev3=0,cnt=0,n,maxpos1=0,maxpos2=0,maxpos3=0,secpos1=0,secpos2=0,secpos3=0,;
    while(scanf("%d",&n)!=EOF)
    {
        cnt++;
        if(n==1&&prev1>0)
        {
            int dst=cnt-prev1;
            if(dst>max1)
            {
                sec1=max1;
                secpos1=maxpos1;
                max1=dst;
                maxpos1=cnt;
                prev1=cnt;
                continue;
            }
            if(dst==max1)
            {
                maxpos1=cnt;
                prev1=cnt;
                continue;
            }
            if(dst>sec1)
            {
                sec1=dst;
                secpos1=cnt;
            }
            if(dst==sec1) secpos1=cnt;
            prev1=cnt;
            continue;
        }
        else if(n==1)prev1=cnt;
        if(n==2&&prev2>0)
        {
            int dst=cnt-prev2;
            if(dst>max2)
            {
                sec2=max2;
                secpos2=maxpos2;
                max2=dst;
                maxpos2=cnt;
                prev2=cnt;
                continue;
            }
            if(dst==max2)
            {
                maxpos2=cnt;
                prev2=cnt;
                continue;
            }
            if(dst>sec2)
            {
                sec2=dst;
                secpos2=cnt;
            }
            if(dst==sec2) secpos2=cnt;
            prev2=cnt;
            continue;
        }
        else if(n==2) prev2=cnt;
        if(n==3&&prev3>0)
        {
            int dst=cnt-prev3;
            if(dst>max3)
            {
                sec3=max3;
                secpos3=maxpos3;
                max3=dst;
                maxpos3=cnt;
                prev3=cnt;
                continue;
            }
            if(dst==max3)
            {
                maxpos3=cnt;
                prev3=cnt;
                continue;
            }
            if(dst>sec3)
            {
                sec3=dst;
                secpos3=cnt;
            }
            if(dst==sec3) secpos3=cnt;
            prev3=cnt;
            continue;
        }
        else if(n==3)prev3=cnt;
    }
    printf("%d %d %d\n",sec1,secpos1-sec1-1,secpos1-1);
    printf("%d %d %d\n",sec2,secpos2-sec2-1,secpos2-1);
    printf("%d %d %d\n",sec3,secpos3-sec3-1,secpos3-1);
}
