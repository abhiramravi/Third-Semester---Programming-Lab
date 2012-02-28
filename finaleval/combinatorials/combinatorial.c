#include "combinatorial.h"

unsigned long int factorial( unsigned long int n, unsigned long int *store)
{
	unsigned long int i, f=1; 

	store[0] = 1;
	for( i = 1; i <= n; i++) {
		f *= i;
		store[i] = f;
	}
	return f;
}

unsigned long int n_C_k( unsigned long int n, unsigned long int k, unsigned long int *factorial_store)
{
	unsigned long int N, denominator;
	denominator = factorial_store[k] * factorial_store[n-k];
	N = factorial_store[n] / denominator;
	
	return N;
}






	
	

