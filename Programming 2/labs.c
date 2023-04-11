#include<stdio.h>
#include<stdlib.h>
#include <string.h>

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
   fgets(userInput, SIZE, stdin);
   //printf("%s\n", words);//****TEST IF GETTING INPUT****
   
//FIRST CHECK IF QUIT PASSED BY USER
   //loop for 'q'
   while (userInput != NULL){
      // Check for 'q' 
      if (userInput[0] == 'q'){
         exit(0);// Exit the program.
      }
      
//NEXT LOOK FOR A COMMA AND SPACE FOR VALID INPUT STYLE
      // loop to find comma
      for (i = 0; i < strlen(userInput); i++){
         if (userInput[i] == ','){// if not found break
            found = 1;
            found++;
            if (found == 0){
               break;
            }
         }
         //if no comma found
         else{
            printf("Error: No comma in string.\n");//**OUTPUT**
            // Prompt for valid input
            printf("\n");//newline
            printf("Enter input string:\n");//**OUTPUT**
            fgets(userInput, SIZE, stdin);
         }  
         while (userInput!= NULL){
            char *word1 = strtok(userInput, ",");//token 
            char *word2 = strtok(NULL, "\0");//token
            printf("First word:\t%s\n", word1);//****TEST IF DATA CORRECT****
            printf("Second word:\t%s\n", word2);//****TEST IF DATA CORRECT****
            return 0;
         }
      }
   }
   return 0;
}
   