//student.c

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "student.h"


/*Create a source file named student.c. In this file, you will do the following:

Write a function named sortStudents(). This function takes in two parameters - 
array of Student objects, size of the array. This function will not return anything. 
This function will sort the students in the increasing order of their id. You can use 
any sorting algorithm - bubble sort, insertion sort, selection sort, or merge sort. 
Keep in mind that the function definition should not change. However, if needed, you can create 
and call another helper function from within this function.
Write a function named print(). This function takes in two parameters - array of Student objects, 
size of the array. The function return type will be void. It will traverse the array and print all 
students in the format (id,name).
Write a function named searchStudent(). This function takes in three parameters - array of Student 
objects, size of the array, and an integer value for the student id. It will use a searching technique 
(linear or binary) to find the student using the id provided as parameter. This function will return 
the Student found. If no student is found, return the first student in the array.
*/


 /*Prototypes here for consistency in functions:
    void sortStudents(Student array[],int length);
    void print(Student array[],int length);
    Student searchStudent(Student array[],int length,int idValue);*/


//function #1
void sortStudents(Student array[],int length){
    int i = 0;
    int j = 0;
    //Selection sort inner/outer loops
    for (i = 0; i < length-1; i++){
        //set min to i
        int min = i;
        //traverse i+1 to n-1
        for (j = i + 1; j < length; j++){
            //if less than min reset min to value found
            if (array[j].id < array[min].id){
                min = j;
            }
        }
    }
}

//function #2
void print(Student array[], int length){
    int i = 0;
    //formatted output
    for (i = 0; i < length - 1; i++){
        printf("(%d,%s) -> ",array[i].id, array[i].name);//**OUPUT**
    }
    printf("(%d,%s)\n",array[n-1].id,array[n-1].name);
}


//function #3
Student searchStudent(Student array[], int length, int idValue){
    int i = 0;
    //linear search loop
    for (i = 0; i < length; i++){
        if(array[i].id == idValue){
            return array[i];
        }
    }
    //If no student is found, return the first student in the array.
    return array[0];
}