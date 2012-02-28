/*****************************************************************
This is the solution to the problem in the problem statement
Author : Abhiram R : CS10B060   
Date : 21.8.2011
*****************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"matrix.h"

int main()
{
    matrix m[2];
    int i,j,k;
    
    for(k=0;k<2;k++)                            /* Taking the input */
    {
        printf("Enter the dimensions of the matrix\n");
        scanf("%d %d", &m[k].rows, &m[k].columns);
        fflush;
        
        (m[k].a) = malloc(m[k].rows*sizeof(double));
        
        for(i=0;i<m[k].rows;i++)
        {
            m[k].a[i] = malloc(m[k].columns*sizeof(double));
        }
        
        printf("Enter the values that you wish to input in the matrix\n");    
        for(i=0;i<m[k].rows;i++)
        for(j=0;j<m[k].columns;j++)
        {
            scanf("%lf",&m[k].a[i][j]);
            fflush;
        }        
    } 
    matrix product;
    product.a = malloc(m[0].rows*sizeof(double));
    for(i=0;i<m[0].rows;i++)
    {
        product.a[i] = malloc(m[1].columns*sizeof(double));
    } 
    product = matrix_mult (  m[0],  m[1]);
    printf("The product of the given matrices is \n");
    matrix_print(product); 
}   
