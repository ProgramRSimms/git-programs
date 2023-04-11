#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0


//#1 create stack
Stack *newStack(int maximumStackSize){
    maximumStackSize = 0;//initialize maxsize to 0
    Stack *s = (Stack*)malloc(sizeof(Stack);//malloc a new Stack
    s->stackElements = (Element*)malloc(s->maxSize * sizeof(Element));//malloc an array of elements the size of maximumStackSize(int)
    //s->stackElements = maximumStackSize;//store array in stackElements pointer
    s->maxSize = maximumStackSize;//
    s->top = 0;//stack size
    //struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 

	if (!StackImp){ 
		return NULL; 
    }

    return s;//return pointer to stackImp
}
//#2 free arrays/stacks
void freeStack(Stack s){
    free(s->stackElements);
    free(s);
    /*int i;
    for(i = 0; i < count; i++){
        free(s->stackElements[i]);
        free(s[i]);*/
    }
}
//#3 push function
void push(Stack s, Element e){
    int i;
    if (s->top >= s->maxSize){
        printf("Stack is full\n");//Error if full
    }
        s->stackElements[i] = e;//assign array [i] to e
        e = (s->top)++;//push to top of stack & increment count
}
//#4 pop function
Element pop(Stack s){
    if(isEmpty(s) == TRUE){
        printf("Stack is empty--Nothing to pop\n");
        exit(1);
    }
    else{
        s->top--;//decrement count
        return s->top;//pop top

    }
}
//#5 check if empty
int isEmpty(Stack s){
    if(s->top == 0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
//#6 check for top element
Element topElement(Stack s){
    if(s->top == 0){
        printf("Stack is empty--No top element\n");
        exit (0);
    }
    else{
        return s->top;
    }
}
