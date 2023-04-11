// employee.c

#include <stdio.h>
#include <stdlib.h>
#include "employee.h"//include header file

/*Create a source file named employee.c. In this file, you will do the following:
Write a function named **readData()** that will take in two input parameters: name of the input file a6-input.txt 
and size of the array (passed by reference as a pointer). The function will return the pointer to the dynamically 
created array of Employee struct. This function will perform the following steps : (1) open the input file for 
reading (2) go through the entire file once to obtain the number of lines, which will be the size of the array to 
be created - make sure to save this in the referenced function parameter (3) dynamically allocate memory for an 
array of Employee (4) rewind the file pointer back to the start of the file (5) read the data from the file and 
populate the dynamically created array (6) close the file (7) return the pointer to the dynamic array that 
contains the employee data.

Write a function named **getBestEmployee()** that will take in two input parameters: pointer to the populated 
array and size of the array. The function will go through the array and find the best employee i.e. the employee 
that has the highest salary. Copy the employee's information in a new Employee variable. The function will return 
this new employee variable.

Write a function named **writeData()** that will take in two input parameters: name of the output file a6-output.txt and 
the best employee obtained from the above function. This function will open the file a6-output.txt for writing and 
print all the information of the employee passed in as parameter - name, id and salary. All the information should 
be printed in a single line with one space in between. Salary should be printed without any decimal values.
No printf() statements can exist in these functions in this file. These functions should return the required results 
and all printing should happen in main.*/


/*prototypes from header file for continuity:
Employee* readData(char *filename, int *size);//return the pointer to the dynamic array that contains the employee data.
Employee getBestEmployee(Employee *arr, int size);//eturn this new employee variable
void writeData(char* filename, Employee a);*/

// function #1
Employee* readData(char *filename, int *size){
    Employee a;
    *size = 0; //set counter to 0
    // open the input file in read mode using pointer to file
    FILE *in = fopen(filename, "r");//read mode "r"

    // read file until the end
    while(!feof(in)){
        fscanf(in,"%s %d %lf",a.name, &a.id, &a.salary);
        (*size)++;//increase array size counter
    }

    //seek file from beginning
    fseek(in, 0, SEEK_SET);
    //employee array
    Employee *Employees = (Employee*)malloc((*size)*sizeof(Employee));

    // read file
    int count = 0;//for loop
    while(!feof(in)){
        fscanf(in,"%s %d %lf",a.name, &a.id, &a.salary);
        Employees[count] = a;//add to array
        count++;//increase employee counter
    }
    fclose(in);//close file
    return Employees;//return pointer to the dynamic array that contains the employee data.
    }

    // function #2
    Employee getBestEmployee(Employee *arr, int size){
        Employee bestEmp = arr[0];//first employee is best then compare to rest via loop
        int i;//for loop
        // loop
        for(i = 1; i < size; i++){
            //compare salary
            if(arr[i].salary > bestEmp.salary){
                bestEmp = arr[i];
            }
        }
        return bestEmp;//return new employee data
    }

// function #3
void writeData(char *filename, Employee a){
    FILE *in = fopen(filename,"w"); //write mode "w"
    fprintf(in, "%s %d %.0f",a.name, a.id, a.salary);/*(name id salary) separated by space - 
                                                            Salary should be printed without any decimal values.*/
    fclose(in); //close file
}/*Lot of you guys are facing issue with passing the tests for Programming Assignment-6. 
The main issues that I am seeing is that you guys are not having the correct types for the 
function return values and parameters. E.g. readData() function -- it is mentioned in the 
description that there should be 2 parameters - name of the input file a6-input.txt and size 
of the array (passed by reference as a pointer). Also, the return type of the function should 
be the pointer to the dynamically created array of Employee struct.*/