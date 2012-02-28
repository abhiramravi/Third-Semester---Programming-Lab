#include "sum.h"

int check_and_eliminate_occurrences(int n, char *str, char ch)
{
	int i, count = 0;
	for( i = 0; i < strlen(str); i++) {
		if( str[i] == ch ) {
			count ++;
			str[i] = 'a'; // non-numeric
		}
	}
	return count;
}

int sum_numeric_ascii( char *str)
{
	int sum=0, i = 0, length = strlen(str);
	do {
		if( (int)str[i] > 47 && (int)str[i] < 58) {
			sum = sum + (int)str[i];
		}
	} while( i++ < length);
	return sum;
}
