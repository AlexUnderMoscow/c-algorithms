#include "bubble.h"
#include <string.h>

//void swap(int *a, int *b);

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

void bubble(int a[], int n)
{
    static int tmp[9];
    char change = 1;
    while(change)
    {
        change = 0;
        for (int i=0; i < (n-1); i++)
        {
         if (a[i]>a[i+1])
         {
             swap(a+i,a+i+1);  change = 1; 
         }
        }
    }
    return;
}
