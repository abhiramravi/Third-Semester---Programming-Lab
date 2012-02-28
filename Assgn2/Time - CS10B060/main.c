/**********************************************************************************
This is a program that calculates the average time that a program takes to execute
Author : Abhiram R : CS10B060   
Date : 16.8.11
************************************************************************************/

#include<stdio.h>
#include<sys/time.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>

void time_me(int);

int main(int argc, char* argv[])
{
    if(argc!=2)
    {
        printf( "Usage: %s <N>", argv[0] );
        exit( EXIT_FAILURE );
    }
    int i;
    int n = atoi(argv[1]);
    struct timeval start, end;      /* Creating instances of the predefined Structures of time.h */

    gettimeofday(&start, NULL);

    for (i=0; i<10; i++)
    {
        time_me(n);
    }

    gettimeofday(&end, NULL);

    printf("%f\n", (((end.tv_sec + end.tv_usec/1000000.0 ) - (start.tv_sec + start.tv_usec/1000000.0 ))/10.0));
}


void time_me(int N) 
{
    int i;
    int a=0;
    sleep(2);
    if (N > 3) 
    {
        sleep((N-2)%7);
    }
    for( i=1; i < 73638; i++) 
    {
        a += i;
    }
    a = ~a;
}

