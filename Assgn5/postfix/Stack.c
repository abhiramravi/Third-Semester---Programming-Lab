/*
 * Author: Abhiram R - CS10B060
 * Stack data structure (Implementation)
 */

#include "Stack.h"
#include "LList.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Create a new empty stack
Stack* stack_new()
{
    Stack* new_stack;
    new_stack = malloc(20*sizeof(Node));
    new_stack->top = NULL;
    return new_stack;
}
// Deletes the stack, frees memory.
void stack_delete( Stack* st )
{
    while(st->top!=NULL)
    {
        stack_pop(st);        
    }
}

// Inserts @val to the top of the stack
Stack* stack_push( Stack* st, int val )
{
    Node *x;
    x=malloc(sizeof(Node));
    x->data = val;
    x->next = st->top;
    st->top = x;
}
// Remove the element at the top of the stack - also frees memory
Stack* stack_pop( Stack* st )
{
    if(st->top == NULL)
    {
        printf("Empty stack\n");
        return st;
    }
    else
    {
        free(st->top);
        st->top = (st->top)->next;
        return st;
    }
}

// Returns the element currently at the top of the stack. If the stack is empty,
// @error should be set to 1, else 0.
int stack_top( Stack* st, int* error )
{
    if(*error == 1) return 0;
    if(*error == 0)
    {
        return (st->top)->data;
    }
    return 0;
}

// Returns the number of elements in the stack
int stack_size( Stack* st )
{
    int size=0;
    Node* ptr;
    ptr = st->top;
    while(ptr!=NULL)
    {
        size++;
        ptr = ptr->next;
    }
    return size;
}
// Prints the elements currently in the stack
void stack_print( Stack* st )
{
    Node* ptr;
    int i=0,j=0;
    char* string;
    string = malloc(100*sizeof(char));
    ptr = st->top;
    while(ptr!=NULL)
    {
        //printf("%d ",ptr->data);       
        string[i] = ptr->data;
        i++;
        ptr = ptr->next;
    }
    for(j=i-1;j>=0;j--)
    {
        printf("%d ", string[j]);
    }
    printf("\n");
   
}


