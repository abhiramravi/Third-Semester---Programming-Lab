/*
 * Author: Abhiram R - CS10B060
 * Postfix Expression Evaluator
 */

#include "Stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void debugger();
int evaluate_postfix( char* expr );

int main( int argc, char* argv[] )
{
    char* string;
    string = malloc(100*sizeof(char));
    int answer;
    fgets(string, 100*sizeof(char), stdin);
    answer = evaluate_postfix(string);
   // printf("%d",answer);

    return 0;
}

int evaluate_postfix( char* expr )
{
    Stack* st = stack_new();
    char* pBuf;
    char* gen;
    int val; 
    gen = malloc(20*sizeof(char));
    pBuf = malloc(20*sizeof(char));
  //printf ("Splitting string \"%s\" into tokens:\n",expr);
    pBuf = strtok (expr," ");   
    while (pBuf != NULL)
    {
        strcpy(gen,pBuf);
        if(atoi(gen)!=0) 
        {         
            val = atoi(gen);
            stack_push(st,val);
        }
        else
        {
            if(strncmp(gen,"+",1)==0)
            {
                val = ((st->top)->data) + ((st->top->next)->data);
                stack_pop(st);
                stack_pop(st);
                stack_push(st,val);
            }
            if(strncmp(gen,"-",1)==0)
            {
                val = ((st->top->next)->data) - ((st->top)->data);
                stack_pop(st);
                stack_pop(st);
                stack_push(st,val);
            }
            if(strncmp(gen,"*",1)==0)
            {
                val = ((st->top)->data) * ((st->top->next)->data);
                stack_pop(st);
                stack_pop(st);
                stack_push(st,val);
            }
            if(strncmp(gen,"/",1)==0)
            {
                val = ((st->top->next)->data)/((st->top)->data) ;
                stack_pop(st);
                stack_pop(st);
                stack_push(st,val);
            }
       } 
       stack_print(st);   
       pBuf = strtok (NULL, " ");       
    }   
    return st->top->data;
}
void debugger()
{
    printf("Checkpoint\n");
}
