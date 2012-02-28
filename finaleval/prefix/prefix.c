/*
 * Abhiram R CS10B060
 * Recursive program to evaluate a postfix expression
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Tokeniser.h"

void print_expression( char* expr )
{
  Token t;
  do
  {
    t = read_token( expr );
    switch( t.op ) {
      // The token is an addition symbol
      case ADD:
        printf( "+ " ); break;
      case SUB:
        printf( "- " ); break;
      case MUL:
        printf( "* " ); break;
      case DIV:
        printf( "/ " ); break;
      // EOE stands for end of expression; Print a new line
      case EOE:
        printf( "\n" ); break;
      // The token is a numeral
      default:
        printf( "%d ", t.num ); break;
    }

  } while( !is_eoe( t ) );

}
int evaluate_expression( char* expr )
{
  Token t;
  do
  {
    t = read_token( expr );
    switch( t.op ) {
      // The token is an addition symbol
      case ADD:
        return evaluate_expression(expr) + evaluate_expression(expr); break;
      case SUB:
        return evaluate_expression(expr) - evaluate_expression(expr); break;
      case MUL:
        return evaluate_expression(expr) * evaluate_expression(expr); break;
      case DIV:
        return evaluate_expression(expr) / evaluate_expression(expr); break;
      // EOE stands for end of expression; Print a new line
      case EOE:
         break;
      // The token is a numeral
      default:
        return t.num; break;
    }
    //return evaluate_expression(expr);
  } while( !is_eoe( t ) );

}

int main( int argc, char* argv )
{
  char c;
  int len = 1024;
  char expr[len];
  
  // Read the string who's characters need to be counted
  fgets( expr, len, stdin );
  len = strlen( expr );
  if( expr[len-1] == '\n' )
    expr[len-1] = '\0';
  int answer = evaluate_expression(expr);
  printf("%d\n",answer);
  return 0;
}

