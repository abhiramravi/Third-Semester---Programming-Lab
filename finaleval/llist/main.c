/*
 * Author: <Your Name>
 * Linked list test program
 */

#include "LList.h"
#include <string.h>
#include <stdio.h>

#define BUF_SIZE 1024

// Reads a single integer argument from the string that's currently being
// parsed using strtok
// Returns 1 on success, and 0 on failure
int read_args1( int* arg1 );

// Reads two integer arguments from the string that's currently being
// parsed using strtok
// Returns 1 on success, and 0 on failure
int read_args2( int* arg1, int* arg2 );

int main( int argc, char* argv[] )
{
  int cmd;
  int loop = 1;

  LList* lst = llist_new();
  // In an infinite loop, get input from user
  do
  {
    scanf( "%d", &cmd );
    switch( cmd )
    {
      // Quit when you see this
      case -1:
        loop = 0;
        break;
      case 0: // count
      {
        printf( "%d\n", llist_size( lst ) );
        break;
      }
      case 1: 
      {
        // append <data>
        // Adds @data to the end of the list
       
        int data;
        if( read_args1( &data ) )
        {
          llist_append( lst, data );
        }
        break;
      }
      case 2: 
      {
        // prepend <data>
        // Adds @data to the beginning of the list
       
        int data;
        if( read_args1( &data ) )
        {
          llist_prepend( lst, data );
        }
        break;
      }
      case 3: 
      {
        // insert <index> <data> 
        // Inserts @data at position @index int the list
        
        int idx = 0;
        int data = 0;
        if( read_args2( &idx, &data ) )
        {
          llist_insert( lst, idx, data );
        }
        break;
      }
      case 4: 
      {
        // remove-last
        // Removes the last element in the list
        
        llist_remove_last( lst );
        break;
      }
      case 5: 
      {
        // remove-first
        // Removes the last element in the list
        
        llist_remove_first( lst );
        break;
      }
      case 6: 
      {
        // remove <index>
        // Removes the element in the @index-th element in the list
        
        int idx = 0;
        if( read_args1( &idx ) )
        {
          llist_remove( lst, idx );
        }
        break;
      }
      case 7: 
      {
        // print <index>
        // Prints the element at the @index-th element in the list
        int idx;
        if( read_args1( &idx ) )
        {
          printf( "%d\n", llist_get( lst, idx ) ); 
        }
        break;
      }
    }

    // Prints the whole list
    llist_print( lst );

  } while( loop );

  return 0;
}


// Reads a single integer argument from the string that's currently being
// parsed using strtok
// Returns 1 on success, and 0 on failure
int read_args1( int* arg1 )
{
  return scanf( "%d", arg1 );
}

// Reads two integer arguments from the string that's currently being
// parsed using strtok
// Returns 1 on success, and 0 on failure
int read_args2( int* arg1, int* arg2 )
{
 return  scanf( "%d %d", arg1, arg2 );
}

