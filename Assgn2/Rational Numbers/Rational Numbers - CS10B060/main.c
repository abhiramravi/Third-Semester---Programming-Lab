/*************************************************************************************************
This is the Main Function used to test whether all the functions are properly working.
Author : Abhiram R - CS10B060   
Date : 12.8.11
*************************************************************************************************/
#include<stdio.h>
#include<math.h>
#include"rational.h"

int main() 
{
    rational rat_1;
    rational rat_2;
    char* string = "2/3";
    rat_1.p = 56;
    rat_1.q = 30;
    rat_2.p = 24;
    rat_2.q = 18;
    reduce(&rat_1);
    reduce(&rat_2);
    rational rat_parsed = rational_parse( string ); 
    rational_print( rat_1 ); 
    rational_print(rat_2);
    rational rat_from_int = rational_from_int( 5 );
    double rat_in_double = rational_to_double( rat_1 ); 
    rational rat_added = rational_add( rat_1,rat_2 );
    rational rat_subtracted = rational_sub( rat_1, rat_2 ); 
    rational rat_multiplied = rational_mul( rat_1, rat_2 ); 
    rational rat_divided = rational_div( rat_1, rat_2 );
    rational rat_reciprocated = rational_reciprocate( rat_1 ); 
    printf("parsed : %d/%d\n",rat_parsed.p,rat_parsed.q);
    printf("from int :%d/%d\n",rat_from_int.p,rat_from_int.q);
    printf("added : %d/%d\n",rat_added.p,rat_added.q);
    printf("subtracted : %d/%d\n",rat_subtracted.p,rat_subtracted.q);
    printf("multiplied : %d/%d\n",rat_multiplied.p,rat_multiplied.q);
    printf("divided : %d/%d\n",rat_divided.p,rat_divided.q);
    printf("reciprocated : %d/%d\n",rat_reciprocated.p,rat_reciprocated.q);
}
