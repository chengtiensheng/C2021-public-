#include<stdio.h>
int to_sec(int time)
{
    return time/10000*3600+(time%10000)/100*60+time%100;
}
int main()
{
    int now,prev;
    scanf("%d",&prev);
    int mindif=1e9;
    while(scanf("%d",&now)!=EOF)
    {
        int prev_sec=to_sec(prev);
        int now_sec=to_sec(now);
        int diff=(prev_sec>now_sec)? prev_sec-now_sec:now_sec-prev_sec;
        mindif=(mindif<diff)? mindif:diff;
        prev=now;
        //printf("%d",diff);
    }
    printf("%d",mindif);
}
