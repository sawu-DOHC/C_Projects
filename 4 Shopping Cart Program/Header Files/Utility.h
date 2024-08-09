
#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include "../Header Files/ShoppingCart.h"


void PrintMenu();

void ExecuteMenu(char, ShoppingCart&);


void AddItemToCart(ShoppingCart&);

void RemoveItemFromCart(ShoppingCart&);

void ChangeItemQuantity(ShoppingCart&);

void OutputItemDescriptions(ShoppingCart&);

void OutputShoppingCart(ShoppingCart&);


#endif


