/*
 * Author: <Your Name>
 * Binary Search Tree data structure
 */

#ifndef BST_H
#define BST_H

// Node for the link list
typedef struct Node_ Node;
struct Node_ {
    int data;
    Node* left;
    Node* right;
};

// Link list structure
typedef struct BSTree_ {
    Node* root;
} BSTree;

// TODO: Write functions to add/remove an element from the binary tree. 
// TODO: Write a function to search if an element belongs to the BST
// TODO: Write a function to print out the whole BST


#endif // BST_H

