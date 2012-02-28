/*
 * Abhiram CS10B060
 * Partition
 */

#include <stdio.h>
#include <stdlib.h>

void partition( int n, int* arr )
{
  int i;
  int j;
  int check = 0;
  for( i=0; i<n; i++ )
  {
    if( arr[i] == 0 )  //If the element is 0, move it to the extreme left
    {
        j = i-1;
        while( j>=0 && arr[j]>=0 )
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[0] = 0;
    }
    if( arr[i] == 2 ) //If the element is 2, move it to the extreme right. Shift back the pointer one step if necessary
    {
        j = i;
        while( j < n )
        {
            arr[j] = arr[j+1];
            j++;
        }
        arr[n-1] = 2;
        if( check < n )
        {
            i--; check++;
        }
    }   
  }
}

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

  partition( n, arr );
  print_array( n, arr );
  
  return 0;
}

