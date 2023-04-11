#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cards.h"

int main(int argc, char *argv[]){
    //current time = 0 = seed
    srand(time(0));
    //argument conditions/checks
    if (argc < 2){
        printf("Command line argument does not exist.\n");
        exit (0);
    }
    int numCards = atoi(argv[1]);
    if (numCards <= 0){
        printf("Invalid argument");
        exit(0);
    }
    Card *player1 = buildCards(numCards);
    Card *player2 = buildCards(numCards);

    //output data
    printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n");
    printf("Start size: %d cards\n", numCards);//**OUTPUT**
    printf("Player 1 starting cards: ");
    printCards(player1);
    printf("\n");
    printf("Player 2 starting cards: ");
    printCards(player2);
    printf("\n");
    int roundCount = 1;
    Card *newCard;
        while ((getLength(player1) != 0) && (getLength(player2) != 0)){
            if (player1->cardType == ATTACK){
                if (player2->cardType == ATTACK){
                    if(player1->value > player2->value){
                        newCard = createCard();
                        //Remember to do remove this current card before applying the reward/punishment for each of the above cases. 
                        //i.e. the current card should be discarded first before removing the next card as penalty or adding a new card as reward.
                        player1 = removeCard(player1);

                        if (getLength(player1) != 0){
                                player1 = addCard(player1, newCard);
                        }
                        player2 = removeCard(player2);//removing current card
                        player2 = removeCard(player2);//after next card becomes head remove the next card
                        printf("Player1 wins. Player 1 gets a new card.");
                        printf("Player2 loses their next card into the abyss\n");//FIX ME
                        /* printCards(player1);//OUTPUT TEST
                        printf("\n");
                        printCards(player2);//OUTPUT TEST
                        printf("\n");*/
                    }
                    else if (player2->value > player1->value){
                        player2 = removeCard(player2);
                        newCard = createCard();
                        if (getLength(player2) != 0){
                                player2 = addCard(player2, newCard);
                        }
                        player1 = removeCard(player1);//removing current card
                        player1 = removeCard(player1);//after next card becomes head remove the next card
                        printf("Player 2 wins. Player 2 gets a new card.");//FIX ME
                        /* printCards(player1);//OUTPUT TEST
                        printf("\n");
                        printCards(player2);//OUTPUT TEST
                        printf("\n");*/
                    }
                    else{
                        /* printCards(player1);//OUTPUT TEST
                        printf("\n");
                        printCards(player2);//OUTPUT TEST
                        printf("\n");*/
                        player1 = removeCard(player1);//removing current card
                        player2 = removeCard(player2);
                        //tie nothing happens **OUTPUT***//FIX ME
                    }
                            /*If both players ATTACK, the player with the higher value wins. The winning player gets a new card, 
                            which will be added to their card list in the descending order of the card value. The losing player will 
                                        lose their next card into the abyss. In a tie, nothing happens. */
                }
                else if (player2->cardType == DEFEND){
                    /*If one player ATTACKs and the other player DEFENDs, the player with the higher value wins. If the ATTACKing player wins, 
                    they get a new card added to their card list in the descending order of the card value and nothing happens to the DEFENDing player. 
                    If the DEFENDing player wins or ties, then the ATTACKing player loses */
                    if (player1->value > player2->value){
                        player1 = removeCard(player1);
                        newCard = createCard();
                        if (getLength(player1) != 0){
                                player1 = addCard(player1, newCard);
                        }
                        player2 = removeCard(player2);
                        /* printCards(player1);//OUTPUT TEST
                        printf("\n");
                        printCards(player2);//OUTPUT TEST
                        printf("\n");*/
                    }
                    else{
                        player1 = removeCard(player1);
                        player1 = removeCard(player1);
                        player2 = removeCard(player2);
                        /*printCards(player1);//OUTPUT TEST
                        printf("\n");
                        printCards(player2);//OUTPUT TEST
                        printf("\n");*/
                        // printf("");//FIX ME
                    }
                }
                else if (player2->cardType == RUN){
                    /*If one player ATTACKs and the other player RUNs, the RUNning player loses their next card into the abyss.*/

                    player1 = removeCard(player1);
                    player2 = removeCard(player2);
                    player2 = removeCard(player2);
                    /* printCards(player1);//OUTPUT TEST
                    printf("\n");
                    printCards(player2);//OUTPUT TEST
                    printf("\n");*/
                }

            }
            else if (player1->cardType == DEFEND){
                if (player2->cardType == DEFEND){
                    player1 = removeCard(player1);
                    player2 = removeCard(player2);
                    // printf("Nothing happens.");//FIX ME 
                    /* printCards(player1);//OUTPUT TEST
                    printf("\n");
                    printCards(player2);//OUTPUT TEST
                    printf("\n");*/
                }
                else if (player2->cardType == ATTACK){
                    if (player1->value > player2->value){
                        player1 = removeCard(player1);
                        newCard = createCard();
                        if (getLength(player1) != 0){
                                player1 = addCard(player1, newCard);
                        }

                        player2 = removeCard(player2);
                    }
                    else{
                        player1 = removeCard(player1);
                        player1 = removeCard(player1);
                        player2 = removeCard(player2);
                        // printf("");//FIX ME
                    }
                }
                else if (player2->cardType == RUN){
                    player1 = removeCard(player1);
                    newCard = createCard();
                    if (getLength(player1) != 0){
                        player1 = addCard(player1, newCard);
                    }
                    player2 = removeCard(player2);
                    player2 = removeCard(player2);
                    /* printCards(player1);//OUTPUT TEST
                    printf("\n");
                    printCards(player2);//OUTPUT TEST
                    printf("\n");*/
                    //**OUTPUT*** FIX ME
                }

        }
        else if (player1->cardType == RUN){
            if (player2->cardType == RUN){
                player1 = removeCard(player1);
                player1 = removeCard(player1);
                player2 = removeCard(player2);
                player2 = removeCard(player2);
                    /* printCards(player1);//OUTPUT TEST
                    printf("\n");
                    printCards(player2);//OUTPUT TEST
                    printf("\n");*/
                //**OUTPUT*** FIX ME
            }
            else if (player2->cardType == ATTACK){
                    player2 = removeCard(player2);
                    player1 = removeCard(player1);
                    player1 = removeCard(player1);
                    /* printCards(player1);//OUTPUT TEST
                    printf("\n");
                    pOUND %d -----", roundCount\n);
        
                    printf("\n");*/
            }

            else if (player2->cardType == DEFEND){
                    player2 = removeCard(player2);
                        newCard = createCard();
                    if (getLength(player2) != 0){
                                        player2 = addCard(player2, newCard);
                                }
                    player1 = removeCard(player1);
                    player1 = removeCard(player1);
                    /* printCards(player1);//OUTPUT TEST
                    printf("\n");
                    printCards(player2);//OUTPUT TEST
                    printf("\n");*/
            }     
            //FIX ME call destroy function and exit(0)
            printf("----- ROUND %d -----\n", roundCount);
            roundCount++;
            printf("Player 1("); 
            getLength(player1)
            printf("): ");
            printCard(player1);
            printf("\n");
            printf("Player 2(");        
            getLength(player2)
            printf("): ");              
            printCard(player2);   
            printf("\n");
        }
        if (getLength(player1) == 0){
                printf("P1 deck empty\n");
        }
        if (getLength(player2) == 0){
                printf("P2 deck empty\n");
        }
        return 0;
    }   