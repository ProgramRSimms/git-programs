/*In this programming assignment, you will write a program that reads in the CSV file 
(passenger-data-short.csv), which contains passenger counts for February 2019 on 200 
international flights. The data set (attached below) is a modified CSV file on all International 
flight departing from US Airports between January and June 2019 reported by the US Department of 
Transportation. You write a program that give some summary statistics on this data set.

Create a header file named flights.h. In this file, you will do the following:

Include the header guards
Declare a struct named Flight. It will have the following data members: origin (a 3 letter airport code), 
destination (a 3 letter airport code), airline (a 2 letter airline code), and passengers (a count of the 
passengers on that flight). Remember that a C-style string needs to have one extra null character at the end.
Write a preprocessor directive to represent a constant value for an array size. Name it NUM_FLIGHTS and give 
the replacement value 200.
There will be no separate source file for this header file.*/

//flights.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_FLIGHTS 200

#ifndef STUDENT_H
#include STUDENT_H

typedef struct Flight{
    char origin[4], destination[4], airline[3];
    int passengers = 0;
}Flight;

#endif