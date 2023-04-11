/*point.c*/

#include "point.h"

//MIDPOINT
/*A = (x1, y1, z1)
B = (x2, y2, z2)
M = ((x1+x2)/2, (y1+y2)/2, (z1+z2)/2)*/

void midpoint(struct Point A, struct Point  B,struct Point *C){
    //(pointer_name)->(variable_name)
    C->x = (A.x + B.x)/2;//assign C with value of 3D point x @ struct member A + point x @ struct member B
    C->y = (A.y + B.y)/2;//assign C with value of 3D point y @ struct member A + point y @ struct member B
    C->z =( A.z + B.z)/2;//assign C with value of 3D point z @ struct member A + point z @ struct member B
}
//DISTANCE
/*A = (x1, y1, z1)
B = (x2, y2, z2)*/

void distance(struct Point A, struct Point B, double *D){
    //DISTANCE FORMULA 
    *D = sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y), 2) + pow((A.z - B.z), 2));
}