
/* 
 * Author: Surya Kiran Oruganti
 * Append "I R Babboon" to input string, convert string to upper case,
 * print original and capitalized strings.
 */

#include <stdio.h>
#include <stdlib.h>

#include "capitalize.h"

int main ()
{
	char input_str[MAX_CHARS], appended_str[MAX_CHARS], capitalized_str[MAX_CHARS];
	char *APPEND_STR = "I R Babboon";
	int num_chars;	
	int i;

	scanf("%s", input_str);
	num_chars = strlen( input_str );

	memcpy( appended_str, input_str, num_chars);
	memcpy( appended_str+num_chars, APPEND_STR, strlen(APPEND_STR) );

	capitalize_string( appended_str );
	//printf( "%s\n", input_str);
	printf( "%s\n", appended_str);

	return 0;
}

