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
        return 0; break;
      // The token is a numeral
      default:
        return t.num; break;
    }

  } while( !is_eoe( t ) );

}

/*int value_expression( Token a, Token b, Token c, char* exp)
{
  if(!is_op(b) && !is_op(c)) 
  {
    switch( a.op ) 
    {
      // The token is an addition symbol
      case ADD:
        return b.num + c.num; break;
      case SUB:
        return b.num - c.num; break;
      case MUL:
        return b.num * c.num; break;
      case DIV:
        return b.num / c.num; break;
      // EOE stands for end of expression; Print a new line
      default:
        printf( "what cup\n" ); break;
    }
  }	
  else
  {
	Token d = read_token(exp);
	Token e = read_token(exp);
	switch( a.op ) 
    {
      // The token is an addition symbol
      case ADD:
        return value_expression(b,c,d,exp) + value_expression(c,d,e,exp); break;
      case SUB:
        return value_expression(b,c,d,exp) - value_expression(c,d,e,exp); break;
      case MUL:
        return value_expression(b,c,d,exp) * value_expression(c,d,e,exp); break;
      case DIV:
        return value_expression(b,c,d,exp) / value_expression(c,d,e,exp); break;
      // EOE stands for end of expression; Print a new line
      default:
        printf( "what cup\n" ); break;
    }
  }	

}*/

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
  Token a = read_token(expr);
  Token b = read_token(expr);
  Token c2 = read_token(expr);
  int answer = evaluate_expression(expr);
  printf("%d\n",answer);
  return 0;
}

