#include "mergesort.h"
#include <string.h>

void merge(int a[], int l, int m, int r)
{
    int i,j;
    static int aux[15];
    for(i = m+1; i>l; i--) aux[i-1] = a[i-1];
    for(j=m; j< r; j++) aux[r+m-j] = a[j+1];
    for (int k = l; k <= r; k++)
        if (aux[j] < aux[i])
            a[k] = aux[j--];
        else
            a[k] = aux[i++];
}

void mergesort (int a[], int l, int r)
{
    static int tmp[9];     memcpy(tmp,a,(r+1)*sizeof(int));//
    if (r<=l) return;
    int m = (r+l)/2;
    mergesort(a,l,m);       memcpy(tmp,a,(r+1)*sizeof(int));//
    mergesort(a,m+1,r);     memcpy(tmp,a,(r+1)*sizeof(int));//
    merge(a,l,m,r);         memcpy(tmp,a,(r+1)*sizeof(int));//
}

int min(int A, int B)
{
    return (A<B)? A:B;
}

void mergesortBU(int a[], int l, int r)
{
    static int tmp[9];
    memcpy(tmp,a,(r+1)*sizeof(int));//
    for(int m = 1; m <= r-l; m=m+m)
        for(int i=l;i<=r-m; i+=m+m)
        {
            merge(a,i,i+m-1,min(i+m+m-1,r));  memcpy(tmp,a,(r+1)*sizeof(int));//
        }
}

void mergeAlex(int out[], int a[], int aN, int b[], int bN)
{
    int k = 0;
    int p = 0;
    int index = 0;
    char eoa = 0;
    char eob = 0;
    while ( (!eoa) && (!eob))
    {
        if (a[k] < b[p])
        {
            out[index++] = a[k++];
            if (k==aN) eoa = 1;
        }
        else
        {
            out[index++] = b[p++];
            if (p==bN) eob = 1;
        }
    }
    if (eoa)
    {
        while (p<bN)
            out[index++] = b[p++];
    }
    else
    {
        while (k<aN)
            out[index++] = a[k++];
    }
}

void mergeSortAlex(int a[], int n)
{
    static int tmp[29];
    int l = n/2;
    if (l==1)
    {
        if (n==3)
        {
            mergeAlex(tmp+l,a+1,l,a+2,1);
            memcpy(a+1,tmp+l,sizeof(int)*2);
        }
        mergeAlex(tmp,a,l,a+l,n-l);
        memcpy(a,tmp,sizeof(int)*n);
        return;
    }
    mergeSortAlex(a,l);
    mergeSortAlex(a+l,n-l);
    mergeAlex(tmp,a,l,a+l,n-l);
    memcpy(a,tmp,sizeof(int)*n);
}


