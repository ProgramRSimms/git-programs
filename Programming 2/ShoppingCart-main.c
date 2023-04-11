/*main.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ShoppingCart.h"
#include "ItemToPurchase.c"
#include "ItemToPurchase.h"

/*related functions
AddItem(ItemsToPurchase, ShoppingCart) returns ShoppingCart object
RemoveItem(char[](item name), ShoppingCart) returns ShoppingCart object **if cant be found output message"Item not found in cart. Nothing removed."
ModifyItem(char[](item name), ShoppingCart) returns ShoppingCart object 
GetNumItemsInCart(ShoppingCart) returns quantity in cart
GetCostOfCart(ShoppingCart) returns total cost
PrintTotal(ShoppingCart)**Outputs total cost **if empty outputs "SHOPPING CART IS EMPTY"
PrintDescriptions(ShoppingCart)**Outputs each item description
*/
//menu function moved to above main function
char PrintMenu(ShoppingCart cart){

   //user selection 
   char selection = ' ';
   //gets(&selection);
   
   /*Instructions:
   (4) Implement the PrintMenu() function. PrintMenu() has a ShoppingCart parameter, 
   and outputs a menu of options to manipulate the shopping cart. 
   Each option is represented by a single character. 
   Build and output the menu within the function.
   If the an invalid character is entered, continue to prompt for a valid choice. 
   Hint: Implement Quit before implementing other options. Call PrintMenu() 
   in the main() function. Continue to execute the menu until the user enters q to Quit. (3 pts) */
   
   //Menu options
   printf("MENU\n");
   printf("a - Add item to cart\n");
   printf("r - Remove item from cart\n");
   printf("c - Change item quantity\n");
   printf("i - Output items' descriptions\n");
   printf("o - Output shopping cart\n");
   printf("q - Quit\n\n");
   
   //prompt for selection
   printf("Choose an option:\n");
   gets(&selection);
   
   //prompt again if invalid selection
   while (selection != 'a' && selection != 'r' && selection != 'c' && selection != 'i' && selection != 'o' 
                           && selection != 'q'){
      printf("Choose an option:\n");
      gets(&selection);
   }
   
   //quit if q selected
   if(selection == q) break;//Quit has no output just simply quits
      
   //if q not selected continue...   
   while(selection != 'q'){
      
      if (selection == 'a'){
         ItemToPurchase item;
   
         printf("ADD ITEM TO CART\n");//**Output
         printf("Enter the item name:\n");//**Output
         gets(item.itemName);
         printf("Enter the item description:\n");//**Output
         gets(item.itemDescription);
         printf("Enter the item price:\n");//**Output
         scanf("%d", &item.itemPrice);
         printf("Enter the item quantity:\n");//**Output
         scanf("%d", &item.itemQuantity);
         
         AddItem(item.itemName, ShoppingCart cart);
         
         printf("\n");//New line
         
         selection = ' '
         }
      else if (selection == 'r') {
         printf("REMOVE ITEM FROM CART\n");//**Output
         printf("Enter name of item to remove:");//**Output
         fgets(name, cart.cartSize, stdin);
   
        RemoveItem(item.itemName, ShoppingCart cart);
        selection = ' ';
      }
      else if (selection == 'c'){
         printf("CHANGE ITEM QUANTITY\n");
         printf("Enter the item name:");
         fgets(name, cart.cartSize, stdin);
   
         int i = 0;//initialize before loop
         while (strcmp(name, cart.cartItems[i].itemName) != 0){
            ++i;
         }
         ModifyItem(cart.cartItems[i], cart);
         selection = ' ';
      }
      else if (selection == 'i'){
         printf("OUTPUT ITEM'S DESCRIPTIONS\n");//**Output
         PrintDescriptions(cart);
         selection = ' ';
      }
      else if (selection == 'o'){
         printf("OUTPUT SHOPPING CART\n");//**Output
         PrintTotal(cart);
         selection = ' ';
      }
      return selection;
   }
}
   
int main(int argc, char* argv[]){

   //variables
   char name[50];
   char date[10];
   //ShoppingCart cart;
   
   /*Instructions:
   (3) In main(), prompt the user for a customer's name and today's date. 
   Output the name and date. Create an object of type ShoppingCart. (1 pt) 
   Enter Customer's Name:
      John Doe
      Enter Today's Date:
      February 1, 2016
      
      Customer Name: John Doe
      Today's Date: February 1, 2016*/
      
   //user name
   printf("Enter Customer's Name:\n");//**Output
   fgets(name, cart.cartSize, stdin);
   name[strlen(name) - 1] = '\0';
   
   // user date
   printf("Enter Today's Date:\n");//**Output
   fgets(date, 10, stdin);
   date[strlen(date) - 1] = '\0';
   
   //output name and date
   printf("Customer Name: %s\n", cart.customerName);//**Output
   printf("Today's Date: %s\n", cart.currentDate);//**Output
   
   //ShoppingCart()
   strcpy(cart.customerName, name);
   strcpy(cart.currentDate, date);
   cart.cartSize = 0;//initialize
   
   while(selection != 'q'){
      selection = PrintMenu(cart);
   }
   /*Instructions:
   (5) Implement the "Output shopping cart" menu option. (3 pts) */

   //Output name/date
   printf("%s's Shopping Cart - %s\n", cart.customerName, cart.currentDate);//**Output
   
   /*Instructions:
   (6) Implement the "Output item's description" menu option. (2 pts) */
   
   //Output description
   printf("Item Descriptions\n");//**Output
   for (int i = 0; i < cart.cartSize; i++){
      printf("%s: %s\n", cart.cartItems[i].itemName, cart.cartItems[i].itemDescription);//**Output
   }
   return 0;
}