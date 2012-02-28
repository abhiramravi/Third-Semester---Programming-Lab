/*****************************************************************
This is the file where all the matrix functions are defined
Author : Abhiram R : CS10B060   
Date : 21.8.2011
*****************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"matrix.h"

void matrix_print ( matrix a )
{
    int i,j;
    for(i=0;i<a.rows;i++)
    {
        for(j=0;j<a.columns;j++)
        {
            printf("%.2lf ",a.a[i][j]);
        }
        printf("\n");
    }
}
matrix matrix_add ( matrix a, matrix b)
{
    int i,j;
    if(a.rows!=b.rows || a.columns!=b.columns) 
    {
        printf("these matrices cannot be added\n");
        exit( EXIT_FAILURE );
    }
    matrix c;
    c.a = malloc(a.rows*sizeof(double));
    for(i=0;i<a.rows;i++)
        {
            c.a[i] = malloc(a.columns*sizeof(double));
        }           
    for(i=0;i<a.rows;i++)
    {
        for(j=0;j<a.columns;j++)
        {
            c.a[i][j] = a.a[i][j] + b.a[i][j] ;        
        }
    }
    c.rows = a.rows;
    c.columns = a.columns;
    return c;
}
matrix matrix_sub ( matrix a, matrix b)
{
    int i,j;
    if(a.rows!=b.rows || a.columns!=b.columns) 
    {
        printf("these matrices cannot be added\n");
        exit( EXIT_FAILURE );
    }
    matrix c;
    c.a = malloc(a.rows*sizeof(double));
    for(i=0;i<a.rows;i++)
        {
            c.a[i] = malloc(a.columns*sizeof(double));
        }
    for(i=0;i<a.rows;i++)
    {
        for(j=0;j<a.columns;j++)
        {
            c.a[i][j] = a.a[i][j] - b.a[i][j] ;        
        }
    }
    c.rows = a.rows;
    c.columns = a.columns;
    return c;
}
matrix matrix_mult ( matrix a, matrix b)
{
    int i,j,k,l;
    if(a.columns!=b.rows) 
    {
        printf("these matrices cannot be multiplied\n");
        exit( EXIT_FAILURE );
    }
    matrix c;
    c.a = malloc(a.rows*sizeof(double));
    for(i=0;i<a.rows;i++)
    {
        c.a[i] = malloc(b.columns*sizeof(double));
    }
    for(i=0;i<a.rows;i++)
    {
        for(j=0;j<b.columns;j++)
        {
            c.a[i][j] = 0;
            for(k=0;k<a.columns;k++)                        /* a.columns = b.rows */   
            {
                c.a[i][j]+= a.a[i][k] * b.a[k][j];
            }
        }
    }    
    c.rows = a.rows;
    c.columns = b.columns;
    return c;
}

