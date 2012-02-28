/*
 * Author: Abhiram R - CS10B060
 * Linked list data structure (Implementation)
 */

#include "LList.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

LList* llist_new()
{
    LList new_list;
    new_list.head = NULL;
    return new_list;
}
int llist_size( LList* list )
{
    int size = 0;
    int i;
    Node* ptr;
    ptr = list->head;
    while(ptr!=NULL)
    {
        size++;
        ptr = ptr->next;
    }
    return size;
}
void llist_print( LList* list )
{
    Node* ptr;
    ptr = list->head;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr = ptr->next;
    }
}
LList* llist_append( LList* lst, int data )
{
    Node* ptr;
    ptr = lst->head;
    while(ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = malloc(sizeof(Node));
    (ptr->next)->data = data;
    return ptr->next;
}
LList* llist_prepend( LList* lst, int data )
{
    Node* ptr;
    ptr = malloc(sizeof(Node));
    ptr->next = lst.head;
    lst->head = ptr;
    return lst; 
}
LList* llist_insert( LList* lst, int idx, int data )
{
    Node* ptr;
    Node* ptr_idx;
    ptr = lst->head;
    int i;
    
    for(i=0;i<idx-1;i++)
    {
        ptr = ptr->next;
    }
    ptr_idx = ptr->next;
    ptr->next = realloc(sizeof(Node));
    (ptr->next)->data = data;
    if(idx==0) lst->head = ptr->next;
    (ptr->next)->next = ptr_idx;   
    return lst;   
}
LList* llist_remove_last( LList* lst )
{
    Node* ptr;
    ptr = lst->head;
    
    while((ptr->next)->next!=NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = NULL;
    return lst;
}
LList* llist_remove_first( LList* lst )
{
    Node* ptr;
    ptr = lst->head;
    ptr = ptr->next;
    lst->head = ptr;
    return lst;
}
LList* llist_remove( LList* lst, int idx )
{
    Node* ptr;
    int i;
    for(i=0;i<idx-1;i++)
    {
        ptr = ptr->next;
    }
    ptr_idx_minus_one = ptr;
    ptr = ptr->next;
    ptr = ptr->next;
    ptr_idx_minus_one->next = ptr;
    return lst;
    
}












