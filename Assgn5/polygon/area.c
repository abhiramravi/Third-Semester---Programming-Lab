/*
 * Author: Abhiram R - CS10B060
 * Compute the area of a polygon
 */

#include "Polygon.h"
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main( int argc, char* argv[] )
{
    int i;
    double p,q;
    Point e;
    Polygon* poly;
    poly = polygon_new();
    //Point ptr = poly->vertices->head;
    int no_of_vertices;
    scanf("%d",&no_of_vertices);
    fflush;
    for(i=0;i<no_of_vertices;i++)
    {
        scanf("%lf %lf",&p,&q);
        e.x = p;
        e.y = q;        
        polygon_add_vertex(poly, e);
        fflush;
        //ptr->next = malloc(sizeof(Point));
        //ptr = ptr->next;
    }
    printf("%lf\n", polygon_area(poly));
    

    return 0;
}

 //printf("Checkpoint!\n") ;
