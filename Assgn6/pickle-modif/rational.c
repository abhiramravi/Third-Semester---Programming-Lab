/*
 * Author: 
 * Rational data structure (Implementation)
 */

#include "rational.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

// Additional functions
int gcd ( int a, int b )
{
    if( a < 0 ) a *= -1;
    if( b < 0 ) b *= -1;
    
    if( a < b ) 
    {
        return gcd( b, a );
    }
    else if( b == 0 )
    {
        return a;
    }
    else
    {
        return gcd( b, a%b );
    }
}


rational make_rational ( int p, int q )
{
    int g = gcd( p, q );
    rational r = {p/g, q/g};

    return r;
}

// Parse a rational value from a string
rational rational_parse ( char* str )
{
    long num, denom;
    char* saveptr;
    char* str_ = strtok_r( str, "/", &saveptr );

    assert( str_ != NULL );
    num = atol( str_ );
    str_ = strtok_r( NULL, "/", &saveptr );
    assert( str_ != NULL );
    denom = atol( str_ );

    return make_rational( num, denom );
}

// Print a rational value
void rational_write ( rational q, FILE* stream ) 
{
    fprintf( stream, "%ld/%ld", q.num, q.denom );
}

// Print a rational value
void rational_print ( rational q ) 
{
    rational_write( q, stdout );
}

// Convert p to a rational p/1
rational rational_from_int ( int p ) 
{
    return make_rational( p, 1 );
}

// Convert rational to double
double rational_to_double ( rational p )
{
    return (double)p.num / p.denom;
}

// Operations on rational numbers
rational rational_add ( rational p, rational q ) 
{
    return make_rational( p.num * q.denom + p.denom * q.num, p.denom * q.denom );
}

rational rational_sub ( rational p, rational q )
{
    return make_rational( p.num * q.denom - p.denom * q.num, p.denom * q.denom );
}

rational rational_mul ( rational p, rational q )
{
    return make_rational( p.num * q.num, p.denom * q.denom );
}

rational rational_div ( rational p, rational q )
{
    return make_rational( p.num * q.denom, p.denom * q.num );
}

rational rational_reciprocate( rational p )
{
    return make_rational( p.denom, p.num );
}

