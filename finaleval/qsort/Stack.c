/*
 * Author: <Your Name>
 * Stack data structure (Implementation)
 */

#include "Stack.h"
#include "LList.h"
#include <stdlib.h>

// Create a new empty stack
Stack* stack_new()
{
  return llist_new();
}
// Deletes the stack, frees memory.
void stack_delete( Stack* st )
{
  llist_delete( st );
}

// Inserts @val to the top of the stack
Stack* stack_push( Stack* st, int val )
{
  return llist_prepend( st, val );
}
// Remove the element at the top of the stack - also frees memory
Stack* stack_pop( Stack* st )
{
  return llist_remove_first( st );
}

// Returns the element currently at the top of the stack. If the stack is empty,
// @error should be set to 1, else 0.
int stack_top( Stack* st, int* error )
{
  if( st->head == NULL )
  { 
    if( error ) *error = 1;
    return 0;
  }
  else 
  {
    if( error ) *error = 0;
    return llist_get( st, 0 );
  }
}

// Returns the number of elements in the stack
int stack_size( Stack* st )
{
  return llist_size( st );
}
// Prints the elements currently in the stack
void stack_print( Stack* st )
{
  return llist_print( st );
}

