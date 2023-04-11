#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h> 


//MAIN FUNCTION
int main(int argc, char *argv[]){

    //vars for code and file input
    char *fileName;
    FILE *file;
    char *line = NULL; 
    size_t len = 0;
    ssize_t read;

    //error checking for argument/file input
    /*if (argv < 2){//FIX ME.................................
        printf("Provide a valid txt file as argument: <file.c> <filename.txt>");
        exit(EXIT_FAILURE);
    }

    else{
        fileName = argv[1];//
    }*/
    
    file = fopen(fileName, "r");//open file in read mode
    if (file == NULL){
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1) {//FIX ME.................................
        //printf("Retrieved line of length %zu :\n", read);
        //printf("%s", line);
    }

    fclose(file); 
    if(line){
        free(line);
    }
    exit(EXIT_SUCCESS);
    
    //ask for single line input of postfix expression
    printf("Please enter a postfix expression");
}

//structure for stack
typedef struct Stack {
    int top;
    unsigned capacity;
    int* array;
}Stack;

//create a stack to store postfix data
struct Stack* newStack(unsigned capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if(!stack){
        return NULL;//ignore everything else if not existent
    }
    stack->capacity = capacity;//set size within stack
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));//array to store stack datatype values
    if(!stack->array){
        return NULL;//ignore everything else if not existent
    }
    return stack;
}


 /*    *****FUNCTIONS*****    */
//stack is full when top is equal to the last index
int isFull(struct Stack* stack){
    return stack->top == stack->capacity - 1;
}
 
//stack is empty when top is equal to -1
int isEmpty(struct Stack* stack){
    return stack->top == -1;
}
//peek at data but do not change it
char peek(struct Stack* stack){
    return stack->array[stack->top];
}
//push function... increment
void push(struct Stack* stack, int item){
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;//increment 
    printf("%d pushed to stack\n", item);
}
 
//pop function.. decrement
int pop(struct Stack* stack){
    if (!isEmpty(stack)){
        return -1;//INT_MIN;//FIX ME.................................
    }
    return stack->array[stack->top--];
}
//evaluate the expression
int evaluatePostfix(char *postfixString){ 
    //set size parameter
    struct Stack* stack = newStack(strlen(postfixString)); //FIX ME.................................
    int i;//initialize for loop 

    //evaluate postfix expression and get result if the line is blank, skip it.
    if (!stack){
		return -1;
	} 

    //Scan string
    for (i = 0; postfixString[i]; ++i){ 
        //If operand, THEN push to stack
        if (isdigit(postfixString[i])){ //incl stdlib.h
            push(stack, postfixString[i] - '0'); 
		}
        //If operator, THEN pop twice
        //operand2 = topStack THEN pop topStack
        //operand1 = topStack THEN pop topStack
        else{ 
            int op1 = pop(stack); 
            int op2 = pop(stack); 
            //switch case to handle operators
            switch (postfixString[i]){ 
				case '+': push(stack, op2 + op1); break; 
				case '-': push(stack, op2 - op1); break; 
				case '*': push(stack, op2 * op1); break; 
				case '/': push(stack, op2 / op1); break; 
				case '(': push(stack, op1); break;//FIX ME................................. 
				case ')': push(stack, op2); break;//FIX ME.................................
                break;
                default:
                printf("Error: Invalid operator found in the expression. Please enter a valid expression.\n, %c", postfixString[i]);
                return -1;
            } 
        } 
    } 
    return pop(stack); 
} 
/*
//Author: Roderick Simms (aak759)
//Assignment Number: Lab 3
//File Name: RODERICKSIMMSLab3.c
//Course/Section: CS 2124 Section A1T
//Date: 07/19/2021
//Instructor: Bernard Ku
*/