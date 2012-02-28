/*
 * Author: Abhiram - CS10B060
 * Token System
 */
 #include"LList.h"
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
  LList* lst;
  lst = malloc(sizeof(LList));
  lst->head = NULL;
  do
  {
    scanf("%d",&i);
    if(i==-1) break;
    if(searchList(lst, i) == -1) lst = llist_append(lst, i);  
    else llist_remove(lst, searchList(lst,i));
    
    llist_print(lst);
    fflush;
  }
  while(1);
  // TODO: For each token - check if the token exists in the
  //       collection. If no - add to the collection. If yes - remove.
  // TODO: Print when done
  //printf("BFS Printing : \n");
  //breadthFirstPrint(tree->root);
  return 0;
}


