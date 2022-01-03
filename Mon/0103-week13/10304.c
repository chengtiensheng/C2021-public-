#include<stdio.h>
#include<memory.h>
#include<string.h>
int lwbit(int n){
    int cnt=0;
    while(!(n&1)){
        cnt++;
        n>>=1;
    }
    return cnt;
}
int main()
{

    int n;
    int cost[25]={0},bit[25]={0};
    int bt[21]={0};
    while(scanf("%d",&n)!=EOF){

        memset(cost,0,sizeof(cost));
        memset(bit,0,sizeof(bit));
        char s[55];
        for(int i=0;i<n;i++){
            scanf("%s",s);
            int l=strlen(s);
            for(int j=0;j<l;j++){
                int le=s[j]-'a';
                cost[i]+=le+1;
                bit[i]|=(1<<le);
            }
        }
        int minc=1e9;
        int cnt=0,cst=0;
        memset(bt,0,sizeof(bt));
        for(int i=1;i<(1<<n);i++){
            int t=lwbit(i);
            cnt+=(1-t);
            for(int j=t-1;j>=0;j--) cst-=cost[j];
            cst+=cost[t];
            for(int j=t;j>=0;j--) bt[j]=(bt[j+1]|bit[t]);
            if(bt[0]!=(1<<26)-1)continue;
            minc=minc<cst? minc:cst;
        }
        printf("%d\n",minc);
    }

}
