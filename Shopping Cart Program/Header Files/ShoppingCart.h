#ifndef UNTITLED_SHOPPINGCART_H
#define UNTITLED_SHOPPINGCART_H

#include <string>
#include <vector>
#include <sstream>

#include "../Header Files/Item.h"


using namespace std;

class ShoppingCart {

private:

    // Variables
    string customerName;
    string currentDate;
    vector<Item> cartItems;


public:

    // Constructors
    ShoppingCart(const string&, const string&);
    ShoppingCart();

    // Accessors
    string GetCustomerName();
    string GetDate();
    vector<Item> GetCartItems();


    // Mutators
    void AddItem(Item);
    void RemoveItem(const string&);
    void ModifyItem(const string&, const int&);

    int GetNumItemsInCart();
    float GetCostOfCart();
    string StringOfTotal();
    string StringOfDescriptions();



};

#endif //UNTITLED_SHOPPINGCART_H
