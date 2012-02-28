/*
 * Abhiram R - CS10B060
 * Recursive program to count the number of occurances of a character
 */

#include <stdio.h>
#include<stdlib.h>
#include<math.h>

int counter(char, char*, int);
int main( int argc, char* argv )
{
	char toCount;
	char* string;
	char* buf;
	buf = malloc(sizeof(char));
	string = malloc(100* sizeof(char));
  // Read the character to count
	fgets(buf, sizeof(buf), stdin);
	sscanf(buf,"%c",&toCount);
  // Read the string who's characters need to be counted
  	fgets(string, 100*sizeof(char), stdin);
  // Count the characters 
	int answer = counter(toCount, string, 0);
  // Print the count
	printf("%d\n",answer);

  return 0;
}
int counter(char toCount, char* stringLetter, int answer )
{
	if(*stringLetter == '\0') return answer;
	else
	{
		if(*stringLetter == toCount) return counter(toCount, stringLetter+1, answer+1 );
		else return counter(toCount, stringLetter+1, answer);
	}
}

