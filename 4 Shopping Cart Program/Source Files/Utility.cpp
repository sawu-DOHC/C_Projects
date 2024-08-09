
#include "../Header Files/Utility.h"

using namespace std;


void PrintMenu() {
    //newline charachters removed from beginning and end, unit test 10 passed on submission 4
    cout << "MENU" << endl;
    cout << "a - Add item to cart" << endl;
    cout << "d - Remove item from cart" << endl;
    cout << "c - Change item quantity" << endl;
    cout << "i - Output items' descriptions" << endl;
    cout << "o - Output shopping cart" << endl;
    cout << "q - Quit" << endl;

}

void ExecuteMenu(char selection, ShoppingCart& newCart) {

    switch (selection) {

        case 'a':
            AddItemToCart(newCart);
            break;

        case 'd':
            RemoveItemFromCart(newCart);
            break;

        case 'c':
            ChangeItemQuantity(newCart);
            break;

        case 'i':
            OutputItemDescriptions(newCart);
            break;

        case 'o':
            OutputShoppingCart(newCart);
            break;

        case 'q':
            // quit
            break;

        default:
            // invalid option
            break;
    }

}




void AddItemToCart(ShoppingCart& newCart) {

    string tempName;
    string tempDescription;
    float tempPrice;
    int tempQuantity;

    cout << "ADD ITEM TO CART" << endl;

    cout << "Enter the item name: " << endl;
    cin.ignore();
    getline(cin, tempName);

    cout << "Enter the item description: " << endl;
    getline(cin, tempDescription);

    cout << "Enter the item price: " << endl;
    cin >> tempPrice;

    cout << "Enter the item quantity: " << endl;
    cin >> tempQuantity;

    Item newItemToPurchase(tempName, tempDescription, tempPrice, tempQuantity);
    newCart.AddItem(newItemToPurchase);
}

void RemoveItemFromCart(ShoppingCart& newCart) {
    string itemName;

    cout << "REMOVE ITEM FROM CART" << endl;

    cout << "Enter name of item to remove: " << endl;
    cin.ignore();
    getline(cin, itemName);

    newCart.RemoveItem(itemName);
}

void ChangeItemQuantity(ShoppingCart& newCart) {
    cout << "CHANGE ITEM QUANTITY" << endl;

    string itemName;
    int newQty;

    cout << "Enter the item name:" << endl;
    cin.ignore();
    getline(cin, itemName);
    cout << "Enter the new quantity:" << endl;
    cin >> newQty;

    newCart.ModifyItem(itemName, newQty);
}

void OutputItemDescriptions(ShoppingCart& newCart) {
    cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
    cout << newCart.StringOfDescriptions() << endl;
}

void OutputShoppingCart(ShoppingCart& newCart) {
    cout << "OUTPUT SHOPPING CART" << endl;
    cout << newCart.StringOfTotal();
}
