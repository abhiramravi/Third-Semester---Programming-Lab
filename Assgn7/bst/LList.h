/*
 * Author: Abhiram R - CS10B060
 * Linked list data structure
 */

#ifndef LLIST_H
#define LLIST_H

// Node for the link list
typedef struct qNode_ qNode;
struct qNode_ {
    struct Node* data;
    qNode* next;
};

// Create a new node with data and next element (can be NULL)
qNode* node_new( int data, qNode* next );

// Link list structure
typedef struct LList_ {
    qNode* head;
} LList;

// Create an empty list (head shall be NULL)
LList* llist_new();

// Traverse the linked list and return its size
int llist_size( LList* lst );

// Traverse the linked list and print each element
void llist_print( LList* lst );
//get element of the idx th index
int llist_get( LList* lst, int idx );
// Add a new element at the end of the list
LList* llist_append( LList* lst, int data );
// Add a new element at the beginning of the list
LList* llist_prepend( LList* lst, int data );
// Add a new element at the @idx index
LList* llist_insert( LList* lst, int idx, int data );

// Remove an element from the end of the list
LList* llist_remove_last( LList* lst );
// Remove an element from the beginning of the list
LList* llist_remove_first( LList* lst );
// Remove an element from an arbitrary position in the list
LList* llist_remove( LList* lst, int idx );

#endif // LLIST_H
