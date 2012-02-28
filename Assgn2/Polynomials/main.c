/**************************************************************
This is the main function that I have used for testing purposes
Author : Abhiram R - CS10B060
Date : 13.8.11
***************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"polynomial.h"

int main ()
{
    int i;
    double c[10];
    c[0] = 1; c[1] = 2; c[2] = 3; c[3] = 4; c[4] = 5; c[5] =6;c[6] = 7;
    double d[8] = {1,5,6,4,5,7,8,9};
    polynomial polynom_1 ;
    polynom_1.coeff =  malloc(7*sizeof(double));
    polynom_1 = polynomial_construct (6,c);
    polynomial polynom_2;
    polynom_2.coeff =  malloc(3*sizeof(double));
    polynom_2 = polynomial_construct (7,d);
    printf("polynom_1 = "); polynomial_print ( polynom_1 );
    printf("polynom_2 = ");polynomial_print ( polynom_2 );
    double value = polynomial_evaluate (polynom_1, 1);
    printf("value = %f\n", value);  
    printf(" Sum = ");polynomial polynom_added = polynomial_add(polynom_1, polynom_2);
    polynomial_print( polynom_added);
    printf("difference = ");polynomial_print( polynomial_sub(polynom_1, polynom_2));
    printf(" derivative = ");polynomial_print( polynomial_diff(polynom_1));
    printf(" integral = ");polynomial_print( polynomial_integrate(polynom_1));
    printf(" product = ");polynomial_print( polynomial_mul(polynom_1, polynom_2));
}

  
