/*Header file*/ //task #1

#ifndef DICEGAME_H
#define DICEGAME_H

//enum for ROUNDTYPE - Enumeration is a user defined data type in C 
//mainly used to assign names to integral constants
typedef enum ROUNDTYPE{
        BONUS,
        DOUBLE,
        REGULAR
}ROUNDTYPE;


//struct for DiceRound
typedef struct DiceRound{
        //Structure members cannot be initialized with declaration. = compile error
        int dice;//member #1
        int points;//member #2
        ROUNDTYPE type;//member #3
}DiceRound;

//Prototypes
int getRandomNumber(int min, int max);
void fillRounds(DiceRound *arr, int size);//DiceRound dynamic array & size of array
int getRoundPoints(DiceRound dice);
void printRoundInfo(DiceRound currentRound);
void printPlayerInfo(int P1, int P2);

#endif