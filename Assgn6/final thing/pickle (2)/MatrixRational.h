/*
 * Author: Abhiram
 * Rational data structure
 */

#ifndef MATRIX_RATIONAL_H
#define MATRIX_RATIONAL_H

#include "rational.h"

typedef struct MatrixRational_ {
    int rows; int cols;
    rational** data;
} MatrixRational;

// Allocate them memory for a matrix with rational entries
MatrixRational* matrix_rational_alloc( int rows, int cols );
// Make a rational matrix initialised with all zeros
MatrixRational* matrix_rational_zeros( int rows, int cols );
MatrixRational* matrix_rational_random( int rows, int cols );

void matrix_rational_print( MatrixRational* m );

// Make a rational matrix initialised with all zeros
MatrixRational* matrix_rational_add( MatrixRational* m1, MatrixRational* m2 );
MatrixRational* matrix_rational_mul( MatrixRational* m1, MatrixRational* m2 );

MatrixRational* matrix_rational_load_txt( char* filename );
MatrixRational* matrix_rational_load_bin( char* filename );
void matrix_rational_save_txt( MatrixRational* m, char* filename );
void matrix_rational_save_bin( MatrixRational* m, char* filename );

#endif // RATIONAL_H


