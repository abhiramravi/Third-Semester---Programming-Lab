
#include "capitalize.h"

void capitalize_string( char *str )
{
	int i;
	for( i = 0; i < strlen( str ); i++ ) {
		if( ((int)str[i] < 123) && ((int)str[i] > 96 ) ) {
			str[i] -= 32;
		}
	}
}
