/*************************************************************************************************
This is the main file for the solution to the continued fraction problem (problem 2) that accurately determines PI
Author : Abhiram R  -  (CS10B060)
Date : 12.8.11

*************************************************************************************************/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"rational.h"

int main (int argc, char* argv[])
{
    int precision = atoi(argv[1]);
    int a[100];
    int i;
    if(argc!=precision+2)
    {
        printf( "Usage: %s <precision> <a0> <a1> <a2>.....\n", argv[0] );
        exit( EXIT_FAILURE );
    }
    for(i=0;i<precision;i++)
    {
        a[i] = atoi(argv[i+2]);
    }
    continued_fraction(a,precision);
}
