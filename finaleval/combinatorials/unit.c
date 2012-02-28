/* 
 * Author: Surya Kiran Oruganti
 * Calculate combinatorials - Fast!
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "combinatorial.h"

/* Input:
 * n1 k1 n2 k2 n3 k3
 * where n is the number of items, of which k are chosen
 * 
 * Output:
 * N1 N2 N3
 * where N is the number of ways of choosing k items out of n distinct items
 */

unsigned long int factorial( unsigned long int, unsigned long int *store);

long int main()
{
	unsigned long int n1,k1, n2,k2, n3,k3;
	unsigned long int N1, N2, N3;
	/* Array to store the factorials of the numbers computed till now */
	unsigned long int *factorial_store = NULL;
	unsigned long int f, N1_denom, N2_denom, N3_denom;

	scanf( "%ld %ld", &n1, &k1);
	scanf( "%ld %ld", &n2, &k2);
	scanf( "%ld %ld", &n3, &k3);

	if ( (n1 < k1) || ( n2 < k2 ) || ( n3 < k3 ) ) { //BUG
		printf("0 0 0");
		return 0;
	}

	if( (n1 >= n2) && (n1 >= n3) ) {
		factorial_store = (unsigned long int *) malloc( (n1+1) * sizeof(unsigned long int) );
		f = factorial( n1, factorial_store);
	} else if ( (n2 >= n1) && (n2 >= n3) ) {
		factorial_store = (unsigned long int *) malloc( (n2+1) * sizeof(unsigned long int) );
		f = factorial( n2, factorial_store);
	} else {
		factorial_store = (unsigned long int *) malloc( (n3+1) * sizeof(unsigned long int) );
		f = factorial( n3, factorial_store);
	} 

	N1 = n_C_k( n1, k1, factorial_store);
	N2 = n_C_k( n2, k2, factorial_store);
	N3 = n_C_k( n3, k3, factorial_store);


	printf( "%lu %lu %lu\n", N1, N2, N3);
	return 0;
// Change all int to long int
}

