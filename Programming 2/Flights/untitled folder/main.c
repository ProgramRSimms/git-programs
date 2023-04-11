//main.c #2
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "flights.h"

int main(int argc, char *argv[]){
    //check whether file name provided or not through command line argument
    //to provide file name in command prompt in dev-c
    //goto Execute -> parameter ->provide the file name in parameters to pass to your program
   
    if(argc!=2)
    { //display error message if file name not provided
        printf("\n ERROR NO ARGS");
        return 1; 
   }

   FILE *fp; //declare a file pointer
   //declare variables
   int i=0,j,countflight=0,totalpassengers=0;
   char ac[3]; //ac is used to store the airline code from user
   //open the file in read mode
   fp = fopen(argv[1],"r");
   //unable to open the file
   if(fp==NULL)
   {
      printf("ERROR FILE NOT OPEN");
      return 1;
   }
   //allocate memory to hold 200 flioght data in structure variables
   Flight *fobj = (Flight *)malloc(NUM_FLIGHTS * sizeof(Flight));
   //loop to read the data from file and store them in structure array
   while(fscanf(fp,"%s%s%s%d",(fobj+i)->origin,(fobj+i)->destination,(fobj+i)->airline,&(fobj+i)->passengers)!=EOF)
   {
      i++; //increase the value of i to know number of records read
   }
   printf("\n Enter the airline code: ");
   scanf("%s",ac); //ask user to input the airline code
   //loop to count number of flights in that airline code
   //it is case sensitive
   for(j=0;j<i;j++)
   {
       //compare the airline code with case sensitive
       if(strcmp(ac,(fobj+j)->airline)==0)
       {
           countflight++; //count the number pf flights
           //update the passengers in that flight
           totalpassengers = totalpassengers + (fobj+j)->passengers;
          
       }
  
   }
   //if any flight found with the airline code then
   //print the detail report
   if(countflight!=0)
   {
      printf("\n Airline : %s",ac);
   printf("\n Flights : %d",countflight);
   printf("\n Passengers : %d",totalpassengers );
   }
   else //if no flight found in that code
   printf("\n No such airline found with code : %s",ac);
fclose(fp);
return 0;
}