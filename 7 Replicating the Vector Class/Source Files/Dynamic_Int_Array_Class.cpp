#include "../Header Files/Dynamic_Int_Array_Class.h"


void Dynamic_Int_Array_Class::outOfMemoryErrorMessage() {
    cout << "Cannot allocate memory." << endl;

}
void Dynamic_Int_Array_Class::indexOutOfRangeErrorMessage() {
    cout << "Index out of range." << endl;
}


//constructors
Dynamic_Int_Array_Class::Dynamic_Int_Array_Class() { // no args constnructor

    this->arrayCapacity = 5;
    this->numberOfElements = 0;

    // declare a pointer
    int* newDynamicArrayPtr;

    // allocate a block of memory with "new" operator and assigns it to the pointer
    newDynamicArrayPtr = new int[ arrayCapacity ];

    // assign the newly allocated array to the class member pointer
    this->dynamicArrayPtr = newDynamicArrayPtr;

}
Dynamic_Int_Array_Class::Dynamic_Int_Array_Class( int newCapacity ) { // capacity argument

    if (newCapacity < 0) {
        outOfMemoryErrorMessage();
    }

    this->arrayCapacity = newCapacity;
    this->numberOfElements = 0;

    int* newDynamicArrayPtr;
    newDynamicArrayPtr = new int[ arrayCapacity ];
    this->dynamicArrayPtr = newDynamicArrayPtr;
}


Dynamic_Int_Array_Class::Dynamic_Int_Array_Class ( const Dynamic_Int_Array_Class &old_Array ) { //used for resizing

    this->arrayCapacity = old_Array.capacity();
    this->numberOfElements = old_Array.size();

    int* newDynamicArrayPtr;
    newDynamicArrayPtr = new int[ arrayCapacity ];
    this->dynamicArrayPtr = newDynamicArrayPtr;

    for (int i = 0; i < numberOfElements; i++) {
        this->dynamicArrayPtr[i] = old_Array.dynamicArrayPtr[i];
    }

}


Dynamic_Int_Array_Class:: ~Dynamic_Int_Array_Class() {
    delete[] dynamicArrayPtr;
}

//accessors
int Dynamic_Int_Array_Class::size() const {
    return numberOfElements;
}
int Dynamic_Int_Array_Class::capacity() const {
    return arrayCapacity;
}
int Dynamic_Int_Array_Class::getElementAt( int index ) {

    if ( index < 0 || index >= numberOfElements ) {
        indexOutOfRangeErrorMessage();
        return -1;
    }
    // explicit pointer arithmetic
    int value = *(dynamicArrayPtr + index);


    return value;

}

//mutators

void Dynamic_Int_Array_Class::push_back( int val ) {

    // resize if necessary
    if (numberOfElements == arrayCapacity) {
        cout << "Capacity reached " << endl;
        int newCapacity = arrayCapacity + 5;
        cout << "Array resized to " << newCapacity << endl;
        int* newArray = new int[newCapacity];


        // copy elements with boundary checking
        cout << "Elements copied " << endl;
        for (int i = 0; i < numberOfElements && i < newCapacity; i++) {
            newArray[i] = dynamicArrayPtr[i];
        }

        cout << "Old memory deallocated" << endl;
        delete[] dynamicArrayPtr;

        dynamicArrayPtr = newArray;
        arrayCapacity = newCapacity;
    }

    // adding a boundary check to avoid buffer overload
    if (numberOfElements < arrayCapacity) {
        dynamicArrayPtr[numberOfElements] = val;
        numberOfElements++;
    }

}


int Dynamic_Int_Array_Class::pop_back() {

    // this action doesnt free the memory occupied by the last element.
    // because the array is still maintainins its capacity and
    // you can continue to use it for future element insertion

    if ( numberOfElements == 0 ) {
        indexOutOfRangeErrorMessage();
        return 0;
    }
    numberOfElements--;
    return dynamicArrayPtr[numberOfElements];
}

// Overloaded [] operator declaration
int& Dynamic_Int_Array_Class:: operator [] ( const int& index ) {

    return dynamicArrayPtr[index];
}
