//main.c


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc,char *argv[]){
    if (argc < 2){
        printf("ERROR NO ARGS\n");
        exit(0);
    }
    else {
        LLNode *head = NULL, *node;

        FILE *fileIn;
        fileIn = fopen(argv[1], "r");
        if(fileIn == NULL){
            printf("ERROR FILE NOT OPEN");
            exit(0);
        }
        char line[256];
        while (fgets(line, sizeof(line), fileIn)) {
            char *token = strtok(line, ",");
            int id = atoi(token);
            char *name = strtok(NULL, ",");
            double gpa = atof(strtok(NULL, ","));
            node = createNode(id, name, gpa);
            insertNode(&head, node);
        }
        printf("Average = %.2lf\n", averageGPA(&head));
        printLL(&head);
        destroyLL(&head);
    }
    return 0;
}
