#include <string>
#include <sstream>
#include <vector>
#include <iostream>

#include "../Header Files/ShoppingCart.h"
#include <iomanip>

using namespace std;

// constructors
ShoppingCart::ShoppingCart(const string& newName, const string& newDate) {
    //experimental constructor
    newName.empty() ? customerName = "none" : customerName = newName;
    newDate.empty() ? currentDate = "January 1, 1998" : currentDate = newDate;

    cout << "Customer name: " << customerName << endl;
    cout << "Today's date: " << currentDate << endl;
}

ShoppingCart::ShoppingCart() {
    customerName = "none";
    currentDate = "January 1, 1998";
}

//ShoppingCart::ShoppingCart(const string& newName , const string& newDate ) {
//this->customerName = newName;
//this->currentDate = newDate;
//}

// accessors 
string ShoppingCart::GetCustomerName() { return customerName; }
string ShoppingCart::GetDate() { return currentDate; }
vector<Item> ShoppingCart::GetCartItems() { return cartItems; }

// mutators
void ShoppingCart::AddItem(Item newItemToPurchase) {
    cartItems.push_back(newItemToPurchase);
}

void ShoppingCart::RemoveItem(const string& itemName) {

    for (size_t i = 0; i < cartItems.size(); i++) {

        if (cartItems[i].GetName() == itemName) {

            cartItems.erase(cartItems.begin() + i);
            //cout << "Item '" << itemName << "' removed from cart." << endl;
            return; // Exit the function after removing the item
        }
    }
    cout << "Item not found in cart. Nothing removed." << endl;
}

void ShoppingCart::ModifyItem(const string& itemName, const int& newQty) {
    bool found = false;

    for (size_t i = 0; i < cartItems.size(); i++) {
        if (cartItems.at(i).GetName() == itemName) {
            cartItems.at(i).SetQuantity(newQty);
            found = true;
        }
    }
    if (found != true) {
        cout << "Item not found in cart. Nothing modified." << endl;
    }

}
int ShoppingCart::GetNumItemsInCart() {
    int total = 0;
    for (size_t i = 0; i < cartItems.size(); i++) {
        total = total + cartItems[i].GetQuantity();

    }
    return total;

}

float ShoppingCart::GetCostOfCart() {
    float total = 0.00;
    for (size_t i = 0; i < cartItems.size(); i++) {
        total = total + (cartItems[i].GetPrice() * cartItems[i].GetQuantity());

    }
    return total;

}

string ShoppingCart::StringOfTotal() {
    ostringstream outputStringStream;

    outputStringStream << customerName << "'s Shopping Cart - " << currentDate << endl;

    if (cartItems.empty()) {
        outputStringStream << "Number of Items: " << GetNumItemsInCart() << endl;

        outputStringStream << "\nSHOPPING CART IS EMPTY" << endl;

        outputStringStream << "\nTotal: $" << fixed << setprecision(2) << GetCostOfCart() << endl;
    }
    else {
        outputStringStream << "Number of Items: " << GetNumItemsInCart() << endl << endl;

        for (size_t i = 0; i < cartItems.size(); ++i) {
            outputStringStream << cartItems[i].GetName() << " " << cartItems[i].GetQuantity() << " @ $" << fixed << setprecision(2) << cartItems[i].GetPrice() << " = $" << fixed << setprecision(2) << cartItems[i].GetQuantity() * cartItems[i].GetPrice() << endl;
        }

        outputStringStream << endl << "Total: $" << fixed << setprecision(2) << GetCostOfCart() << endl;
    }

    return outputStringStream.str();
}



string ShoppingCart::StringOfDescriptions() {

    ostringstream outputStringStream;

    outputStringStream << customerName << "'s Shopping Cart - " << currentDate << endl << endl;

    outputStringStream << "Item Descriptions" << endl;

    for (size_t i = 0; i < cartItems.size(); i++) {

        outputStringStream << cartItems[i].StringOfItemDescription() << endl;
    }

    return outputStringStream.str();
}