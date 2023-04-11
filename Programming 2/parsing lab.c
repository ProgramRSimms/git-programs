#include <stdio.h>

#include <stdlib.h>

#include <string.h>



int main(int argc, char *argv[]){

    //vars.

    char *words[100];

    char word1[50], word2[50];

   

    int found = 0;

    // Allocate the memory.

    words = (words*)malloc(strlen(words) * sizeof(words));

    // Prompt

    printf("Enter input string:\n");

    getline(&words, 100, stdin);

    //loop.

    while (words[] != NULL){

        // Check for 'q' 

        if (strlen(words) == 2){

            if (words[0] == 'q'){

            // Exit the program.

            exit(0);
            }
        }

    int i, j = 0;

        // find comma

        for (i = 0; words[i] != '\0'; i++){

        // if comma found break

            if (words[i] == ','){

                // if found break

                found = 1;

                break;
            }

            // new words.

            if (words[i] != ' ' && words[i] != ','){

                word1[j++] = words[i];

                }
        }

        // split the string

        word1[j] = '\0';

        i++;

        j = 0;

        // Check if found.

        if (found== 1){

            

            while (words[i] != '\0'){

                // Enter the characeter in the new string.

                if (words[i] != ' '){

                    word2[j++] = words[i];

                }

                i++;

            }

            split the new string

            word2[j] = '\0';

            // output the found words

            printf("First word: %s\n", word1);

            printf("\nSecond word: %s\n", word2);

        }

        //if no comma found

        else{

            printf("Error: No comma in string.\n");

        }

        // Prompt for valid input

        printf("Enter input string:\n");

        getline(&words, 100, stdin);

    }

}