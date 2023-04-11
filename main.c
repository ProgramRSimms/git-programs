#include "Stack.h"

#define MAX_LINE_LENGTH 50
#define TRUE 1
#define FALSE 0


int convertToPostfix(char *infixString, char *postfixString);
int evaluatePostfix(char *postfixString);

/*****FUNCTION PROTOTYPES**********/
//Malloc a new StackImp, malloc an array of Elements of size maximumStackSize (store the address in stackElements pointer), set maxSize to be maximumStackSize, initialize count to be 0, and return a pointer to the StackImp.
Stack newStack(int maximumStackSize);

//Free stackElements and then free the Stack s.
void freeStack(Stack s);

//Push a new Element e onto the Stack s, and increment the count variable.  Print an error message if the stack was already full.
void push(Stack s, Element e);

//Pop an element off the stack, decrement the count variable, and return the element's value.
Element pop(Stack s);

//Return true (1) if stack is empty and false (0) otherwise.
int isEmpty(Stack s);

//Return the value of the top element of the stack (without removing it).
Element topElement(Stack s);

//MAIN
int main(){
	FILE *inputFile;
	inputFile = fopen("p1Input.txt", "r");
	if(inputFile == NULL){

		perror("Error opening file");
		return -1;
	}


	//This string will hold the infix equations that are read from inputFile, one at a time.
	char infixString[MAX_LINE_LENGTH];


	//Use fgets to read the next line from the inputFile.
	//Store the line into infixString.
	//The while loop repeats until there are no more lines in the file.
	while(fgets(infixString, MAX_LINE_LENGTH, inputFile)!=NULL){

		//If the line is blank, skip it.
		if(infixString[0] == '\n')
			continue;

		printf("Current infix string: %s",infixString);

		//postfixString is a string to store the equation from szInfixString converted into postfix.
		char postfixString[MAX_LINE_LENGTH];

		//Call the convertToPostfix function (that you are to implement below main).
		int returnMessage = convertToPostfix(infixString,postfixString);


		//convertToPostfix should return an integer letting us know if the infix string was in a valid format.
		//If the format is valid (we returned 0), then we call the evalutaePostfix function (that you are to implement below), and print the result of the evalution.
		//If the format is not valid (we returned something other than 0), then we print the corresponding error message.
		switch(returnMessage)
		{

			case 0: //0 means the infix string had no errors.  Go ahead and evaluate the postfix string.
				printf("Postfix string: %s\n",postfixString);
				int result = evaluatePostfix(postfixString);
				printf("It evaluates to %d.\n",result);
				break;
			case 1:  //1 means the infix string is missing a left parenthesis.
				printf("WARNING: Missing left parenthesis.\n");
				break;
			case 2: //2 means the infix string is missing a right parenthesis.
				printf("WARNING: Missing right parenthesis.\n");
				break;
			case 3: // 3 means missing operator.
				printf("WARNING: Missing operator.\n");
				break;
			case 4: //4 means missing operand.
				printf("WARNING: Missing operand.\n");
				break;
			default:
				printf("WARNING: %d.\n", returnMessage);


		}


		printf("\n\n");
	}

	fclose(inputFile);

	return 0;
}


/*******
int convertToPostfix(char *infixString, char *postfixString)

Input: 
infixString is a character array of length <= MAX_LINE_LENGTH that contains an equation in infix format.
postfixString is a currently empty character array of length <= MAX_LINE_LENGTH that we should fill with a postfix representation of infixString.

Output:
We return an integer based on any errors found in infixString.
If there are no errors, return 0.
If there is a missing (, return 1.
If there is a missing ), return 2.
If there is a missing operator, return 3 (for extra credit).
If there is a missing operand, return 4 (for extra credit).
*********/

/*
1.	Scan X from left to right and repeat Step 3-6 for each element of infix until the Stack is empty.
2.	If an operand is encountered, add it to postfix
	3.	If a ( is encountered, push it onto Stack.
		4.	If an operator is encountered ,then:
			Repeatedly pop from Stack and add to postfix for each operator w/ => precedence than current (top) operator.
			Add operator to Stack.
			[End If #1]
		5. If a ) is encountered , pop:
			Repeatedly pop from Stack and add to Y each operator (on the top of Stack) until a left parenthesis is encountered.
			Remove the left Parenthesis.
			[End If #2]
		[End of If #3]
6. 	END.
*/

int convertToPostfix(char *infixString, char *postfixString){

	//Vars
	int i = 0, j = 0;//for loops
	char scannedChar;
	char top;

	//stack var
	struct Stack s = newStack(MAX_LINE_LENGTH);//use defined parameter

	//define operand
	if (scannedChar >= '0' && scannedChar <= '9'){
		//FIX ME
	}

	

	//FUNCTION LOGIC

	//used in loop
	scannedChar = infixString[i];//iteration of infix char by char

	//scan to end of string using loop
	while (scannedChar != '\0'){
		//if parentheses
		//CONDITION 1
		if (scannedChar == '('){//push to stack
			push(s, scannedChar);
			Element *is;
			is.operation = '(';
			push(s, is);
		}
		else if (scannedChar == ')'){
			Element *is = pop(s);
		}
		//CONDITION 2
		//define operation for union
		if (scannedChar == '^' || scannedChar == '*' || scannedChar == '/' || scannedChar == '+' || scannedChar == '-'){
			//stack empty
			if (isEmpty(s) == TRUE){
				Element *is;
				is.operation = scannedChar;
				push(s, is);
			}
			//stack not empty
			else{
				if (scannedChar == '^'){
					Element *is;
					is = topElement(s);
					if (is.operation == '^'){
						is = pop(s);
						postfixString[j] = is.operation;
						j++;
					}
				}
				if (scannedChar == '*' || scannedChar == '/'){
					Element *is;
					is = topElement(s);
					if (is.operation == '*' || is.operation== '/'){
						is = pop(s);
						postfixString[j] = is.operation;
						j++;
					}
				}
				//pop all if not an opening (
				while (scannedChar != '('){
					if (scannedChar == '+' || scannedChar == '-'){
						Element *is;
						is = topElement(s);
						if (is.operation == '+' || is.operation == '-'){
							is = pop(s);
							postfixString[j] = is.operation;
							j++;
						}
					}
					//else push
					else{
						Element *is;
						is.operation = scannedChar;
						push (s, is);
					}
				}
			}
		}
		//CONDITION 3
		//define operand for union
		while (scannedChar != '\0'){
			if (scannedChar >= '0' || scannedChar <= '9'){//if operator found pop from stack
				Element *is;
				is.operand = scannedChar;
				push(s, is);
			}
			//if opening ( found push
			else if (scannedChar == '('){
				is.operation = scannedChar;
				push (s, is);
			}

			//find closing ) and pop
			else if (scannedChar == ')'){
				top = pop();                  
				while (top != '('){
					postfixString[j] = top;
					j++;
					top = pop();
				}
			}
			//if char is not a valid type
			else{ 
				printf("\nNot a valid infix expression. Re-enter expression.\n");
				getchar();
				exit(1);
			}
			i++;
			scannedChar = infixString[i]; //scan next char of infix 
		}

		//CONDITION 4
		//loop to scan for operand
		while(isEmpty(s) != TRUE){
			is = topElement(s); 
			//now if opening ( encountered == error  
			if (is.operation == '('){
				//free stack before returning an error
				freeStack(s);
				return 2;//
			}
			else if(is.operation == '+' || is.operation == '-' || is.operation == '*' || is.operation == '/' || is.operation == '^'){
				is = pop(s);
				postfixString[j] = pop(is).operation;
				j++;
			}
		}
		postfixString[j] = '\0';//end postfix string with NULL char
		//PREVENT MEMORY LEAKS
		freeStack(s);   

		return 0;
	}//END OF OUTER LOOP FOR FUNCTION
}//END OF FUNCTION




/************
evaluatePostfix(char *postfixString)

Input:
postfixString is a string of length <= MAX_LINE_LENGTH that contains an equation in postfix representation.
If your convertToPostfix() function is correct, this string should be in a valid postfix format.

Output:
Return an integer representing what the postfix equation evaluated to.
************/
int evaluatePostfix(char *postfixString){ 
    //set size parameter
    struct Stack* stack = createStack(strlen(postfixString)); 
    int i;//initialize for loop 
    //error check
    if (!stack){
		return -1;
	} 
    //Scan string
    for (i = 0; postfixString[i]; ++i){ 
        //If operand, push 
        if (isdigit(postfixString[i])){ //incl stdlib.h
            push(stack, postfixString[i] - '0'); 
		}
        //If operator, pop twice
        else{ 
            int op1 = pop(stack); 
            int op2 = pop(stack); 
            switch (postfixString[i]){ 
				case '+': push(stack, op2 + op1); break; 
				case '-': push(stack, op2 - op1); break; 
				case '*': push(stack, op2 * op1); break; 
				case '/': push(stack, op2 / op1); break; 
				//case '(': push(stack); break; 
				//case ')': push(stack); break; 
            } 
        } 
    } 
    return pop(stack); 
} 

/*/Function to define known precedence: ( ) ^ / * + -
int precedence(char symbol){
	if (symbol == '(' || symbol == ')'){
		return (4);
	}
	else if (symbol == '^'){
		return (3);
	}
	else if (symbol == '*' || symbol == '/'){
		return (2);
	}
	else if (symbol == '+' || symbol == '-'){
		return (1);
	}
	else{
		return (0);
	}
}

//Function to define operand
int operand(int op){
	if (op >= '0' && op <= '9'){
		return 1;
	}

//Function to define operator
int operator(char symbol){
	if (symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-'){
		return 1;
	}
	else{
	return 0;
	}
}*/
