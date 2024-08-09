#include <iostream>
#include <string>

#include "Header Files/ShoppingCart.h"
#include "Header Files/Utility.h"

using namespace std;

int main() {

    string newName;
    string newDate;

    cout << "Enter customer's name:";
    getline(cin, newName);

    cout << "Enter today's date: ";
    getline(cin, newDate);

    //declaring shopping cart object
    ShoppingCart newCart(newName, newDate);

    char selection;
    bool cont = true;

    while (cont == true) {

        PrintMenu();

        cout << "Choose an option:" << endl;
        cin >> selection;
        cout << endl;


        //validating the selection the fancy way
        string validOptions = "qoicda";
        while ( validOptions.find(selection ) == string::npos ) {
            cout << "Choose an option:" << endl;
            cin >> selection;
        }
        //exiting loop if q is entered
        if (selection == 'q') {
            cont = false;
            break;
        }

        ExecuteMenu(selection, newCart);

    }

    return 0;

}