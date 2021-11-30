# include<stdio.h>
# include<stdlib.h>
#include "multiply.h"
void multiplyMatrix(void ** arrayA, void ** arrayB, void ** arrayC)
{
    A* tmpA;
    B* tmpB;
    C* tmpC;

    int cnt=0;
    while(*(arrayA+cnt)!=NULL)
    {
        //printf("QQ");
        tmpA=*(arrayA+cnt);
        tmpB=*(arrayB+cnt);
        tmpC=*(arrayC+cnt);
        for(int i=0;i<ROW;i++)
        {
            for(int j=0;j<ROW;j++)
            {
                (*tmpC)[i][j]=0;
                for(int k=0;k<COL;k++)
                {
                    (*tmpC)[i][j] +=(*tmpA)[i][k]* (*tmpB)[k][j] ;
                }
                //printf("%d ",(*tmpC)[i][j]);
            }
            //printf("\n");
        }
        cnt++;
    }
}
void printAns(void ** arrayA,int siz)
{
    C* tmpC;
    int cnt=0;
    while(*(arrayA+cnt)!=NULL)
    {
        //printf("QQ");
        tmpC=*(arrayA+cnt);
        for(int i=0;i<ROW;i++)
        {
            for(int j=0;j<ROW;j++)
            {
                printf("%d ",(*tmpC)[i][j]);
            }
            printf("\n");
        }
        cnt++;
    }
}

