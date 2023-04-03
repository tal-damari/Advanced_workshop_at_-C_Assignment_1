// Course: Advanced C programming
// exercise 1, question 2
// file name: ex1_q2.c
#define _CRT_SECURE_NO_WARNINGS
// --------------------------- //
// include package section:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// --------------------------- //


// --------------------------- //
// function declaration and main section:
// DO NOT CHANGE anything in the following macro:
#ifdef FUNC_DECLARE
#include "ex1_q2.h"
#else
#define FUNC_DECLARE

// struct declaration section:
typedef struct point
{
	int x, y;
}point;

typedef struct polygon
{
	int n;
	point* points;
	double scope;
}polygon;
// --------------------------- //

unsigned long student_id();
void scanPoint(point*);
void scanPolygon(polygon*);
double distance(point*, point*);
void calculatePolygonScope(polygon*);
void freeMemory(polygon*);

int main()
{
	unsigned long id_num;
	polygon poly;

	// call functions:
	id_num = student_id();
	printf("[id: %lu] start main\n", id_num);

	scanPolygon(&poly);
	calculatePolygonScope(&poly);
	freeMemory(&poly);

	// write output:
	printf("Output: Scope of polygon: %.2lf\n", poly.scope);

	return 0;
}
#endif
// --------------------------- //


// --------------------------- //
// function implementation section:
unsigned long student_id()
{
	// return your id number,
	// for example if your id is 595207432
	// return 595207432
	// your code:
	return 123456789;
}
// --------------------------- //


/// <summary>
/// Function scan a point in the plane,
/// Used as auxiliary function for createPolygon.
/// </summary>
/// <param>point* p - pointer to p</param>
/// <returns>None</returns>
void scanPoint(point* p)
{
	// your code:
	printf("Please enter x and y to point:\n");
	scanf("%d", &p->x);
	scanf("%d", &p->y);
}
// --------------------------- //


/// <summary>
/// Function scan a polygon with n verticies,
/// Example of input parameters:
/// 4 1 2 2 3 3 2 2 1
/// translate to 4 points with values: 
/// (1,2), (2,3), (3,2), (2,1) 
/// </summary>
/// <param>polygon* poly - pointer to polygon</param>
/// <returns>None</returns>
void scanPolygon(polygon* poly)
{
	// your code:
	unsigned size, i;
	point* arr_points;
	printf("please enter the desired number of points in polygon:\n");
	scanf("%d", &size);
	poly->n = size;
	arr_points = (point*)malloc(size * sizeof(point));
	if (arr_points)
	{
		for ( i = 0; i < size; i++)
		{
			scanPoint(&arr_points[i]);
		}
	}
	poly->points = arr_points;
}
// --------------------------- //


/// <summary>
/// Function calculates distance between 2 adjacent points  
/// </summary>
/// <param>point* p1 - pointer to the first point</param>
/// <param>point* p2 - pointer to the second point</param>
/// <returns>The Euclidean distance between p1 and p2</returns>
double distance(point* p1, point* p2)
{
	// your code:
	int calculatex= 0, calculatey = 0,sum=0;
	double new_distance;
	calculatex=(p1->x - p2->x)* (p1->x - p2->x);
	calculatey = (p1->y - p2->y) * (p1->y - p2->y);
	sum = calculatex + calculatey;
	new_distance = sqrt((double)sum);
	return new_distance;
}
// --------------------------- //


/// <summary>
/// Function calculates the Scope of the entire polygon.
/// Setting the result inside the polygon object.  
/// </summary>
/// <param>polygon* poly - pointer to polygon</param>
/// <returns>None</returns>
void calculatePolygonScope(polygon* poly)
{
	// your code:
	int i;
	double sum_scope = 0;
	point* p1, * p2;
	for ( i = 1; i < poly->n; i++)
	{
		p1 = &poly->points[i];
		p2 = &poly->points[i - 1];
		sum_scope += distance(p1, p2);
	}
	p1 = &poly->points[0];
	p2 = &poly->points[poly->n - 1];
	sum_scope += distance(p1, p2);
	poly->scope = sum_scope;
}
// --------------------------- //


/// <summary>
/// Function free alocated memory. 
/// </summary>
/// <param>polygon* poly - pointer to polygon</param>
/// <returns>None</returns>
void freeMemory(polygon* poly)
{
	// your code:
	free(poly->points);
	poly->points = NULL;
}
// --------------------------- //