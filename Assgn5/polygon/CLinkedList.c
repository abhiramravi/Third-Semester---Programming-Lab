/*
 * Author: Abhiram R - CS10B060
 * Circularly Linked List (Implementation)
 */

#include "CLinkedList.h"

// Create a new empty list
CLinkedList* clinked_list_new()
{
    CLinkedList* new;
    new = malloc(sizeof(CLinkedList));
    new->head = NULL;
    new->tail = NULL;
    return new;
}
// Deletes the list, frees memory.
void clinked_list_delete( CLinkedList* lst )
{
    int i;
    Point* ptr = lst->head ;
    for(i=0;i<clinked_list_size(lst);i++)
    {
        free(ptr);
        ptr = ptr->next;
    }
    free(lst);
}

// Returns the number of elements in the stack
int clinked_list_size( CLinkedList* lst )
{
    int size=0;
    Point* ptr;
    ptr = lst->head;
    if(lst->head == NULL) return 0;
    else
    {
        size++;
        while(ptr!=lst->tail)
        {
            size++;
            ptr = ptr->next;
        }
    }
    return size;
}
// Inserts @val at the 'i-th' index
CLinkedList* clinked_list_insert( CLinkedList* lst, int at, Point val )
{
    Point* ptr;
    ptr = lst->head;
    int i;
    if(at==0) return clinked_list_push_front(lst, val);
    else
    {
		for(i=0;i<at-2;i++)
		{
			ptr = ptr->next;
		}
		if(at>=2) ptr = ptr->next;
		ptr->next = &val; 
	}  
    return lst; 
}
// Inserts @val at the beginning of the list.
CLinkedList* clinked_list_push_front( CLinkedList* lst, Point val )
{
    /*Point *tmp;
    tmp = malloc(sizeof(Point));
    tmp->x = val.x;
    tmp->y = val.y;
    tmp->next = last->next;
    last->next = tmp;*/
    
    int i;
    Point* ptr = lst->head;
    val.next = lst->head;
    lst->head = &val;
    for(i=0;i<clinked_list_size(lst)-1;i++)
    {
        ptr = ptr->next;
    }
    ptr->next = lst->head;
    return lst;
} 
// Inserts @val at the end of the list.
CLinkedList* clinked_list_push_back( CLinkedList* lst, Point val )
{
    Point* pt;
    pt = malloc(sizeof(Point));
    pt->x = val.x;
    pt->y = val.y;
    if(lst->head==NULL) 
    {
        lst->head = pt;
        lst->tail = pt;
        lst->tail->next = lst->head;
        //printf("Checkpoint\n");
    }
    else
    {
        lst->tail->next = pt;
        pt->next = lst->head;
        lst->tail = lst->tail->next;
    }
    return lst;
}



// Removes element at the 'i-th' index
CLinkedList* clinked_list_remove( CLinkedList* lst, int at )
{
    Point* ptr;
    Point* ptr_idx_minus_one;
    int i;
    ptr = lst->head;
    if(at==0) clinked_list_pop_front(lst);
    else if(at==1) 
    {
		(lst->head)->next = (ptr->next)->next;
	}
    else
    {
		for(i=0;i<at-1;i++)
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
// Removes element at the beginning
CLinkedList* clinked_list_pop_front( CLinkedList* lst )
{
    int i;
    Point* ptr;
    ptr = lst->head;
    ptr = ptr->next;
    lst->head = ptr;
    ptr = lst->head;
    for(i=0;i<clinked_list_size(lst)-1;i++)
    {
        ptr = ptr->next;
    }
    ptr->next = lst->head;
    return lst;
}
// Remoeves element at the end
CLinkedList* clinked_list_pop_back( CLinkedList* lst )
{
     int i;
     Point* ptr;
     ptr = lst->head;
     for(i=0;i<clinked_list_size(lst)-1;i++)
     {
        ptr = ptr->next;
     }
     free(ptr->next);
     ptr->next = lst->head;
     return lst;
     
}


// Gets a pointer to element at the 'i-th' index
Point* clinked_list_get( CLinkedList* lst, int at )
{
    int i;
    Point* ptr = lst->head;
    for(i=0;i<=at;i++)
    {
        ptr = ptr->next;
    }
    return ptr;
}
// Gets element at the beginning
Point* clinked_list_front( CLinkedList* lst )
{
    return lst->head;
}
// Gets element at the end
Point* clinked_list_back( CLinkedList* lst )
{
    int i;
    Point* ptr;
    ptr = lst->head;
    for(i=0;i<clinked_list_size(lst);i++)
    {
        ptr = ptr->next;
    }
    return ptr;
}

// Prints the elements currently in the stack
void clinked_list_print( CLinkedList* lst )
{
    int i;
    Point* ptr;
    ptr = lst->head;
    for(i=0;i<clinked_list_size(lst);i++)
    {
        point_print(ptr); 
        printf("\n");
        ptr = ptr->next;
    }
}
