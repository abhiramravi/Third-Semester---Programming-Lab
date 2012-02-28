#include <stdio.h>
#include "polynomial.h"


int main()
{
  int i, j;
  polynomial p = polynomial_construct(2);
  polynomial q = polynomial_construct(2);
  polynomial r;

  p.re_coeffs[0] = 1;
  p.im_coeffs[0] = 1;
  p.re_coeffs[1] = 1;
  p.im_coeffs[1] = 1;
  polynomial_print( p );

  q.re_coeffs[0] = 1;
  q.im_coeffs[0] = 1;
  q.re_coeffs[1] = 2;
  q.im_coeffs[1] = 1;
  polynomial_print( q );

  r = polynomial_mul( p, q );
  polynomial_print( r );

  return 0;
}

