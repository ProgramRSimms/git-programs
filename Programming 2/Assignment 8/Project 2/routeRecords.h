//route-records.h

#ifndef ROUTERECORDS_H
#define ROUTERECORDS_H

//STRUCT
typedef struct RouteRecord{
    char origin[4], destination[4], airline[3];
    int countArr [6];//array of passenger count /*There are six months’ worth of data for each route. (Index 0 will represent January’s passenger count, Index 1 will represent February’s passenger count, etc.).*/
}RouteRecord;

//ENUM
typedef enum SearchType{ 
    ROUTE, 
    ORIGIN, 
    DESTINATION, 
    AIRLINE,
    QUIT 
    //added for consistency 
}SearchType;

                    //PROTOTYPES
//function #1
RouteRecord* createRecords(FILE *fileIn); 
//function #2
int fillRecords(RouteRecord *r, FILE *fileIn);
//function #3
int findAirlineRoute(RouteRecord *r, int length, const char *origin, const char *destination, const char *airline);
//function #4
void searchRecords(RouteRecord *r, int length, const char *key1, const char *key2, SearchType st);
//function #5
void printRecords(RouteRecord *r, int length); 
//function #6
void printMenu();
//function #7 additional 
int getLength(FILE *fileIn);

#endif