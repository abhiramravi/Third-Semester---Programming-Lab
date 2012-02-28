/*
 * Author: <Your Name>
 * Linked list data structure (Implementation)
 */

#include "LList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Create a new node with data and next element (can be NULL)
Node* node_new( int data, Node* next )
{
  Node* n = (Node*) malloc( sizeof( Node ) );
  n->data = data;
  n->next = next;

  return n;
}

// Create an empty list (head shall be NULL)
LList* llist_new()
{
  LList* l = (LList*) malloc( sizeof( LList ) );
  l->head = NULL;

  return l;
}

void llist_delete(LList* lst)
{
  Node* n;
  for( n = lst->head; n != NULL; )
  {
    Node* n_ = n->next;
    free(n);
    n = n_;
  }
  free( lst );
}

// Traverse the linked list and return its size
int llist_size( LList* lst )
{
  int i=0;
  Node* n;
  for( n = lst->head; n != NULL; n=n->next, i++ );
  return i;
}

// Traverse the linked list and print each element
void llist_print( LList* lst )
{
  Node* n;
  for( n = lst->head; n != NULL; n=n->next )
  {
    printf( "%d ", n->data );
  }
  printf( "\n" );
}

int llist_get( LList* lst, int idx )
{
  int i = 0;
  Node* n;
  for( n = lst->head; n != NULL && i < idx; n=n->next, i++ );
  assert( i == idx );

  return n->data;
}

// Add a new element at the end of the list
LList* llist_append( LList* lst, int data )
{
  Node* n;
  Node* n_ = node_new( data, NULL );

  if( lst->head == NULL )
  {
    lst->head = n_;
  }
  else
  {
    for( n = lst->head; n != NULL && n->next != NULL; n=n->next );
    n->next = n_;
  }

  return lst;
}

// Add a new element at the beginning of the list
LList* llist_prepend( LList* lst, int data )
{
  Node* n = node_new( data, lst->head );
  lst->head = n;

  return lst;
}

// Add a new element at the @idx index
LList* llist_insert( LList* lst, int idx, int data )
{
  if( idx == 0 )
  {
    Node* n_ = node_new( data, NULL );
    n_->next = lst->head;
    lst->head = n_;
  }
  else
  {
    int i = 1;
    Node* n;
    Node* n_ = node_new( data, NULL );

    for( n = lst->head; n!=NULL && n->next!=NULL && i < idx; n=n->next, i++ );

    n_->next = n->next;
    n->next = n_;
  }

  return lst;
}

// Remove an element from the end of the list
LList* llist_remove_last( LList* lst )
{
  Node* n;

  if( lst->head->next == NULL )
  {
    free( lst->head );
    lst->head = NULL;
  }
  else
  {
    for( n = lst->head; n->next != NULL && n->next->next != NULL; n=n->next );

      free( n->next );
      n->next = NULL;
  }
}

// Remove an element from the beginning of the list
LList* llist_remove_first( LList* lst )
{
  Node* n = lst->head;
  assert( n != NULL );

  lst->head = n->next;
  free( n );
  
  return lst;
}

// Remove an element from an arbitrary position in the list
LList* llist_remove( LList* lst, int idx )
{
  Node* n;

  if( idx == 0 )
  {
    n = lst->head;
    free( n );
  }
  else
  {
    int i = 1;
    for( n = lst->head; n!=NULL && n->next!=NULL && i < idx; n=n->next, i++ );

    Node* n_ = n->next;
    free( n_ );
    n->next = n_->next;
  }

  return lst;
}

