/*
 * Author: Abhiram - CS10B060
 * Binary Search Tree data structure (Implementation)
 */

#include "queue.h"
#include "BSTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void addElement(BSTree* tree, int value)
/*
 * creates a node with the data as the value given, and adds it to the tree in the appropriate location
 * returns nothing.
 * */
{
	Node* new = malloc(sizeof(Node));
	new = tree->root;
	int check = 0;
	if(tree->root == NULL) tree->root = malloc(sizeof(Node));
	if(new == NULL) 
	{
		tree->root->data = value;
		tree->root->left = NULL;
		tree->root->right = NULL;
		check = 1;
	}
	while(new && check == 0)
	{
		if(value > new->data) 
		{
			if(new->right == NULL) 
			{
				Node* point = malloc(sizeof(Node));
				point->data = value;
				point->left = NULL;
				point->right = NULL;
				new->right = point;
				break;
			}
			else {new = new->right;}
		}
		else
		{
			if(new->left == NULL) 
			{
				Node* point = malloc(sizeof(Node));
				point->data = value;
				point->left = NULL;
				point->right = NULL;
				new->left = point;
				break;
			}
			else new = new->left;
		}
	}
}
Node* searchElement(Node* root, int value)
/*
 * Returns the pointer to the element in the tree that holds the value given in param
 * */
{
	if(root==NULL) return NULL;
	if(value < root->data) return searchElement(root->left, value);
	else if( value > root->data) return searchElement(root->right, value);
	if(value == root->data) return root;
}
Node* findParent(Node* root,int data) 
/*
 * returns the parent of the whatever we are searching for
 * */
{
    if(data<root->data)
    {
        if(root->left->data==data)
        {
            return root;
        }
        else
        {
            return findParent(root->left,data);
        }
    }
    else if(data>root->data)
    {
        if(root->right->data==data)
        {
            return root;
        }
        else
        {
            return findParent(root->right,data);
        }
    }
    else
    return root;
}

Node* findSuccessorParent(Node* root)  // its returning the parent of the successor
{
    if(root->left->left==NULL)
        return root;
    else
        return findSuccessorParent(root->left);
}
void printBST(Node* root)
{
	if(root == NULL)  ;
	else
	{	
		printBST(root->left);
		printf("%d ", root->data);
		printBST(root->right);
	}
}
int delete(BSTree* tree, int value)
{
	Node *p,*successor,*parent,**buffer;
    buffer = NULL;
    p = NULL;
    successor = NULL;
    parent=findParent(tree->root,value);
    if(tree->root->data==value)
       buffer=&(tree->root);
    else
    {
        if(parent->left!=NULL)
        {
            if(parent->left->data==value)
                buffer=&(parent->left);
         }
         if(parent->right!=NULL)
         {
            if(parent->right->data==value)
                buffer=&(parent->right);
        }
    }
    if((*buffer)->right==NULL)
    {
        p=(*buffer);
        (*buffer)=(*buffer)->left;
        free(p);
    }
    else if((*buffer)->right->left==NULL)
    {
        p=(*buffer)->right;
        (*buffer)->data=(*buffer)->right->data;
        (*buffer)->right=(*buffer)->right->right;
        free(p);
    }
    else
    {
        successor=findSuccessorParent((*buffer)->right);
        (*buffer)->data=successor->left->data;
        p=successor->left;
        successor->left=p->right;
        free(p);
    }
    return 0;	
}
void breadthFirstPrint(Node* root)
{
    queue* q;
    QNode* qptr;
    Node* ptr;
    q=queue_new();
    ptr=root;
    q=queue_enqueue(q,ptr);
    while(q->head!=NULL){
        qptr=q->head;
        if(qptr->node->left!=NULL)
            q=queue_enqueue(q,qptr->node->left);
        if(qptr->node->right!=NULL)
            q=queue_enqueue(q,qptr->node->right);
        q=queue_dequeue(q);
    }
    printf("\n");
}


