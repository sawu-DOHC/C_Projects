//
// Created by Sam on 7/22/2024.
//

#ifndef UNTITLED_ITEM_H
#define UNTITLED_ITEM_H

#include <string>

using namespace std;

class Item {

private:
    // Variables and objects
    string itemName;
    string itemDescription;
    float itemPrice;
    int itemQuantity;

public:
    // Constructors
    Item();
    Item(const string&, const string& , const float& , const int& );

    // Accessors
    string GetName();
    string GetDescription();
    float GetPrice();
    int GetQuantity();


    // Mutators
    void SetName(const string& );
    void SetDescription(const string& );
    void SetPrice(float);
    void SetQuantity(int);

    // Other functions
    string StringOfItemCost();
    string StringOfItemDescription();



};

#endif //UNTITLED_ITEM_H
