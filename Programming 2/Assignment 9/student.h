//header

#ifndef Student_H
#define Student_H

/*In this programming assignment, you will work with an array of struct objects containing 
Student information and implement sorting and searching operations. 
You can use any code provided in the lecture to help finish this assignment.
Create a header file named student.h. In this file you will do the following:
Include the header guards
Declare the struct named Student for storing student information. Each student 
will have with two data members: id(integer), and name(10 chars).
You will write three functions (see below student.c). Declare their prototypes. Function 
names should be exactly as shown below. Each student information is stored in a separate line 
in the file. For each student, their information (id and name) will be separated by commas. 
See the example ``a09-input.csv``` file shown below (also provided as attachment).
1004,John
1001,Steve
1003,Mary
1002,Sarah*/

//structure to store Student information
typedef struct Student{
    int id;
    char name[11];
    }Student;

    
    /*
    #1 Write a function named sortStudents(). This function takes in two parameters - 
    array of Student objects, size of the array. This function will not return anything. 
    This function will sort the students in the increasing order of their id. You can use 
    any sorting algorithm - bubble sort, insertion sort, selection sort, or merge sort. 
    Keep in mind that the function definition should not change. However, if needed, you can create 
    and call another helper function from within this function.

    #2 Write a function named print(). This function takes in two parameters - array of Student objects, 
    size of the array. The function return type will be void. It will traverse the array and print all 
    students in the format (id,name).

    #3 Write a function named searchStudent(). This function takes in three parameters - array of Student 
    objects, size of the array, and an integer value for the student id. It will use a searching technique 
    (linear or binary) to find the student using the id provided as parameter. This function will return 
    the Student found.*/

    //prototypes 
    void sortStudents(Student array[],int length);
    void print(Student array[],int length);
    Student searchStudent(Student array[],int length,int idValue);
    void sortNames(Student name1,Student name2);

#endif 