/*
 * Author: 
 * Matrix Rational data structure (Implementation)
 */

#include "MatrixRational.h"
#include "rational.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define BUF_SIZE 1024

// Allocate them memory for a matrix with rational entries
MatrixRational* matrix_rational_alloc( int rows, int cols )
{
    MatrixRational* new;
    new = malloc(sizeof(MatrixRational));
    new->rows = rows;
    new->cols = cols;
    new->data = malloc(rows*sizeof(rational*));
    int i;
    for(i=0;i<new->rows;i++)
    {
        new->data[i] = malloc(cols*sizeof(rational));
    }
    return new;
}

// Make a rational matrix initialised with all zeros
MatrixRational* matrix_rational_zeros( int rows, int cols )
{
    int i, j;
    MatrixRational* m = matrix_rational_alloc( rows, cols );
    for( i = 0; i < rows; i++ )
    {
        for( j = 0; j < cols; j++ )
        {
            m->data[i][j] = make_rational( 0, 1 );
        }
    }

    return m;
}

// Make a rational matrix initialised with random entries 
MatrixRational* matrix_rational_random( int rows, int cols )
{
    int i, j;
    MatrixRational* m = matrix_rational_alloc( rows, cols );
    for( i = 0; i < rows; i++ )
    {
        for( j = 0; j < cols; j++ )
        {
            m->data[i][j] = make_rational( rand()%20, rand()%20 + 1 );
        }
    }

    return m;
}

// Make a rational matrix initialised with random entries 
void matrix_rational_print( MatrixRational* m )
{
    int i, j;
    for( i = 0; i < m->rows; i++ )
    {
        for( j = 0; j < m->cols; j++ )
        {
            rational_print( m->data[i][j] );
            printf( " " );
        }
        printf( "\n" );
    }
}

// Make a rational matrix initialised with all zeros
MatrixRational* matrix_rational_add( MatrixRational* m1, MatrixRational* m2 )
{
    int i, j;
    int rows = m1->rows;
    int cols = m1->cols;
    assert( m1->rows == m2->rows && m1->cols == m2->cols );

    MatrixRational* m = matrix_rational_alloc( rows, cols );

    for( i = 0; i < rows; i++ )
    {
        for( j = 0; j < cols; j++ )
        {
            m->data[i][j] = rational_add( m1->data[i][j], m2->data[i][j] );            
        }
    }

    return m;
}

// Make a rational matrix initialised with all zeros
MatrixRational* matrix_rational_mul( MatrixRational* m1, MatrixRational* m2 )
{
    int i,j,k;
    if((m1->cols)!=(m2->rows))
    {
        printf("The matrices cannot be multiplied\n");
        exit(EXIT_FAILURE);
    }
    MatrixRational* product = matrix_rational_zeros( m1->rows, m2->cols );   
    for(i=0;i<(m1->rows);i++)
    {
        for(j=0;j<(m2->cols);j++)
        {
            for(k=0;k<(m1->cols);k++)                        /* a.columns = b.rows */   
            {	
                product->data[i][j] = rational_add( product->data[i][j],rational_mul(m1->data[i][k], m2->data[k][j]));
            }
        }
    }   
    return product;
}

MatrixRational* matrix_rational_load_txt( char* filename )
{
    FILE* fin;
    fin = fopen(filename, "r");
    if(fin==NULL)
    {
        printf("File doensn't exist\n");
        exit(EXIT_FAILURE);
    }
    int i,j,rows,cols;
    char* string;
    string = malloc(100*sizeof(char));
    char* buf;
    rational r;
    fgets(string, sizeof(string), fin);
    sscanf(string, "%d %d", &rows, &cols);
    MatrixRational* m = matrix_rational_alloc(rows,cols);
    for(i=0;i<rows;i++)
    {
        j=0;
        fgets(string, 100*sizeof(char), fin);
        buf = strtok (string," ");
        while (buf!= NULL)
        {
           sscanf(buf,"%ld/%ld",&(r.num),&(r.denom));
           m->data[i][j] = r;
           j++; 
           buf = strtok (NULL, " ");
        }                        
    }
    fclose(fin);
    return m;
}

MatrixRational* matrix_rational_load_bin( char* filename )
{
    FILE* fin;
    fin = fopen(filename, "rb");
    if(fin==NULL)
    {
        printf("File doensn't exist\n");
        exit(EXIT_FAILURE);
    }
    int i,j,rows,cols;
    fread(&rows, sizeof(int), 1, fin);
    fread(&cols, sizeof(int), 1, fin);
    MatrixRational* m = matrix_rational_alloc(rows,cols);
    for(i=0;i<rows;i++)
    for(j=0;j<rows;j++)
    {
		fread(&(m->data[i][j]), sizeof(rational), 1, fin);
	}
	fclose(fin);
	return m;
}

void matrix_rational_save_txt( MatrixRational* m )
{	
    FILE* fout;
    //debugger();
    /*fout = fopen(filename, "w");
    if(fout == NULL)cd ..
		printf("file could be initialized");
		
    debugger();
    if(fout==NULL)
    {
        printf("Failure!\n");
        exit(EXIT_FAILURE);
    }*/
    int i,j;
    //fprintf(fout,"%d %d\n",m->rows,m->cols);
    printf("%d %d\n",m->rows,m->cols);

    for(i=0;i<(m->rows);i++)
    {
        for(j=0;j<(m->cols);j++)
        {			
            rational_write(m->data[i][j],stdout);            
            fprintf(stdout," ");
        }
        fprintf(stdout,"\n");
    }
    //fclose(fout);
}

void matrix_rational_save_bin( MatrixRational* m, char* filename )
{
    FILE* fout;
    fout = fopen(filename, "wb");
    if(fout==NULL)
    {
        printf("Failure!\n");
        exit(EXIT_FAILURE);
    }
    int i,j;
    fwrite(&m->rows,sizeof(int),1,fout);
    fwrite(&m->cols,sizeof(int),1,fout);
    for(i=0;i<(m->rows);i++)
    {
        for(j=0;j<(m->cols);j++)
        {
            fwrite(&(m->data[i][j]), sizeof(rational), 1, fout);
        }
    }
    fclose(fout);
}


