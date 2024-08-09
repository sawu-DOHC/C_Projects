#ifndef CREATING_A_VECTOR_CLASS_DYNAMIC_INT_ARRAY_CLASS_H
#define CREATING_A_VECTOR_CLASS_DYNAMIC_INT_ARRAY_CLASS_H

#include <iostream>

using namespace std;

class Dynamic_Int_Array_Class{

private:
    int* dynamicArrayPtr;   // To point to the allocated array
    int numberOfElements;   // Number of elements in the array
    int arrayCapacity;      // capacity of the dynamic array

    void outOfMemoryErrorMessage();
    void indexOutOfRangeErrorMessage();

public:

    //constructors
    Dynamic_Int_Array_Class();
    Dynamic_Int_Array_Class( int newCapacity );
    Dynamic_Int_Array_Class( const Dynamic_Int_Array_Class &old_Vector );
    ~Dynamic_Int_Array_Class();

    //accessors
    int size() const;
    int capacity() const;
    int getElementAt( int index );

    //mutators
    void push_back(int);
    int pop_back();

    //Overloaded operators
    int& operator [] ( const int& );

};

#endif //CREATING_A_VECTOR_CLASS_DYNAMIC_INT_ARRAY_CLASS_H
