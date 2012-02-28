/*
 * Author: Abhiram R - CS10B060
 * A point
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#ifndef POINT_H
#define POINT_H
typedef struct Point_ Point;
struct Point_ {
    double x,y;
    Point* next;
};

/* Create a new point */
Point point_new( double x, double y );

Point point_add( Point x, Point y );
Point point_sub( Point x, Point y );

Point point_mul( Point x, double y );
Point point_div( Point x, double y );

// Returns 1 if x > y, 0 if x == y, -1 if x < y
int point_compare( Point x, Point y );

double point_dot( Point x, Point y );
void point_print( Point* x );

#endif // POINT_H
