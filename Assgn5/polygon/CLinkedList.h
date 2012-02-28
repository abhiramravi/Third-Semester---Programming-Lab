/*
 * Author: Abhiram R - CS10B060
 * Circularly linked data structure
 */

#ifndef CLINKED_LIST_H
#define CLINKED_LIST_H

#include "Point.h"

typedef struct CLinkedList_ {
   Point* head;
   Point* tail;
} CLinkedList;

// Create a new empty list
CLinkedList* clinked_list_new();
// Deletes the list, frees memory.
void clinked_list_delete( CLinkedList* lst );

// Returns the number of elements in the stack
int clinked_list_size( CLinkedList* lst );

// Inserts @val at the 'i-th' index
CLinkedList* clinked_list_insert( CLinkedList* lst, int at, Point val );
// Inserts @val at the beginning of the list.
CLinkedList* clinked_list_push_front( CLinkedList* lst, Point val ); 
// Inserts @val at the end of the list.
CLinkedList* clinked_list_push_back( CLinkedList* lst, Point val ); 


// Removes element at the 'i-th' index
CLinkedList* clinked_list_remove( CLinkedList* lst, int at );
// Removes element at the beginning
CLinkedList* clinked_list_pop_front( CLinkedList* lst );
// Removes element at the end
CLinkedList* clinked_list_pop_back( CLinkedList* lst );


// Gets a pointer to element at the 'i-th' index
Point* clinked_list_get( CLinkedList* lst, int at );
// Gets element at the beginning
Point* clinked_list_front( CLinkedList* lst );
// Gets element at the end
Point* clinked_list_back( CLinkedList* lst );

// Prints the elements currently in the stack
void clinked_list_print( CLinkedList* lst );

#endif // CLINKED_LIST_H

