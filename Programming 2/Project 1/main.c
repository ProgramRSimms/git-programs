/*main.c*/ //Task #3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dicegame.h"


//Prototypes
int getRandomNumber(int min, int max);
void fillRounds(DiceRound *arr, int size);//DiceRound dynamic array & size of array
int getRoundPoints(DiceRound dice);
void printRoundInfo(DiceRound currentRound);
void printPlayerInfo(int P1, int P2);


//main function
int main (int argc, char *argv []){
    // Initialize the srand() to start the random generator
    srand(time(0));//initialize time for random numbers
    // Initialize the player-1 and player-2 scores to 0
    int P1 = 0;//var name per instructions on output--even rolls to score 
    int P2 = 0;//var name per instructions on output--odd rolls to score
    // Initialize all other required variables
    int i = 0;//for loop
    int n;//user number of rounds
    int curPlayer = getRandomNumber(1, 2);//vars per instructions call get random number for players
    // Ask the user for the number of rounds to run the game
    printf("Please enter the number of rounds to play: ");//prompt  for user input **OUTPUT**
    scanf("%d", &n);//user input number of rounds
    // Dynamically create an array of DiceRound struct objects, based on the user input
    DiceRound* arr;//
    arr = (DiceRound*)malloc(sizeof(DiceRound) * n);

    // Check if array created. If not end program, by calling return 1;
    if (arr == NULL){//if empty return 1
            return 1;
    }
    // Fill the DiceRound array by calling the fillRounds() function
    fillRounds(arr, n);

    // Call printPlayerInfo() function to print the initial player scores which will be 0
    printPlayerInfo(P1, P2);//**OUTPUT** track scores each round

    //LARGE LOOP TO CONTROL MAIN GAME LOGIC
    for(i = 0; i < n; i++){
        // Call getRoundPoints() to get the actual points to be used for this round
        printf("\nROUND %d\n--------\n", i + 1);//round numbers increase from (i = 1 - nRounds value) **OUTPUT**
        printf("Player\t: %d\n", curPlayer); // Print current player **OUTPUT**
        // Call printRoundInfo() to print the round information
        printRoundInfo(arr[i]);//output round number **OUTPUT**

        // MAIN GAME LOGIC
        // Write code here to get the main game logic using branches

        // IF Player-1 (even player) is the current player and the dice rolled is even 
        // OR 
        // IF Player-2 (odd player) is the current player and the dice rolled is odd
        // THEN Current player gains the points, based on the type of the round. 
        //The player's turn continues in the next round.
        // IF Player-1 (even player) is the current player and the dice rolled is odd 
        // OR 
        // IF Player-2 (odd player) is the current player and the dice rolled is even
        // THEN Current player incurs penalty of the same amount of points, based on the type of the round (see above). 
        //In the next round, the current player is changed to the other player.
        if (curPlayer == 1){
            P1 = curPlayer;
            if (arr[i].dice % 2 == 0){//even
                P1 = P1 + getRoundPoints(arr[i]);//accrue point value if even
                curPlayer = P1;//continue turn 
            }
        }
        else{
            P1 = curPlayer;
            P1 = P1 - getRoundPoints(arr[i]);//penalty == same value
            curPlayer = 2;//end of turn
        }
        if (curPlayer == 2){
            P2 = curPlayer;
            if (arr[i].dice % 2 != 0){//odd
                P1 = P1 + getRoundPoints(arr[i]);//accrue point value if odd
                curPlayer = 2;//continue turn 
            }
        }
        else{
            P2 = curPlayer;
            P1 = P1 - getRoundPoints(arr[i]);//penalty == same value
            curPlayer = 1;//end of turn
        }
        // Call printPlayerInfo() to print the player information at the end of the round
        printPlayerInfo(P1, P2);//**OUTPUT** 
        }
        printf("\nGAME OVER!!\n");
        // Compare the final points for player-1 and player-2
        if (P1 > P2){
                // Print the winner as the one with higher points
                printf("P1 Won\n");//**OUTPUT**
        }
        else if (P2 > P1){
                printf("P2 Won\n");//**OUTPUT**
        }
        else{
                printf("Tie Score!!\n");//**OUTPUT**
        }
        // Free the dynamically allocated array memory
        free(arr);//free memory

        return 0;
}                                                                                                                                                 111,0-1       Bot