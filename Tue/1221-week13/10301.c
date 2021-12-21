#include<stdio.h>
unsigned int solve(unsigned int c,int l,int r)
{
    //printf("%u %d %d %d\n",c,l,r);
    if(l+1==r)return c;
    int cnt=0;
    for(int i=0;i<r-l;i++)
    {
        if(c&(1<<i)) cnt++;
    }
    //printf("%u %d %d %d\n",c,l,r,cnt);
    int m=l+(r-l)/2;
    if(cnt%2)
    {
        return (solve(c%(1<<(m-l)),m,r)<<(m-l))+solve(c>>(m-l),l,m);
    }
    else return (solve(c>>(m-l),l,m)<<(m-l))+solve(c%(1<<(m-l)),m,r);
}
int main()
{
    unsigned int s;
    scanf("%u",&s);
    printf("%u",solve(s,0,32));
}
