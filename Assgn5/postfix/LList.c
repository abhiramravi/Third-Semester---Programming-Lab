/*
 * Author: Abhiram R - CS10B060
 * Linked list data structure (Implementation)
 */
#include<stdio.h>
#include<stdlib.h>
#include "LList.h"

Node* node_new( int data, Node* next )
{	
	Node* node_1;
	node_1 = malloc(10*sizeof(Node));
	node_1->data = data;
	node_1->next = next;
	return node_1;
}
LList* llist_new()
{
    LList* new_list;
    new_list = malloc(10*sizeof(Node));
    new_list->head = NULL;
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
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int llist_get( LList* lst, int idx )
{
	Node* ptr;
	ptr = lst->head;
	int i;
	for(i=0;i<idx;i++)
	{
		ptr = ptr->next;
	}
	return ptr->data;
}
LList* llist_append( LList* lst, int data )
{
    Node* ptr;
    ptr = lst->head;
    if(lst->head == NULL)
    {
		lst->head = node_new(data, NULL);
		return lst;
	}
	else
	{
		while(ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = node_new(data,NULL);
		return lst;
	}
}
LList* llist_prepend( LList* lst, int data )
{
    Node* ptr;
    ptr = malloc(sizeof(Node));
    ptr = node_new(data, lst->head)   ;
    lst->head = ptr;
    return lst; 
}
LList* llist_insert( LList* lst, int idx, int data )
{
    Node* ptr;
    ptr = lst->head;
    int i;
    if(idx==0) return llist_prepend(lst, data);
    else
    {
		for(i=0;i<idx-2;i++)
		{
			ptr = ptr->next;
		}
		if(idx>=2) ptr = ptr->next;
		ptr->next = node_new(data, ptr->next); 
	}  
    return lst;   
}
LList* llist_remove_last( LList* lst )
{
    Node* ptr;
    ptr = lst->head;
    if(llist_size(lst) == 1) return llist_remove_first(lst);
    else
    {
		while((ptr->next)->next!=NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = NULL;
	}
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
    Node* ptr_idx_minus_one;
    int i;
    ptr = lst->head;
    if(idx==0) llist_remove_first(lst);
    else if(idx==1) 
    {
		(lst->head)->next = (ptr->next)->next;
	}
    else
    {
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
}
