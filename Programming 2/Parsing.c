//parsing a string lab

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h> //for isspace() function
#define SIZE 100     

int main(int argc, char *argv[]){
   //vars.
   char userInput[SIZE];
   char *words = userInput;
   int found = 0, i = 0;
   
   // Allocate the memory.
   words = (char*)malloc(sizeof(*words) * SIZE);
   
   // Prompt/get input
   printf("Enter input string:\n");//**OUTPUT**
   
   //printf("%s\n", userInput);//****TEST IF GETTING INPUT****
   
   
   /* 1. check whether the input is q. and quit if so
      2. check whether input contain comma and 
      3. print message if it does not contain a comma separate the string into two word using comma, and go through the word character by character and print if the character is not a space .
      4. read in the next line using fgets*/
//FIRST: CHECK IF QUIT PASSED BY USER
   //loop for 'q'
   while (userInput != NULL){
      // Check for 'q' 
      if (userInput[0] == 'q'){
         exit(0);// Exit the program.
      }
      fgets(userInput, SIZE, stdin);
      
//NEXT: LOOK FOR A COMMA AND SPACE FOR VALID INPUT STYLE
      // loop to find comma
      for (i = 0; i < strlen(userInput); i++){
         if (userInput[i] == ','){// if not found break
            found = 1;
         }  
         else {
            found = 0;
            printf("Error: No comma in string.\n");//**OUTPUT**
            // Prompt for valid input
            printf("\n");//newline
            printf("Enter input string:\n");//**OUTPUT**
            fgets(userInput, SIZE, stdin);
            break;
         }
      }
      while (found == 1) {
         i = 0;
         char *word1 = strtok(userInput, ",");//token 
         char *word2 = strtok(NULL, "\0");//token
         //printf("First word: %s\n", word1);
         //printf("Second word: %s\n", word2);
         
         for (i = 0; i < strlen(word1); i++){ 
            if(isspace(word1[i]) == 0){
               printf("%c", word1[i]);
            }
         }
         printf("\n");//newline outside loop
         printf("Second word: ");
         for (i = 0; i < strlen(word2); i++){
            if(isspace(word2[i]) == 0){
               printf("Second word: %s\n", word2);
            }
         }
         printf("\n");//newline outside loop
      }
      fgets(userInput, SIZE, stdin);   
   }
   return 0;
}