/**********************************************************************
This is the header file/library for operations on polynomials
Author - Abhiram R -  CS10B060  
Date - 12.8.11
***********************************************************************/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

typedef struct polynomial
{
    double* coeff;
    int n;
}   polynomial;
    polynomial polynomial_construct( int , double[] );       //Constructs a polynomial from a list of 'n' coefficients stored in 'coeffs'.
    void polynomial_print( polynomial  );                    //Prints the polynomial q in the format "a0 x^0 + a1 x^1 + ...", where a0, etc. are 
                                                             //the actual  coefficients, to the terminal (using printf)      
    double polynomial_evaluate( polynomial , double );       // Evaluates the polynomial p at the value x.
    polynomial polynomial_add( polynomial , polynomial );    // Adds two polynomials p, q.
    polynomial polynomial_sub( polynomial , polynomial );    // Subtracts two polynomials p, q.
    polynomial polynomial_mul( polynomial , polynomial );    // Multiplies two polynomials p, q.
    polynomial polynomial_diff( polynomial );                // Differentiates the polynomial p with respect to x.
    polynomial polynomial_integrate( polynomial );           // Integrates the polynomial p with respect to x. Ignores the constant term.




#endif
