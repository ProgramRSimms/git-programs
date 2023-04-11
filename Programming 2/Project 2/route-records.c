//routeRecords.c

#include <stdio.h>
#include <stdlib.h>
#include "routeRecords.h"

//function #1
RouteRecord* createRecords(FILE* fileIn){
    RouteRecord *r;
    r = (RouteRecord*)malloc(rLength * sizeof(RouteRecord));//FIX ME LENGTH
    //rLength =
    return r;
} 
/*•	Column 1 – Month (1 – January, 2 – February, 3 – March, 4 – April, 5 – May, 6 – June)
•	Column 2 – 3-letter IATA Airport Code for the origin airport (e.g., SAT for San Antonio International Airport)
•	Column 3 – 3-letter IATA Airport Code for the destination airport
•	Column 4 – 2-letter IATA Airline Code for the airline (e.g., AA for American Airlines). Some airlines will have a 3-letter airline code, your program will exclude them from the parsing.
•	Column 5 – The passenger category, in our example, there is only one category.
•	Column 6 – Total number of passengers in that month for that route
*/

//function #2
int fillRecords(RouteRecord *r, FILE *fileIn){
    int month;//&month when passed
    char origin[4];
    char destination[4];
    char airline[3];//exclude 3 letter codes
    char paxType[];//only one type
    int paxCount;//# of pax for month -- &paxCount when passed
    char buffer[1000];
    int length = 0;
    int i = 0;//for loops
    int j;//for loops
    int k;//for loops
    int fileLength = getLength(fileIn);
    /*Note that there is a header row you must skip. Since this data holds passenger statistics for each route operated by an airline for six months, you should see the airline route repeated six times. 
    For example, you will see the JFK to LHR operated by BA route 6 times, once for each of the six months.*/
    
    //check for header
    char checker[5];
    if (strcmp(checker, "MONTH") == 0){
        rewind(fileIn);
        return 1;
    }
    else{
        rewind(inputFile);
        return 0;
    }
    fgets(buffer, 1000, fileIn);

    while (i < fileLength && !feof(fileIn)){
        fgets(buffer, 1000, fileIn);
        sscanf(buffer, "%d,%[^,],%[^,],%[^,],%[^,],%d", &month, origin, destination, airline, paxType, &paxCount);
        if (strlen(airline) != 3){
            j = findAirlineRoute(r, length, origin, destination, airline);
            if (j == -1){
                strcpy((*(r + length)).origin, origin);
                strcpy((*(r + length)).destination, destination);
                strcpy((*(r + length)).airline, airline);
                    for (k = 0; k < 6; k++){
                        (*(r + length)).paxCount[k] = 0;
                    }
                    (*(r + length)).paxCount[month - 1] = paxCount;
                    length++;
            }
            else{
                (*(r + j)).paxCount[month - 1] = paxCount;
            }
        }
        i++;
    }
    printf("Unique routes operated by airlines: %d\n", length);
    return length;
}
//function #3
int findAirlineRoute(RouteRecord* r, int length, const char* origin, 
const char* destination, const char* airline){
    int route = -1;
    int i = 0;
    while (i < length && route == -1){
        RouteRecord temp = (*(r + i));//temp record
        if (strcmp(temp.origin, origin) == 0){
            if (strcmp(temp.destination, destination) == 0){
                if (strcmp(temp.airline, airline) == 0){
                    route = i;
                }
            }
        }
        i++;
    }
    return route;
}

//function #4
void searchRecords(RouteRecord* r, int length, const char* key1, 
const char* key2, SearchType st){
    int i;
    int j;
    int matches = 0;
    RouteRecord *temp;
    int totalPassengers[6];
    printf("\n");//newline
}
/*For project-2, the printRecords() function is not really being 
used anywhere in the other parts of the code. This is my mistake. 
However, you still should have that function in your code, the TA 
will grade it. The function should basically be able to go through 
all the unique records in the dynamic array and print all records 
in one line --- similar to the actual data in some logical format 
e.g. origin,destination,code,month,passengerCount*/
//function #5
void printRecords(RouteRecord* r, int length){


//function #6
void printMenu(){
    printf( "\n\n######### Airline Route Records Database MENU #########\n");
    printf( "1. Search by Route\n");
    printf( "2. Search by Origin Airport\n");
    printf( "3. Search by Destination Airport\n");
    printf( "4. Search by Airline\n");
    printf( "5. Quit\n" );
    printf( "Enter your selection: ");
}
// function #7
int getLength(FILE *fileIn){
    int count;
    char buffer[1000];
    while (!feof(fileIn) && count != -1){
        fgets(buffer, 1000, fileIn);
        count++;
    }
    rewind(fileIn);
    return count;
}