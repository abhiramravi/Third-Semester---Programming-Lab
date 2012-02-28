/*************************************************
This describes all the fucntions that were declared in rational.h
Author : Abhiram R  -  (CS10B060)
Date : 12.8.11
*************************************************/

#include<stdio.h>
#include<math.h>
#include"rational.h"
rational rational_parse( char* str )
{
    int i;
    rational rat_num;
    sscanf(str,"%d/%d",&rat_num.p,&rat_num.q);   /* This method is truly amazing :) */
    reduce(&rat_num);
    return rat_num;
}
void rational_print( rational a )
{
    printf("%d/%d\n",a.p,a.q);
}
rational rational_from_int( int a )
{
    rational rat_num;
    rat_num.p=a;
    rat_num.q=1;
    return rat_num;
}
double rational_to_double( rational a )
{
    double rat_num_double;
    return ((double)(a.p))/a.q;
}
rational rational_add( rational a, rational b )
{
    rational rat_num;
    int lcm = least_common_multiple(a.q,b.q);
    rat_num.p = a.p*(lcm/a.q) + b.p*(lcm/b.q);
    rat_num.q = lcm;
    reduce(&rat_num);
    return rat_num;
}
rational rational_sub( rational a, rational b )
{
    rational rat_num;
    int lcm = least_common_multiple(a.q,b.q);
    rat_num.p = a.p*(lcm/a.q) - b.p*(lcm/b.q);
    rat_num.q = lcm;
    reduce(&rat_num);
    return rat_num;
}
rational rational_mul( rational a, rational b )
{
    rational rat_num;
    rat_num.p = a.p*b.p;
    rat_num.q = a.q*b.q;
    reduce(&rat_num);
    return rat_num;
}
rational rational_div(rational a, rational b)
{
    rational rat_num;
    rat_num.p = (a.p)*(b.q);
    rat_num.q = (a.q)*(b.p);
    reduce(&rat_num);
    return rat_num;
}
rational rational_reciprocate( rational a )
{
    rational rat_num;
    rat_num.p = a.q;
    rat_num.q = a.p;
    reduce(&rat_num);
    return rat_num;
}
int least_common_multiple(int a, int b)
{
    int i;
    int max;
    if(a>b) max = a;
    else max = b;
    for(i=1;;i++)
    {
        if(i%a==0 && i%b==0) return i;
    }
}
/* 
Converts the rational number to the reduced form. 
    @params - pointer to the rational number that needs to be reduced
    (ensures the changes are directly made to the original rational number, also saves memory and time)
*/
void reduce(rational* rat_num_ptr)              
{
    int a = (*rat_num_ptr).p;
    int b = (*rat_num_ptr).q;
    int g_c_d = gcd(a,b);
    (*rat_num_ptr).p = ((*rat_num_ptr).p)/g_c_d;
    (*rat_num_ptr).q = ((*rat_num_ptr).q)/g_c_d;
}
int gcd(int x,int y)
{
	if(y%x==0) return x;
	else return gcd(y%x,x);
}
void continued_fraction(int a[100], int k)
{
    int i;
    rational answer = rational_from_int(a[k-1]);
    for(i=k-1;i>0;i--)
    {
        answer = rational_add(rational_reciprocate(answer), rational_from_int(a[i-1]));
    }
    rational_print( answer);
    printf("%f\n",(rational_to_double(answer)));
    return answer;
}
