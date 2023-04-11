`//project2-main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "routeRecords.h"

/*CSV
•       Column 1 – Month (1 – January, 2 – February, 3 – March, 4 – April, 5 – May, 6 – June)
•       Column 2 – 3-letter IATA Airport Code for the origin airport (e.g., SAT for San Antonio International Airport)
•       Column 3 – 3-letter IATA Airport Code for the destination airport
•       Column 4 – 2-letter IATA Airline Code for the airline (e.g., AA for American Airlines). Some airlines will have a 3-letter airline code, your program will exclude them from the parsing.
•       Column 5 – The passenger category, in our example, there is only one category.
•       Column 6 – Total number of passengers in that month for that route
*/

//PROTOTYPES

//function #1
RouteRecord* createRecords(FILE *fileIn);
//function #2
int fillRecords(RouteRecord *r, FILE *fileIn);
//function #3
int findAirlineRoute(RouteRecord *r, int length, const char *origin, const char *destination, const char *airline);
//function #4
void searchRecords(RouteRecord *r, int length, const char *key1, const char *key2, SearchType st);
//function #5
void printRecords(RouteRecord *r, int length);
//function #6
void printMenu();
//function #7 additional 
int getLength(FILE *fileIn);




//Main Function
int main( int argc, char *argv[]){

    /* 1. Declare variables here */
    int userInt;
    //strcpy(userInt, argv[1]);
    int checker = 0;
    char key1[5];//origin values
    char key2[5];//destination values
    SearchType search = 0;//enum object: search
    char buffer[100];

    /* 2. Check command line arguments here. If a command line argument (for the file name) is missing, print out the following: ERROR: Missing file name and end the program */
    if (argv[1] == NULL){
        printf("ERROR: Missing file name.");
        exit(1);
    }
    /* 3. Attempt to open the file. Print out Opening <filename>... before you call fopen(). */
    FILE *fileIn;
    printf("Opening %s\n", argv[1]);//***OUTPUT***
    fileIn = fopen(argv[1], "r");

    /* 4. Check to see if the file opens. If it does not open, print out ERROR: Could not open file and end the program. */
    if (fileIn == NULL){
        printf("ERROR: Could not open file and end the program.");
        exit(1);
    }

    // 5. Do the following to load the records into an array of RouteRecords
    RouteRecord *r;

    //5.1 Call createRecords(), which will read through the file once to find the total number of lines/records in the file. Use this count, to dynamically allocate memory for an array of RouteRecords. 
    //It returns a pointer to that array. Don't forget to rewind the file pointer.
    r = createRecords(fileIn);

    //5.2 Call fillRecords() to go through the CSV file again to fill in the values. It will then return the actual number of items the array has. Recall that not all records in the original CSV file will be entered into the array. Print the number of unique routes operated by different airlines: Unique routes operated by airlines: ???
    int rLength = fillRecords(r, fileIn);

    //5.3 Close the the file.
    fclose(fileIn);

    // 6. Create an infinite loop that will do the following:
    // 6.1 Call printMenu()
    int x = 0;
    while (x >= 0){
        printMenu();

    //6.2 Ask the user to input a value for the menu -- do... while correct parameters passed by user
        printf("Please enter an interger between 1 - 5 : ");

    //6.3 Handle the case in which a non-integer value is entered
        if (isdigit(userInt)!= 0){
            printf("Please enter a integer between 1 - 5 : ");
            return 1;
            exit(0);
        }
    //6.4 Create a switch/case statement to handle all the menu options
    //6.4.1 Each option requires the user to enter a search key
        do{
            scanf("%d", &userInt);
            while (userInt == 0){
                printf("Error: invalid option\n");
                printf("Enter your selection: ");
                fgets(buffer, 100, stdin);
                scanf("%d", &userInt);
            }
            switch (userInt){
                //struct case 1 = route
                case ROUTE + 1:
                    printf("Enter the origin: ");
                    scanf("%s", key1);
                    printf("Enter the destination: ");
                    scanf("%s", key2);
                searchRecords(r,rLength, key1, key2, ROUTE);
                break;
                //struct case 2 = origin
                case ORIGIN + 1:
                    printf("Enter the origin: ");
                    scanf("%s", key1);
                        searchRecords(r,rLength, key1, key2, ORIGIN);
                    break;
                //struct case 3 = destination
                case DESTINATION + 1:
                    printf("Enter the destination: ");
                    scanf("%s", key1);
                        searchRecords(r,rLength, key1, key2, DESTINATION);
                    break;
                //struct case 4 = airline
                case AIRLINE + 1:
                    printf("Enter the airline: ");
                    scanf("%s", key1);
                        searchRecords(r,rLength, key1, key2, AIRLINE);
                    break;
    //6.4.2 Quit needs to free the array
                //struct case 5 = end program
                case QUIT + 1:
                    printf("Goodbye!");
                    free(r);
                    exit(0);
                default:
                    printf("Error: invalid option\n");
                    printf("Please enter a integer between 1 - 5 : ");
                    break;
            }
        } while (userInt <= 0 || userInt > 5);
    }
    return 0;
}
