#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

#ifndef CARDS_H
#define CARDS_H

//enumerator
typedef enum CardType {
    ATTACK,
    DEFEND,
    RUN
}CardType;
//structure
typedef struct Card{
    CardType cardType;
    Card *next;//additional
    int value;
}Card;

// Prototypes 
Card *createCard();
Card *removeCard(Card *head); 
Card *addCard(Card *head, Card *c); 
int getLength(Card *head);
void printCard(Card *head);
void printCards(Card *head); 
Card *buildCards(int n);
Card *destroyCards(Card *head);

#endif