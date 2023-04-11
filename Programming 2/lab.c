#include<stdio.h>
#include <string.h>

int main(void) {
   char words [100]; 
   int i = 0;
   
   //fgets instead of scanf but if q entered quit
   while (strcmp(words, "q\n") != 0){
        fgets (words, 100, stdin);//will not read more than 100 chars
        if(strchr(words, ',') == NULL){
           printf("Error: No comma in string.\n");
        }
   }
   while (words != NULL){
      if (strcmp(words, "q") == 0) {
               break;
   }
   //search string for space
   for(i = 0; strlen(words) - 1; i++){
      printf("%s", words[i]);
      char newWords = words[i];
      if (words[i] != ","){
         printf("First word: %s\n", words[i]);
         if (words[i] != ' '){
            printf("Second word: %s\n", words[i]);
         }
      }
   }

   return 0;
}