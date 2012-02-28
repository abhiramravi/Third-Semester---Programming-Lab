/*
 * Author: Abhiram
 * Polynomial data structure
 */

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

  
typedef struct polynomial_
{
  int n;
  int re_coeffs[5];
  int im_coeffs[5];
} polynomial;

// Construct a polynomial from a list of 'n' coefficients stored in 'coeffs'.
polynomial polynomial_construct ( int n );

// Print the polynomial q in the format a0 x^0 + a1 x^1 ...
void polynomial_print ( polynomial p );

// Operations on polynomials
polynomial polynomial_add ( polynomial p, polynomial q );
polynomial polynomial_mul ( polynomial p, polynomial q );

#endif // POLYNOMIAL_H

