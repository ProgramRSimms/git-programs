/*main.c*/

/*Instructions:
In this programming assignment, you will write a C program that uses struct, pointer passing, 
and function calls for working with 3D points (x, y, z). 
You will also organize your program into separate source and header files.

Create a header file named point.h. 
Include the header guards
Create a struct named Point which will contain three double valued data members: x, y, and z.
Write two functions (see below point.c). Declare their prototypes. 
Function names should be exactly as shown below.

Create a source file named point.c. In this file, you will do the following:
Write a function named midpoint() that takes in three parameters - two 3D points and a third parameter which is a pointer to a Point variable. This function will not return anything and hence the return type should be void. This function calculates a new point which is the midpoint of these 2 points and updates the Point value pointed by the parameter passed into this function. If two points are represented as A = (x1, y1, z1) and B = (x2, y2, z2), then the midpoint is M = ((x1+x2)/2, (y1+y2)/2, (z1+z2)/2)
Write a function named distance() that takes in three parameters - two 3D points and a third parameter which is a double pointer type for distance. The function will not return anything and hence the return type should be void. This function calculates the distance between these 2 points and updates the value pointed by the double pointer passed into this function. If two points are represented as A = (x1, y1, z1) and B = (x2, y2, z2), then the distance d is calculated as shown here
No printf() statements can exist in these functions in this file. 
These functions should return the required results.

Write the main() that will do the following:
All printing should happen in main.

Take the values for the points from the users
Call the midpoint() function to calculate and obtain the midpoint for A and B. 
The midpoint will be updated directly by the function and the call will not return anything.
 
The distance value will be updated directly by the function and the call will not return anything.
Print the midpoint and distance values as shown below. 
The output must look exactly like this in terms of formatting. 
There is only one space between the colon and the result. 
Results are shown with exactly two decimal places. 

The example shows the solutions for when the A is (1, 1, 1), B is (2, 3, 4).
midpoint: 1.50, 2.00, 2.50
distance: 3.74

Save your files as main.c, point.c, and point.h and upload them below for grading.*/

#include "point.h"

int main (int argc, char* argv[]){
    //Declare two 3D points A and B using the structure created.
    //typedef;
    struct Point A;//
    struct Point B;//
    struct Point C;//

    double D;//distance
    
    //printf("Enter the details of point 1 : ");
    scanf("%lf", &A.x);
    scanf("%lf", &A.y);
    scanf("%lf", &A.z);

    //printf("Enter the details of point 2 : ");
    scanf("%lf", &B.x);
    scanf("%lf", &B.y);
    scanf("%lf", &B.z);

    //newline
    midpoint(A, B, &C);
    printf("midpoint: %.2lf, %.2lf, %.2lf", C.x, C.y, C.z);
    
    //newline
    printf("\n");
    //Call the distance() function to calculate and obtain the distance between A and B.
    distance(A, B, &D);
    printf("distance: %.2lf", D);
    
    return 0;   
}