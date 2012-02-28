/*
 * Author: Abhiram R - CS10B060
 * Polygon (Implementation)
 */

#include "CLinkedList.h"
#include "Polygon.h"
#include "Point.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Create a new polygon - with no vertices
Polygon* polygon_new()
{
    Polygon* new;
    new = malloc(sizeof(Polygon));
    new->vertices = clinked_list_new();
    return new;
}
// Deletes the polygon, freeing all vertices.
void polygon_delete( Polygon* poly )
{
    clinked_list_delete(poly->vertices);
    free(poly);
}

// Add a vertex
Polygon* polygon_add_vertex( Polygon* poly, Point p )
{    
    poly->vertices = clinked_list_push_back(poly->vertices,p);
    return poly;
}
// Remove a vertex
Polygon* polygon_remove_vertex( Polygon* poly, Point p )
{
    Point* ptr = poly->vertices->head;
    int i;
    for(i=0;i<clinked_list_size(poly->vertices);i++)
    {
        if(point_compare(*ptr,p)==0) 
        {
            poly->vertices = clinked_list_remove(poly->vertices, i);
            break;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return poly;
}

// Returns the number of vertices in the polygon
int polygon_size( Polygon* poly )
{
    return clinked_list_size(poly->vertices);
}
// Prints the vertices in the polygon
void polygon_print( Polygon* poly )
{
    clinked_list_print(poly->vertices);
}

// Find the centroid of the polygon
Point polygon_centroid( Polygon* poly )
{
    int i;
    Point centroid;
    centroid.x=0;
    centroid.y=0;
    Point* ptr;
    ptr = poly->vertices->head;
    for(i=0;i<clinked_list_size(poly->vertices);i++)
    {
        centroid.x+= ptr->x;
        centroid.y+= ptr->y;
        ptr = ptr->next;
    }
    centroid.x = centroid.x/clinked_list_size(poly->vertices);
    centroid.y = centroid.y/clinked_list_size(poly->vertices);
    return centroid;
}
double area_of_triangle( Point* a,  Point* b, Point* c)
{
    return fabs(((a->x)*((b->y)-(c->y)) + (b->x)*((c->y)-(a->y)) + (c->x)*((a->y)-(b->y)) )/2.0) ;
}
// Find the area of the polygon
double polygon_area( Polygon* poly )
{
    double area=0;
    double increment;
    int i;
    Point* ptr;
    ptr = poly->vertices->head;
    Point centroid = polygon_centroid(poly);
    for(i=0;i<clinked_list_size(poly->vertices);i++)
    {
        increment = area_of_triangle(&centroid, ptr, ptr->next); 
        area = area + increment;
        ptr = ptr->next;
    }
    return area;
}  

