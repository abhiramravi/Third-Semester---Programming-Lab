/*********************************************************************
This is the matrix library for declaring all matrix functions
Author : Abhiram R : CS10B060
Date : 21.8.2011
********************************************************************/

#ifndef MATRIX_H
#define MATRIX_H 

typedef struct matrix
{
    double** a;
    int rows, columns;     
}  
matrix;

void matrix_print( matrix );
matrix matrix_add ( matrix , matrix );
matrix matrix_sub ( matrix , matrix );
matrix matrix_mult ( matrix , matrix );

#endif
