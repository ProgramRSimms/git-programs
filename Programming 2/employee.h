// employee.h

/*Create a header file named employee.h. In this file, you will do the following:
Include the header guards
Declare a struct named Employee with three data members: name (10 chars max with no spaces), 
id (integer) and salary (double).
You will write three functions (see below employee.c). Declare their prototypes. Function names 
should be exactly as shown below.
Each employee information is stored in a separate line. All 3 of the employee information will be 
separated by spaces. See the sample a6-input.txt file shown below (also provided as attachment).*/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct Employee{
    char name[10];//per instructions
    int id;//per instructions
    double salary;//per instructions
}Employee;

//prototypes:
Employee* readData(char *filename, int *size);//return the pointer to the dynamic array that contains the employee data.
Employee getBestEmployee(Employee *arr, int size);//eturn this new employee variable
void writeData(char *filename, Employee a);

#endif