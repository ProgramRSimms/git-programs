//main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

/*Create a main.c source file with the main() that will do the following:
Example output for the sample input file attached, a09-input.csv along with user input of 1003 to search for a student.

(1004,John) -> (1001,Steve) -> (1003,Mary) -> (1002,Sarah) -> 
(1001,Steve) -> (1002,Sarah) -> (1003,Mary) -> (1004,John) -> 
(1003,Mary)*/



 //prototypes 
    /*void sortStudents(Student array[],int length);
    void print(Student array[],int length);
    Student searchStudent(Student array[],int length,int idValue);
    void sortNames(Student name1,Student name2);*/

//main function storing command line argument
int main(int argc, char *argv[]){
    
    //vars
    char data[1000];//stores one line in file
    int count = 0;//counts the number of students
    int i = 0;//for loop
    int j = 0;//for loop
    
    //Read in the name of the input file a09-input.csv through the command line argument. 
    //If the argument is not there, print out the error message: ERROR NO ARGS and end the program.
    if(argc <= 1){
        // if argument count less than a.out and fileName
        printf("ERROR NO ARGS\n");
        exit(0);
    }
    FILE *fileIn;
    //Open the file for reading. 
    fileIn = fopen(argv[1],"r");//open from command line in read mode

    //If the file does not open, print out the error message: ERROR FILE NOT OPEN and end the program.
    if(fileIn == NULL){
        printf("ERROR FILE NOT OPEN");
        exit(0);
    }
    
    //Go through the file once to obtain the number of records in the file.  
    while (fscanf(fileIn,"%s", data) != EOF){
        count++;//count students in file
    }
    //Rewind the file pointer. 
    rewind(fileIn);

    //Dynamically create the array of Student objects.
    Student *array = ((Student*)malloc(sizeof(Student) * count));

    //Read the file again and store all the student information in the array created. 
    int counter = 0;//start at student[0]
    while (fscanf(fileIn,"%s",data) != EOF){
        int id = 0;//id object for student struct
        for (i = 0; data[i] != '\0'; i++){
            if (data[i] == ','){
                j = i;
                break;
            }
            //id conversion to int
            id = id * 10 + (data[i]-'0');
        }
        //parse student name
        char name[10];//name object for student struct
        int index = 0;//find index
        for(i = j+1; data[i] != '\0';i++){
            name[index++] = data[i];
        }
        //find end
        name[index] = '\0';

        //parse data into array
        array[counter].id = id;
        strcpy(array[counter].name, name);

        counter++;
    }

    //Close the file.
    fclose(fileIn);

    //Call print() to print out the student information in the format mentioned below.
    print(array, count);

    //Call sortStudents() to sort all the array of students in the increasing order of their id.
    sortStudents(array, count);

    //Call print() again to print out the sorted student information in the format mentioned below.
    print(array, count);

    //Ask the user to input a student id. DO NOT print any prompt for the user, directly use scanf.
    int userInput;//id integer from user
    scanf("%d", &userInput);

    //Call searchStudent() to find the student matching the student id provided by the user. 
    Student key = searchStudent(array, count, userInput);

    //Print the student information for the returned student in the format (id,name).
    printf("(%d,%s)\n", key.id, key.name);

    //Once done, free the dynamic array.
    free(array);

    return 0;
}