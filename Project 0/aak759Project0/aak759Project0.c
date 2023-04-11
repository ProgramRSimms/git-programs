//aak759Project0.c

#include <stdio.h>  //For input/output functions.
#include <stdlib.h> //For malloc, free, etc.
#include <string.h> 
#include "Project0.h"  //Include our own header file for the Employee struct.

/*  STEP BY STEP OBJECTIVE:    
  1.Open the file Project0.txt and read in the first line of the file to determine how many 
    Employees we need for our array, and use malloc() to dynamically allocate an array of this size                             2.Use a loop to read the Employee information from Project0.txt and write the information to the 
    entries of your array.  
	Suggestion:  read a single line of the file using fgets() then use sscanf() 
        to parse out the variables from the line. 										3.Loop through your array and print out the employee information.  Each employee (name, ID, hourly rate) 
    should be on a single line.  The name should be left justified in a column of width 10.  The IDs are each 6			  digits long so they can be printed with a single space after it.  The hourly rate should be printed to 2 
    decimal places.
*/
int main (int argc, char *argv[]){
    
    //vars
    int n = 0, i = 0;
    char line[100];
    char *filename;

    //check for args
    if (argc < 2){
        printf("ERROR NO ARGS\n");
        exit(0);
    }

    //get file from command line arg
    else{
        filename = argv[1];
    }
    // printf("%s\n", filename);//test input
   
    //open file in read mode
    FILE *file = fopen(filename, "r+");
    
    //read Project0Input.txt...if error do this
    if(file == NULL){
        printf("Unable to open the file\n");
    }

    //if error opening.. read line 1 to get # of employees
    else{
        //read one line
        fgets(line, 100, file);
        sscanf(line, "%d\n", &n);
    }

    //Create struct object array of employees    
    Employee *employees = NULL; //Employee employees[n];array parameter set by number of employees read in file
    
    // Dynamically allocate memory 
    employees = (Employee*)malloc(sizeof(Employee) * n);

    //iterate through file with loop
    while(!feof(file)){
	fgets(line, 100, file);
        
	//get full line of data from file
        sscanf(line, "%s %d %lf",employees[i].name, &employees[i].ID, &employees[i].hourlyRate);
        i++;

    }
    //close the file
    fclose(file);

    //output formatted data
    for(i = 0; i < n; i++){
        printf("Name: %s,\t ID: %d,\t Hourly Rate: %.2lf\n", employees[i].name, employees[i].ID, employees[i].hourlyRate);
    }
    // Free the dynamically allocated array memory
    free(employees);
    return 0;

}