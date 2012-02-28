/* 
 * Author: Surya Kiran Oruganti
 * check if there are atleast 'n' occurrences of character 'ch'
 * find sum of ascii values of the remaining characters
 * 
 */


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	char str[100];
	char ch;
	int count, sum;
	
	scanf( "%d %s %c", &n, str, &ch);
	
	/* check if there are atleast 'n' occurrences of character 'ch' */
	count = check_and_eliminate_occurrences( n, str, ch);
	if( count < n) {
		printf( "0" );
		return 0;
	}
	
	/* find sum of ascii values of the remaining (non 'ch') numeric characters */
	sum = sum_numeric_ascii(str);
	printf( "%d\n", sum);

	return 0;
}




