/*
 * Author: Abhiram R - CS10B060
 * Linked list test program
 */

#include "LList.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int read_args1( int* arg1 );

int read_args2( int* arg1, int* arg2 );

int main( int argc, char* argv[] )
{
    char cmd[ BUF_SIZE ];
    LList* lst = llist_new();
    while( 1 )
    {
        char* op = NULL; 
        // Get a line of input from the user
        fgets( cmd, BUF_SIZE, stdin );
        // Parse the line using strtok
        op = strtok( cmd, " " );
        // If the last line is a new line, make it a null character
        int len = strlen( op );
        if( op[ len-1 ] == '\n' )
          op[ len-1 ] = 0;

        if( strcmp( op, "quit" ) == 0 || op[0] == EOF )
        {
          exit(EXIT_SUCCESS);
        }
        else if( strcmp( op, "count" ) == 0 )
        {
          
          printf( "%d\n", llist_size( lst ) );
          
        }
        else if( strcmp( op, "append" ) == 0 )
        {
          // append <data>
          // Adds @data to the end of the list
         
          int data;
          if( read_args1( &data ) )
          {
            llist_append( lst, data );
          }
        }
        else if( strcmp( op, "prepend" ) == 0 )
        {
          // prepend <data>
          // Adds @data to the front of the list
          
          int data;
          if( read_args1( &data ) )
          {
            llist_prepend( lst, data );
          }
        }
        else if( strcmp( op, "insert" ) == 0 )
        {
          // insert <index> <data> 
          // Inserts @data at position @index int the list
          
          int idx = 0;
          int data = 0;
          if( read_args2( &idx, &data ) )
          {
            llist_insert( lst, idx, data );
          }
        }
        else if( strcmp( op, "remove-last" ) == 0 )
        {
          llist_remove_last( lst );
        }
        else if( strcmp( op, "remove-first" ) == 0 )
        {
          llist_remove_first( lst );
        }
        else if( strcmp( op, "remove" ) == 0 )
        {
          // remove <index>
          // Removes the element in the @index-th element in the list
          
          int idx = 0;
          if( read_args1( &idx ) )
          {
           llist_remove( lst, idx );
          }
        }
        else if( strcmp( op, "print" ) == 0 )
        {
          // print <index>
          // Prints the element at the @index-th element in the list
          int idx;
          if( read_args1( &idx ) )
          {
              printf( "%d\n", llist_get( lst, idx ) ); 
          }
        }
        else
        {
            printf( "Invalid command\n" );
        }

        llist_print( lst );
    }

    return 0;
}


// Reads a single integer argument from the string that's currently being
// parsed using strtok
// Returns 1 on success, and 0 on failure
int read_args1( int* arg1 )
{
  char* arg1_str = strtok( NULL, " " );
  if( arg1_str == NULL )
  {
    printf( "Expected 1 argument\n" );
    return 0;
  }
  else
  {
    sscanf( arg1_str, "%d", arg1 );
    return 1;
  }
}

// Reads two integer arguments from the string that's currently being
// parsed using strtok
// Returns 1 on success, and 0 on failure
int read_args2( int* arg1, int* arg2 )
{
  char* arg1_str = strtok( NULL, " " );
  char* arg2_str = strtok( NULL, " " );
  if( arg1_str == NULL || arg2_str == NULL )
  {
    printf( "Expected 2 arguments\n" );
    return 0;
  }
  else
  {
    sscanf( arg1_str, "%d", arg1 );
    sscanf( arg2_str, "%d", arg2 );
    return 1;
  }
}

