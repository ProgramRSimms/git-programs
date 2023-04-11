//main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flights.h"

/*Write the main() that will do the following:

Read in the name of the file through the command line argument. If the argument is not there, print out the 
error message: ERROR NO ARGS and end the program.
Open the file for reading. If the file does not open, print out the error message: ERROR FILE NOT OPEN and end 
the program.
Dynamically allocate an array of 200 Flight struct objects.
Read in and parse the CSV into this array.
csv:

//JFK	LHR	BA	80736

3 letter code at argv[0]
2 letter airline code at argv[2]
passenger count at argv[3]

Ask the user to enter a two letter airline code. Then, traverse the array and count two things: the number of 
flights that airline operates and the total number of passengers for those flights.
Close the file and free the dynamic array when you are done.
The output must look exactly like below in terms of formatting. There is only one space after the colon.
csv = comma separated values
*/

int main(int argc, char *argv[]){

   //fgets(buffer, sizeof(buffer),fileIn);//in case needed

    //check for valid command line args from input
    if (argc < 2){//need two args:
        printf("ERROR NO ARGS");
        return 1;
    }

    //open file and check if NULL
    FILE *fileIn = NULL;
    fileIn = fopen(argv[1], "r");//filename and read mode//fileIn = fopen(argv[1], "r");
    //rewind(fileIn);
    //check if file opened
    if (fileIn == NULL){
        printf("ERROR FILE NOT OPEN");
        exit(0);
        fclose(fileIn);
    }
    //vars
    Flight* arr;//read csv file into this struct array
    //char flightPtr[200];//200 struct objs use **USE PREPROC DIRECTIVE**
    char airlineCodeInput[2];//2 chars plus null char
    int flights = 0;//flight counter for output
    int passengers = 0;//passenger counter for output
    int i = 0;//for loop

    //dynamic allocation of array of 200 struct OBJs using preprocessor directive
    arr = ((Flight*)malloc((NUM_FLIGHTS + 1)* (sizeof(Flight))));//memory for struct objs

    //prompt user for airline code
    //printf("Please enter a two-letter airline code: \n");//**OUTPUT**
    scanf("%s", airlineCodeInput);
    
    /* csv data format: - data separated by whitespace??
        
        JFK	LHR	BA 80736 
        3 letter code at argc[0] or argc[1]
        2 letter airline code at argc[2]
        passenger count at argc [3]*/

    //traverse the array and count two things: the number of flights that 
    //airline operates and the total number of passengers for those flights.

    //read csv and parse into struct array (arr)
    //char buffer[500];//in case needed
    while (!feof(fileIn)){
        fscanf (fileIn," %[^,],%[^,],%[^,],%d", arr[i].origin, arr[i].destination, arr[i].airline, &arr[i].passengers);
        i++; //increment/count csv files
    }
    //printf("\n Enter the airline code: ");
    //scanf("%s", airlineCodeInput); //ask user to input the airline code
    //printf("airlineCodeInput");//**test OUTPUT**
    //loop to count number of flights in that airline code
        
    int j = 0;//initialize to use in loop
    //loop to compare csv to user input airline code
    for (j = 0; j < i; j++){
        //if found get count of flights and passenger count for output
        if (strcmp(airlineCodeInput, arr[j].airline) == 0){//compare user code to struct array
            flights++;//increment flight count
            passengers = passengers + arr[j].passengers;//get passenger count
        }
    }
    //Output
    if (flights != 0){// if count has incremented at all then print the data
        printf("airline: %s\nflights: %d\npassengers: %d\n", airlineCodeInput, flights, passengers);//**OUTPUT**
    }
    else{
        printf("No data retrieved.\nPlease enter a two-letter airline code: \n");//**OUTPUT**
    }
    fclose(fileIn);
    free(arr);
    return 0;
}

//PRIOR ATTEMPTS GRAVEYARD: \/

//char * token = strtok(string, " ");
//while (fgets(buffer, 500, fileIn) != NULL && i < (*count))
/* 
void getData(char buff[]) 
{ 
   char *token = strtok(buff,","); 
   int counter=0; 
 
   while( token != NULL )  
   { 
    counter++;  
    printf( " %s\n",token); 
    token = strtok(NULL,","); 
   }       
} 

//
#include <stdio.h>

#include <stdlib.h>

FILE *filePointer;

char file[12];

char * filename = file;

filename= “file.csv\0” ;

filePointer = fopen(filename, “r”);

if (filePointer == NULL) {

fprintf(stderr, “ERROR: Unable to open file: %s\n”, filename);

exit(-1);

}

//allocating enough room for 255 characters, plus the null terminator for the string

char * wordRead = malloc(256 * sizeof(char));

while ((ret = sscanf(filePointer, “%s[^,]”, wordRead)) != EOF) {

printf(“Word read in: %s”, wordRead);

}

free(wordRead);

fclose(filePointer);*/

/*while (fgets(buffer, sizeof(buffer),fileIn)){
        char *token = strtok(arr, " ");//space in array 
        while (fgets(buffer, 500, fileIn) != NULL){
            char* line[12];
            while (i < 5){
                line[i] = strtok(buffer, token);
                    printf("%s\n",line[x]);
                    i++;
            }
        }
    }
    
    
    */