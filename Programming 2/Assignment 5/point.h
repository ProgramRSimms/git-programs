/*Point.h*/

#ifndef STRUCT_POINT_H
#define STRUCT POINT_H
#include<stdio.h>
#include<math.h>

struct Point{
    double x;
    double y;
    double z;
};

void midpoint(struct Point A, struct Point B, struct Point *C);
void distance(struct Point A, struct Point B, double *D);

#endif