#include<stdio.h>
void sort(int *a,int l,int r)
{
    if(l>r) return ;
    for(int i=l;i<=r;i++)printf("%d ",a[i]);
    printf("\n");
    if(l==r) return ;
    int m=l+(r-l+1)/2;
    sort(a,l,m-1);
    sort(a,m,r);
    int tmp[r-l+10];
    int tmp1=l,tmp2=m,cnt=0;
    while(tmp1<m||tmp2<=r)
    {
        if(tmp1==m)
        {
            tmp[cnt]=a[tmp2];
            tmp2++;cnt++;
            continue;
        }
        if(tmp2==r+1)
        {
            tmp[cnt]=a[tmp1];
            tmp1++;cnt++;
            continue;
        }
        if(a[tmp1]<=a[tmp2])
        {
            tmp[cnt]=a[tmp1];
            cnt++;tmp1++;
            continue;
        }
        if(a[tmp2]<a[tmp1])
        {
            tmp[cnt]=a[tmp2];
            cnt++;tmp2++;
            continue;
        }
    }
    for(int i=0;i<=r-l;i++)
    {
        printf("%d ",tmp[i]);
        a[i+l]=tmp[i];
    }
    printf("\n");
}
int main()
{
    int n=0,a[100005];
    while(scanf("%d",&a[n])!=EOF)
    {
        n++;
    }
    sort(a,0,n-1);
}
