/*shoppingCart.c*/

#include <stdio.h>
#include <stdlib.h>
#include "ShoppingCart.h"
#include "ItemToPurchase.c"
#include "ItemToPurchase.h"

//#1 Modify Cart Function
/*ShoppingCart ModifyItem(char item[50], ShoppingCart cart){
   
   int quantity;
   char itemFound = 'n';//no
   //Prompt
   printf("Enter the new quantity:");//**Output
   scanf("%d", &quantity);
   //
   int i = 0;
   for (i = 0; i < 50; i++){
      if (strcmp(item, cart.cartItems[i].itemName) == 0){
         itemFound = 'y';//yes
         cart.cartItems[i].itemQuantity = quantity;
      }
   }
   
   if (itemFound == 'n'){
      printf("Item not found in cart. Nothing modified.\n");//**Output 
   }
   return cart;
}*/

//#2 quantity
int GetNumItemsInCart(ShoppingCart cart){
   return cart.cartSize;
}
//#3 Cost
int GetCostOfCart(ShoppingCart cart){
   int cost = 0;
   int tempVal = 0;
   int i;
   for (i = 0; i < cart.cartSize; i++) {
      tempVal = (cart.cartItems[i].itemQuantity * cart.cartItems[i].itemPrice);
      cost = cost + tempVal;
   }
   return total;
}

//#4 Print Total Cost function
void PrintTotal(ShoppingCart cart){
   int total = 0;
   int numOfItems = 0;
   int i;
   for (i = 0; i < cart.cartSize; i++) {
      numOfItems = numOfItems + cart.cartItems[i].itemQuantity;
   }
   printf("%s\'s Shopping Cart - %s\n", cart.customerName, cart.currentDate);//**Output
   printf("Number of Items: %d\n\n", numOfItems);//**Output
   if (cart.cartSize == 0){
      printf("SHOPPING CART IS EMPTY\n");//**Output
      printf("Total: $0\n");
   } 
   else{
        int i;
        for (i = 0; i < cart.cartSize; i++){
            printf("%s %d @ $%d = $%d\n", cart.cartItems[i].itemName, cart.cartItems[i].itemQuantity,
                cart.cartItems[i].itemPrice, ((cart.cartItems[i].itemQuantity) * (cart.cartItems[i].itemPrice)));
        total = total + ((cart.cartItems[i].itemQuantity) * (cart.cartItems[i].itemPrice));
        }
        printf("\nTotal: $%d\n\n", total);
   }
}

//#5 Print descriptions function
void PrintDescriptions(ShoppingCart cart){
    int i;
    printf("%s's Shopping Cart - %s\n\n", cart.customerName, cart.currentDate);//**Output
    printf("Item Descriptions\n");
    for (i = 0; i < cart.cartSize; i++){
     //PrintItemDescription(cart.cartItems[i]);
        printf("%s: %s\n", cart.cartItems[i].itemName, cart.cartItems[i].itemDescription);
   }
}

