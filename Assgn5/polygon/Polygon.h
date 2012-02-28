/*
 * Author: Abhiram R - CS10B060
 * Polygon data structure
 */

#ifndef POLYGON_H
#define POLYGON_H

#include "CLinkedList.h"

typedef struct Polygon_ {
    CLinkedList* vertices;
} Polygon;

// Create a new polygon - with no vertices
Polygon* polygon_new();
// Deletes the polygon, freeing all vertices.
void polygon_delete( Polygon* poly );

// Add a vertex
Polygon* polygon_add_vertex( Polygon* poly, Point p );
// Remove a vertex
Polygon* polygon_remove_vertex( Polygon* poly, Point p );

// Returns the number of vertices in the polygon
int polygon_size( Polygon* poly );
// Prints the vertices in the polygon
void polygon_print( Polygon* poly );

// Find the centroid of the polygon
Point polygon_centroid( Polygon* poly );
// Find the area of the polygon
double polygon_area( Polygon* poly );
#endif // POLYGON_H

