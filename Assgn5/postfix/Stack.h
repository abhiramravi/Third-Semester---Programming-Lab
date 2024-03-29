/*
 * Author: Abhiram R - CS10B060
 * Stack data structure
 */
#include"LList.h"
#ifndef STACK_H
#define STACK_H

typedef struct Stack_ {
    Node* top;
} Stack;

// Create a new empty stack
Stack* stack_new();
// Deletes the stack, frees memory.
void stack_delete( Stack* st );

// Inserts @val to the top of the stack
Stack* stack_push( Stack* st, int val );
// Remove the element at the top of the stack - also frees memory
Stack* stack_pop( Stack* st );

// Returns the element currently at the top of the stack. If the stack is empty,
// @error should be set to 1, else 0.
int stack_top( Stack* st, int* error );

// Returns the number of elements in the stack
int stack_size( Stack* st );
// Prints the elements currently in the stack
void stack_print( Stack* st );

#endif // STACK_H

