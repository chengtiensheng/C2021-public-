#include<stdio.h>
#include<memory.h>
#include<string.h>
int cnt=0;
int solve(char s1[],char s2[],char s3[],int sz1,int sz2,int sz3){
    cnt++;
    if(sz1<0||sz2<0||sz3<0) return -1;
    if(sz1*sz2*sz3<=0) return 0;
    int mx=0,ret;
    ret=solve(s1+1,s2+1,s3+1,sz1-1,sz2-1,sz3-1);
    if(s1[0]==s2[0]&&s2[0]==s3[0]){
        ret++;
        return ret ;
    }
    mx= mx>ret? mx:ret;
    int cnt1,cnt2,cnt3;
    for(int i=0;i<=sz2-mx;i++) {
        cnt2=i;
        if(s1[0]==s2[i]) {
            break;
        }
    }
    for(int i=0;i<=sz3-mx;i++) {
        cnt3=i;
        if(s1[0]==s3[i]) {
            break;
        }
    }
    ret=solve(s1+1,s2+cnt2+1,s3+cnt3+1,sz1-1,sz2-1-cnt2,sz3-1-cnt3)+1;
    mx= mx>ret? mx:ret;
    for(int i=0;i<=sz1-mx;i++) {
        cnt1=i;
        if(s2[0]==s1[i]) {
            break;
        }
    }
    for(int i=0;i<=sz3-mx;i++) {
        cnt3=i;
        if(s2[0]==s3[i]) {
            break;
        }
    }
    ret=solve(s1+1+cnt1,s2+1,s3+cnt3+1,sz1-1-cnt1,sz2-1,sz3-1-cnt3)+1;
    mx= mx>ret? mx:ret;
    for(int i=0;i<=sz1-mx;i++) {
        cnt1=i;
        if(s3[0]==s1[i]) {
            break;
        }
    }
    for(int i=0;i<=sz2-mx;i++) {
        cnt2=i;
        if(s3[0]==s2[i]) {
            break;
        }
    }
    ret=solve(s1+1+cnt1,s2+cnt2+1,s3+1,sz1-1-cnt1,sz2-1-cnt2,sz3-1)+1;
    mx= mx>ret? mx:ret;

    //printf("%s %s %s %d\n",s1,s2,s3,mx);
    return mx;
}
int main()
{
    char s1[15],s2[15],s3[15];
    while(scanf("%s %s %s",s1,s2,s3)!=EOF){
        printf("%d\n",solve(s1,s2,s3,strlen(s1),strlen(s2),strlen(s3)));
        printf("%d\n",cnt);
    }
}
