/*
 * Name (Rollno)
 * Mergesort Main
 */

#include "mergesort.h"
#include <stdio.h>
#include <stdlib.h>

void print_array( int n, int* arr )
{
  int i;
  for( i = 1; i <= n; i++ )
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
  arr = (int*) malloc( sizeof(int) * (n+2) );
  for( i = 1; i < n+1; i++ )
    scanf( "%d", &arr[i] );

  mergesort( n, arr );
  print_array( n, arr );
  
  return 0;
}

