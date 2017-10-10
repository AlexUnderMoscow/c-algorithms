#include <string.h>
#include "selection.h"

void selection(int a[], int n)
{ 
    int min;
    int index =0;
    for (int i = 1; i<n; i++ )
    {
        min = a[i-1];
        for (int j=i; j<n; j++)
        {
            if (a[j]< min)
            {
                min = a[j];
                index = j;
            }
        }
        swap(a+index,a+i-1);  
    }
}
