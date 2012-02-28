/*
 * Author: Abhiram - CS10B060
 * Token System
 */
 #include"queue.h"
#include "BSTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main( int argc, char* argv[] )
{
  // TODO: Read a stream of integers using scanf. Stop when you see a
  //       -1
  int i=1;
  int j=0;
  BSTree* tree;
  tree = malloc(sizeof(tree));
  tree->root=NULL;
  do
  {
    scanf("%d",&i);
    if(i==-1) break;
    if(searchElement(tree->root, i) == NULL) addElement(tree, i);  
    else delete(tree, i);
    
    printBST(tree->root);   
    fflush;
    printf("\n");
  }
  while(1);
  // TODO: For each token - check if the token exists in the
  //       collection. If no - add to the collection. If yes - remove.
  // TODO: Print when done
  /*printf("BFS Printing : \n");
  breadthFirstPrint(tree->root);*/
  return 0;
}

