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
}



/*
for(i=0;i<m[k].rows;i++)
        for(j=0;j<m[k].columns;j++)
        {
            printf("%.2lf ",m[k].a[i][j]);
        }
*/
