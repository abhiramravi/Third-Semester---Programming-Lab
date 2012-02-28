/*
 * Abhiram CS10B060
 * Insertion sort
 */

#include "insertion_sort.h"

void insertion_sort( int n, int* arr )
{
    int j,i,key;
    for(j=0; j<n; j++)
    {
        key = arr[j];
        i = j-1;
        while(i>=0 && arr[i]>key)
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}


