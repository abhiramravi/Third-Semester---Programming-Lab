/*
 * Author: Abhiram R Cs10b060
 * queue haeder file
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "BSTree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct QNode_ QNode;
struct QNode_ {
    Node* node;
    QNode* next;
};
typedef struct queue_{
    QNode* head;
    QNode* tail;
}queue;

//creates a new queue
queue* queue_new(void);
//pushes a node to back
queue* queue_enqueue(queue* q,Node* root);
//removes a node from back and prints its value
queue* queue_dequeue(queue* q);
#endif
