// main.c

#include <stdio.h>
#include <stdlib.h>
#include "employee.h"//include header file


/*Write the main() that will do the following:
Call the readData() function with the corresponding parameters, -- a6-input.txt
that will return the dynamically created array of Employee structs. 
Call the getBestEmployee() function to find the best employee from the data read.
Call the writeData() function to print the information for the best employee obtained 
into an output file a6-output.txt.
Free the data array when you are done.*/


int main (int argc, char *argv[]){
    //vars
    int size;//parameter 

    // employee array
    Employee *arr = readData("a6-input.txt", &size);//read input file

    //best employee
    Employee bestEmp = getBestEmployee(arr, size);//function call/update best employee

    // write best employee to file
    writeData("a6-output.txt", bestEmp);//write to output file after updating best employee
   
    free(arr); //free the employee array
    return 0;
}