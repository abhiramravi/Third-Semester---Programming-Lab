/*
 * Author: Abhiram R - CS10B060
 * A point (Implementation)
 */

#include "Point.h"
#include<stdio.h>
#include<stdlib.h>

Point point_new( double x, double y )
{
    Point new;
    new.x = x;
    new.y = y;
    /*new.next = NULL;  */
    return new;
}
Point point_add( Point x, Point y )
{
    Point sum;
    sum.x = x.x + y.x;
    sum.y = x.y + y.y;
    /*See if you should add the ptr being NULL statement here too.*/
    return sum;
}
Point point_sub( Point x, Point y )
{
    Point diff;
    diff.x = x.x - y.x;
    diff.y = x.y - y.y;
    /*See if you should add the ptr being NULL statement here too.*/
    return diff;
}
Point point_mul( Point x, double y )
{
    Point mult;
    mult.x = (x.x)*y;
    mult.y = (x.y)*y;
    return mult;
}
Point point_div( Point x, double y )
{
    Point div;
    div.x = (x.x)/y;
    div.y = (x.y)/y;
    return div;
}
double point_dot( Point x, Point y )
{
    double dot;
    dot = (x.x) * (y.x) + (x.y) * (y.y);
    return dot;
}
void point_print( Point* x )
{
    printf("(%f,%f) ",x->x,x->y);
    
}
int point_compare(Point x, Point y)
{
    if(x.x == y.x && x.y==y.y) return 0;
    else return 1;
}
