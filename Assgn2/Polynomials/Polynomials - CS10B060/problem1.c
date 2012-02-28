/*********************************************
This is the main file for the first problem
Author : Abhiram : CS10B060
Date : 14.8.11
*********************************************/

#include<stdio.h>
#include<stdlib.h>
#include"polynomial.h"
#include<math.h>

int main(int argc, char* argv[])
{
    if(argc!=4) 
    {
        printf( "Usage: %s <v> <a> <t>", argv[0] );
        exit( EXIT_FAILURE );
    }
    double coeff[2] = { atof(argv[1]), atof(argv[2])};
    double t = atof(argv[3]);
    polynomial velocity = polynomial_construct( 1, coeff);      // the velocity polynomial
    polynomial distance_travelled = polynomial_integrate( velocity);
    /* 
    printf("The velocity polynomial is ");polynomial_print(velocity);
    printf("The distance travelled polynomial is ");
    polynomial_print(distance_travelled); 
    */
    printf(" %f\n",polynomial_evaluate(distance_travelled, t));
    
    
}
