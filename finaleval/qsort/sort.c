/*
 * Name (Rollno)
 * Insertion Sort Main
 */

#include "qsort.h"
#include <stdio.h>
#include <stdlib.h>

void print_array( int n, int* arr )
{
  int i;
  for( i = 0; i < n; i++ )
  {
    printf( "%d ", arr[i] );
  }
  printf( "\n" );
}

int main()
{
  int i, n;
  int* arr;
  // Read a count n, and a stream of integers
  scanf( "%d", &n );
  arr = (int*) malloc( sizeof(int) * n );
  for( i = 0; i < n; i++ )
    scanf( "%d", &arr[i] );

  QSort( n, arr );
  print_array( n, arr );
  
  return 0;
}

