#include<stdio.h>
#include "findRowAndColumn.h"
void findRowAndColumn(int **ptr, int *Row, int *Col, int **start, int *ansRow, int *ansCol)
{
    int cnt=0;
    while(*(ptr+cnt)!=NULL)
    {
        int dist=*(ptr+cnt)-*(start+cnt);
        ansRow[cnt]=dist/Col[cnt];
        ansCol[cnt]=dist%Col[cnt];
        cnt++;
    }
}
