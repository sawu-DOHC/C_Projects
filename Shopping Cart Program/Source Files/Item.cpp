#include <string>
#include <sstream>

#include "../Header Files/Item.h"


// constructors

Item::Item() {
    itemName = "none";
    itemDescription = "none";
    itemPrice = 0.00;
    itemQuantity = 0;
}

Item::Item(const string& newItemName, const string& newItemDescription, const float& newItemPrice, const int& newItemQuantity) {
    itemName = newItemName;
    itemDescription = newItemDescription;
    itemPrice = newItemPrice;
    itemQuantity = newItemQuantity;
}


// acessors

string Item::GetName() {
    return itemName;
}

string Item::GetDescription() {
    return itemDescription;
}

float Item::GetPrice() {
    return itemPrice;
}

int Item::GetQuantity() {
    return itemQuantity;
}



// mutators

void Item::SetName(const string& newName) {
    itemName = newName;
}

void Item::SetDescription(const string& newDescription) {
    itemDescription = newDescription;
}

void Item::SetPrice(float newPrice) {
    itemPrice = newPrice;
}

void Item::SetQuantity(int newQuantity) {
    itemQuantity = newQuantity;
}


// other functions

string Item::StringOfItemCost() {

    ostringstream outputStringStream;


    outputStringStream << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemPrice * itemQuantity;

    return outputStringStream.str();

}

string Item::StringOfItemDescription() {

    ostringstream outputStringStream;

    outputStringStream << itemName << ": " << itemDescription;

    return outputStringStream.str();
}