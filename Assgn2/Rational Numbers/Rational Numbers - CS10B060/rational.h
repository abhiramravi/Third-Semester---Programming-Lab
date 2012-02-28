/*************************************************
This is a library for operating on rational numbers 
Author : Abhiram R  -  (CS10B060)
Date : 12.8.11
**************************************************/
#ifndef RATIONAL_H
#define RATIONAL_H
typedef struct rational
{
    int p;
    int q;
} rational;
/*Reads a string "str" that contains the rational number in a "p/q" format into the data structure. Also reduces the resultant sum*/
rational rational_parse( char*); 
void rational_print( rational  );                   // Prints the rational number q in the format "p/q" to the terminal (using printf) 
rational rational_from_int( int );                  // Converts an integer to a rational number (p/i)
double rational_to_double( rational  );             // Converts a rational number p to a real number (of double type).
rational rational_add( rational , rational  );      // Adds two rational numbers p, q. Reduces the resultant sum
rational rational_sub( rational , rational  );      // Subtracts two rational numbers p, q. Reduces the resultant sum.
rational rational_mul( rational , rational  );      // Multiplies two rational numbers p, q. Reduces the resultant sum.
rational rational_div( rational , rational );       // Divides two rational numbers p, q. reduces the resultant sum.
rational rational_reciprocate( rational  );         // Computes "1/p".
int gcd(int ,int );                                 // Returns the GCD of the two params
void continued_fraction(int[], int );               // printfs the value of the continued fraction @params - int[] - array of the inputs, 
                                                    // int - precision
void reduce(rational*);
#endif
