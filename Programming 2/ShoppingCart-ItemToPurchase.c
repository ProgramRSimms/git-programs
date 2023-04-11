/*ItemToPurchase.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include "ShoppingCart.c"

/*Instructions:
(1) Extend the ItemToPurchase struct to contain a new data member. (2 pt)
char itemDescription[ ] - set to "none" in MakeItemBlank()
Implement the following related functions for the ItemToPurchase struct:
PrintItemDescription() Has an ItemToPurchase parameter.*/

void MakeItemBlank(ItemToPurchase *item){
   strcpy((*item).itemName, "none");
   (*item).itemPrice = 0;
   (*item).itemQuantity = 0;
   strcpy((*item).itemDescription, "none");
}

void PrintItemCost(ItemToPurchase item){
   printf("%s %d @ $%d = $%d\n", item.itemName, item.itemQuantity, item.itemPrice,(item.itemPrice *item.itemQuantity));
}

void PrintItemDescription(ItemToPurchase item){
   printf("%s: %s.\n", item.itemName, item.itemDescription);
}
