/*************************************************************************************************
This is the main file for the first continued fraction problem.
Author : Abhiram R - CS10B060
Date : 12.8.11
*************************************************************************************************/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"rational.h"
void continued_fraction(int[], int);
int main(int argc, char* argv[])
{
    int a[100];
    int i;
    if(argc!=5) 
    {
        printf( "Usage: %s <a0> <a1> <a2> <a3>", argv[0] );
        exit( EXIT_FAILURE );
    }	
    for(i=0;i<4;i++)
    {
        a[i] = atoi(argv[i+1]);
    }
    continued_fraction(a,4);
}



