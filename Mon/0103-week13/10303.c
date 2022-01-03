#include<stdio.h>
#include<assert.h>
#include<limits.h>
typedef long long ll;
ll solve(ll a[10][10],int sz){
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            printf("%lld",a[i][j]);
            if(j==sz-1)printf("\n");
            else printf(" ");
        }
    }
    if(sz==1) return a[0][0];
    ll ans=0,tmp[10][10];
    for(int i=0;i<sz;i++){
        for(int j=1;j<sz;j++){
            int b=0;
            for(int k=0;k<sz;k++){
                if(k==i) {
                    b=1;
                    continue;
                }
                tmp[j-1][k-b]=a[j][k];
            }
        }
        ll ret=solve(tmp,sz-1);
        //printf("ans=%d\n",ret);
        if(i%2) ans-=a[0][i]*ret;
        else ans+=a[0][i]*ret;
        assert(ans<=INT_MAX&&ans>=INT_MIN);
        assert(a[0][i]*ret<=INT_MAX&&a[0][i]*ret>=INT_MIN);
    }
    printf("determinant=%lld\n",ans);
    assert(ans<=INT_MAX&&ans>=INT_MIN);
    return ans;
}
int main()
{
    int n;
    ll a[10][10];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%lld",&a[i][j]);
            //a[i][j]=1;
        }
    }
    ll ans=solve(a,n);
    //printf("%d",ans);
}
