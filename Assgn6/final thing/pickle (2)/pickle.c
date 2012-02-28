/*
 * Author: Abhiram
 * Reading/Writing matrices
 */

#include <stdio.h>
#include <stdlib.h>
#include "rational.h"
#include "MatrixRational.h"
void debugger();
/* 
 * Assume the input and output filenames are given as the first two
 * arguments
 */
int main( int argc, char* argv[] )
{
    if( argc != 4 )
    {
        fprintf( stderr, "Usage: %s [-b|-t] <in-file> <out-file>\n", argv[0] );
        exit( EXIT_FAILURE );
    }
    else
    {
        int is_text = strcmp( argv[1], "-t" ) == 0;
        char* in_file = argv[2];
        char* out_file = argv[3];

        if( is_text )
        {			
            MatrixRational* m1 = matrix_rational_load_txt( in_file );           
            MatrixRational* m2 = matrix_rational_mul( m1, m1 );
            matrix_rational_save_txt( m2, out_file );
        }
        else
        {
            MatrixRational* m1 = matrix_rational_load_bin( in_file );
            MatrixRational* m2 = matrix_rational_mul( m1, m1 );
            matrix_rational_save_bin( m2, out_file );
        }
    }

    return 0;
}
void debugger()
{
	printf("Checkpoint\n");
}	

