#include "Header Files/Dynamic_Int_Array_Class.h"
#include <iostream>

using namespace std;

int main(){

    Dynamic_Int_Array_Class myArray;

    cout << "Adding elements" << endl;
    for (int i = 0; i < 8; i++) { // Add more elements than the initial capacity to test resizing
        myArray.push_back(i*3);
        cout << "Added " << i*3 << endl;
    }

    cout << endl;

    cout << "Array elements after additions (tested using custom '[]' operator)" << endl;
    for (int i = 0; i < myArray.size(); i++) {
        cout << "Element at index " << i << ": " << myArray[i] << endl;
    }
    cout << "Current array capacity after additions: " << myArray.capacity() << endl << endl;


    cout << "Trying to access an out-of-bounds index (index 20):" << endl;
    cout << "Element at index " << 20 << ": " << myArray.getElementAt(20) << endl;
    cout << endl;


    cout << "Performing pop_back:" << endl;
    int poppedValue = myArray.pop_back();
    cout << "Popped value: " << poppedValue << endl;
    cout << "Array size after popping: " << myArray.size() << endl << endl;


    cout << "Final array contents: (tested using custom '[]' operator)" << endl;
    for (int i = 0; i < myArray.size(); i++) {
        cout << "Element at index " << i << ": " << myArray[i] << endl;
    }

    return 0;
}