#include<stdio.h>
int main()
{
    char fname[3][2000];

    for(int i=0;i<3;i++)scanf("%s",fname[i]);
    FILE *f1,*f2,*fout;
    f1=fopen(fname[0],"rb");
    f2=fopen(fname[1],"rb");
    fout=fopen(fname[2],"w+b");
    int cnt=0;
    char tmp;
    //fprintf(stderr,"finish_open\n");
    int N1,N2,N;
    fseek(f1,40,SEEK_SET);
    fread(&N1,4,1,f1);
    fseek(f2,40,SEEK_SET);
    fread(&N2,4,1,f2);
    N=N1+N2;
    //fprintf(stderr,"%x %x %x\n",N1,N2,N);
    //fprintf(stderr,"%d %d\n",N1,N2,N);
    int rlen=0;
    fseek(f1,0,SEEK_SET);
    while(rlen=fread(&tmp,1,1,f1)){
        if(cnt>=4&&cnt<8){
            //fprintf(stderr,"%x\n",tmp);
            tmp=(((N+36)>>((cnt-4)*8))&((1<<8)-1));
            //fprintf(stderr,"%x\n",tmp);
            fwrite(&tmp,1,1,fout);
            cnt++;
            continue;
        }
        if(cnt>=40&&cnt<44){
            tmp=((N)>>((cnt-40)*8))&((1<<8)-1);
            fwrite(&tmp,1,1,fout);
            cnt++;
            if(cnt==44) break;
            continue;
        }
        fwrite(&tmp,1,1,fout);
        cnt++;

    }
    //fprintf(stderr,"finish_open\n");
    char buf[10005];
    fseek(f1,44,SEEK_SET);
    while(rlen=fread(buf,1,10000,f1)){
        fwrite(buf,1,rlen,fout);
        //fprintf(stderr,"ppp\n");
    }
    fseek(f2,44,SEEK_SET);
    while(rlen=fread(buf,1,10000,f2)){
        fwrite(buf,1,rlen,fout);
        //fprintf(stderr,"ppp\n");
    }
    //fprintf(stderr,"finish_open\n");
    int t;
    fseek(f1,44,SEEK_SET);
    fseek(f2,44,SEEK_SET);
    fseek(fout,44,SEEK_SET);
    for(int i=0;i<44;i++){
        char tmp;
        fread(&tmp,1,1,f2);
        //printf("%x ",tmp);
        fread(&tmp,1,1,fout);
        //printf("%x\n",tmp);
    }
}
