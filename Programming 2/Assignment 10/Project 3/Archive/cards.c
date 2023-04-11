/*Task 2 - cards.c
Write the following functions which are typical linked list functions adapted for the game play:
#1	Card* createCard() - This function dynamically allocates a new Card struct object and 
returns a pointer to that struct object which will later be used to insert into a linked list. 
There are three types of cards ATTACK, DEFEND, and RUN. ATTACK and DEFEND cards also have a value. 
You will assign a card type based on these random chances:
•	40% - ATTACK: the value is a random number between 1 and 5 inclusive. 
•	50% - DEFEND: the value is a random number between 3 and 8 inclusive. 
•	10% - RUN: the value is a random number between 1 and 8 inclusive. The value of a RUN card is 
only used for sorting purposes.
#2	Card* removeCard( Card *head ) - This function removes and deallocates the first node in the 
linked list that head is pointing at. It returns the new head of the linked list.
#3	Card* addCard( Card *head, Card *c ) - This function adds a new Card struct object to the 
linked list that head is pointing at. It is assumed that a new Card struct object is being passed 
into this function as parameter c. This function will add the new node in descending order of its 
value regardless of the action. 
#4	int getLength( Card *head ) - This function returns the length of the linked list that head is 
pointing at.
#5	void printCard( Card *head ) - This function prints a single card with abbreviations: A for ATTACK, 
D for DEFEND, and R for RUN and their corresponding values. Example: A5 means an ATTACK worth 5 points.
#6	void printCards( Card *head ) - This function traverses the linked list that head is pointing at. 
It will call printCard(). It should print out from front to back. Example: R6 D5 D4 A4 D3
#7	Card* buildCards( int n ) - This function builds a stack of cards using a linked list. The parameter n 
determines how many cards are created. It will use createCard() and addCard(). It returns the head of the new 
linked list.
#8	Card* destroyCards( Card *head ) - This function is the destructor for a linked list that head is pointing 
at. It should return NULL.
Prototypes: 
#1 Card *createCard()
#2 Card *removeCard(Card *head); 
#3 Card *addCard(Card *head, Card *c); 
#4 int getLength(Card *head);
#5 void printCard(Card *head);
#6 void printCards(Card *head); 
#7 Card *buildCards(int n);
#8 Card *destroyCards(Card *head);*/

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include "cards.h"

//Functions

//#1
Card *createCard(){
    Card *ptr; 
    ptr = (Card*)malloc(sizeof(Card));
    //random 1 to 100
    int lower = 1; 
    int upper = 100; 
    int percentage = (rand() % (upper - lower + 1)) + lower;
    int num;
    
    //1 to 40 = attack
    if(percentage<=40){
        lower = 1; //lower
        upper = 5; //upper
        ptr->cardType = ATTACK;
    }
    //41 to 90 = defend
    else if(percentage<=90){
        lower = 3; //lower
        upper = 8; //upper
        ptr->cardType = DEFEND;   
    }
    //else = run
    else{
        lower = 1; // lower
        upper = 8; // upper
        ptr->cardType = RUN;   // make type RUN
    }
    //random card val
    num = (rand() % (upper - lower + 1)) + lower;
    ptr->next = NULL;
    ptr->value = num;
    // return pointer
    return ptr;
}
//#2
Card *removeCard(Card *head){
    //base case
    Card *delete;
    
    if (head == NULL){
        return NULL;
    }

    delete = head;
    head = head->next;
    free(delete);
    return head;
}
//#3
Card *addCard(Card *head, Card *c){
    Card* current;
    if (head == NULL || head->value <= c->value){
        c->next = head;
        head = c;
    }
    else{
        current = head;
        while (current->next != NULL && current->value > c->value){
            current = current->next;
        }
        c->next = current->next;
        current->next = c;
    }
    return head;
}
//#4
int getLength(Card *head){
    int count = 0;//counter
    Card *current = head;
    while (current != NULL){  
        count++;  
        current = current->next;  
    }  
    return count;  
}  
//#5
void printCard(Card *head){
    if(head == NULL){
        return;
    }
    if(head->cardType == ATTACK){
        printf("A");
    }
    else if(head->cardType == DEFEND){
        printf("D");
    }
    if(head->cardType == RUN){
        printf("R");
    }
    printf("%d ", head->value);
}
//#6
void printCards(Card *head){
    Card *current = head;
    while(current != NULL){
       printCard(current);//Call printCard
       current = current->next;
    }
}
//#7
Card *buildCards(int n){
    Card *head = NULL;
    while(n--){
       Card *card = createCard();
       head = addCard(head,card);
    }
   return head;
}
//#8
Card *destroyCards(Card *head){
    while (head != NULL){
        head = removeCard(head);        
    }
    return NULL;
}