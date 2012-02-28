/*
 * Author: Abhiram R CS10B060
 * queue library file
 */

#include "queue.h"
#include "BSTree.h" 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

queue* queue_new(void)
{
    queue* new;
    new=malloc(sizeof(queue));
    assert(new!=NULL);
    new->head=malloc(sizeof(QNode));
    assert(new->head!=NULL);
    new->head->node=NULL;
    new->head->next=NULL;
    new->tail=NULL;
    return new;
}

queue* queue_enqueue(queue* q,Node* root)
{
    QNode* ptr;
    ptr=q->head;
    if(ptr->node==NULL){
        ptr->node=root;
        q->tail=ptr;
    }else{
        q->tail->next=malloc(sizeof(QNode));
        ptr=q->tail->next;
        ptr->node=root;
        ptr->next=NULL;
        q->tail=ptr;
    }
    return q;
}
queue* queue_dequeue(queue* q)
{
    QNode* ptr,*temp;
    ptr=q->head;
    temp=ptr;
    if(q->head==q->tail)
        q->tail=NULL;
    q->head=ptr->next;
    printf("%d ",ptr->node->data);
    free(temp);
    return q;
}


