/*dicegame.c*/ //Task #2

#include <stdio.h>
#include <stdlib.h>
#include "dicegame.h"

#define MAX_ROLL 6

/*
NOTE: Generating random numbers within a specified range:
In order to produce random integer numbers within a specified range, you need to manipulate the rand( ) function. 
The formula is:
int number = a + rand( ) % n;

a = the first number in your range
n = the number of terms in your range
(range computed by  largest value - smallest value + 1)
example: for(int i = 1; i <=10; i++)     // looping to print 10 numbers
    printf("%d", 10 + rand( ) % 46);   // formula for numbers 
     }
*/
//RANDOM NUM BTWN MIN/MAX FUNCTION
int getRandomNumber(int min, int max){
         return  rand() %  (max - min + 1) + min;//min + rand() / (RAND_MAX / (max - min + 1) + 1); 
}
//ROUNDS FUNCTION
void fillRounds(DiceRound *arr, int size){//DiceRound dynamic array & size of array
        int i = 0;
        for (i = 1; i <= size; i++){
                //dice roll
                arr[i].dice = getRandomNumber(1, 6);//random number between 1-6.To assign these values use the getRandomNumber() function. 
                //points
                arr[i].points = 10 * getRandomNumber(10, 100);//random number from 10-100 in multiples of 10. (10 * random number between 1-10).
                //round type
                int randomNumber = getRandomNumber(0, 100);//call function to get values from 1 - 100 for round type probability
                if (randomNumber <= 60){
                        arr[i].type = REGULAR;//60%
                }
                else if (randomNumber >= 80){
                        arr[i].type = BONUS;//20%
                }
                else {
                        arr[i].type = DOUBLE;//%20
                }
        }
}
/*
o       Type – the type of the round. There are 3 types of rounds:
       BONUS – if the player dice roll is successful, the player gains 100 points. 
    If unsuccessful, 100 points are deducted from the player’s score.
       DOUBLE – if the player dice roll is successful, the player gains twice the points. 
    If unsuccessful, those points are deducted from the player’s score.
       REGULAR – if the player dice roll is successful, the player gains the points value decided above. 
    If unsuccessful, those points are deducted from the player’s score.
       Probability of the round types:
•       20% for BONUS, 
    20% for DOUBLE 
    60% for REGULAR
*/
//COMPUTE ROUND POINTS FUNCTION
int getRoundPoints(DiceRound roundPoints){
        int i = 0;
        srand(0);
        for (i = 0; i < MAX_ROLL; i++){//preprocessor value
                //printf(" %d ", 1 + rand() % 6);// 
        }
        if (roundPoints.type == BONUS){
                return 100;//gains 100 points
        }
        else if (roundPoints.type == DOUBLE){
                return (2 * roundPoints.points);//gains twice the points.
        }
    else{
                return roundPoints.points;//gains points value random number from 10-100 by 10s
        }
}
//PRINT ROUND INFO FUNCTION
void printRoundInfo(DiceRound currentRound){
        printf("Type    : ");//**OUTPUT**
        if (currentRound.type == BONUS){
                printf("BONUS\n");//**OUTPUT**
        }
        else if (currentRound.type == DOUBLE){
                printf("DOUBLE\n");//**OUTPUT**
        }
        else{
                printf("REGULAR\n");//**OUTPUT**
        }
        printf("\n");//newline after conditions**OUTPUT**
        printf("Dice    : %d\n", currentRound.dice);//**OUTPUT**
        printf("Points  : %d\n", currentRound.points);//**OUTPUT***
}
/*
        For each round, one of the following cases can occur:
    o   Player-1 (even player) is the current player and the dice rolled is even 
                                        OR 
        Player-2 (odd player) is the current player and the dice rolled is odd
       Current player gains the points, based on the type of the round (see above). 
        The player’s turn continues in the next round.
    o   Player-1 (even player) is the current player and the dice rolled is odd 
                                        OR 
        Player-2 (odd player) is the current player and the dice rolled is even
       Current player incurs penalty of the same amount of points, based on the type of the round (see above). 
        In the next round, the current player is changed to the other player.
*/
void printPlayerInfo(int P1, int P2){
        //output player points
        printf("P1      : %d\n", P1);
        printf("P2      : %d\n", P2);
}
/*//Prototypes as reminder for vars
int getRandomNumber(int min, int max);
void fillRounds(DiceRound *arr, int size);//DiceRound dynamic array & size of array
int getRoundPoints(DiceRound dice);
void printRoundInfo(DiceRound currentRound);
void printPlayerInfo(int P1, int P2);*/