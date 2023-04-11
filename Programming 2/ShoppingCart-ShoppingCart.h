/*ShoppingCart.h*/

#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include "ItemToPurchase.h"
#include "ItemToPurchase.c"

typedef struct ShoppingCart_struct{
   char customerName [50];
   char currentDate [50];
   ItemToPurchase cartItems [10];
   int cartSize;
}ShoppingCart;

//definitions/prototypes
ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart);//ItemToPurchase.c
ShoppingCart RemoveItem(char name[], ShoppingCart cart);//ItemToPurchase.c
ShoppingCart ModifyItem(char item[50], ShoppingCart cart);//#1
int GetNumItemsInCart(ShoppingCart cart);//#2
int GetCostOfCart(ShoppingCart cart);//#3
void PrintTotal(ShoppingCart cart);//#4
void PrintDescriptions(ShoppingCart cart);//#5

#endif
