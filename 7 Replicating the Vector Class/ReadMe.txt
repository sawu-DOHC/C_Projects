The objective of this exercise is to make an integer array that can change size while the program is running.
This is commonly called a "Dynamic array" or "Vector". Normal "static" arrays cannot change in size during runtime,
the number of elements must be specified at compile time. This program makes a "dynamic" array from a standard array
that gets copied any time it reaches capacity. Once it reaches capacity it grows by a fixed amount.
It is meant to replicate the inner workings of the vector class from the C++ standard library.

Overloading the [] allows instances of a class to be used with standard C++ algorithms that require element access
with an index.

>pointer arithmetic
>dynamic memory allocation using "new" operator
>memory de-allocation using destructor
>Custom Operator for direct element access "[]"


Example Output

Adding elements
Added 0
Added 3
Added 6
Added 9
Added 12
Capacity reached
Array resized to 10
Elements copied
Old memory deallocated
Added 15
Added 18
Added 21

Array elements after additions (tested using custom '[]' operator)
Element at index 0: 0
Element at index 1: 3
Element at index 2: 6
Element at index 3: 9
Element at index 4: 12
Element at index 5: 15
Element at index 6: 18
Element at index 7: 21
Current array capacity after additions: 10

Trying to access an out-of-bounds index (index 20):
Element at index 20: Index out of range.
-1

Performing pop_back:
Popped value: 21
Array size after popping: 7

Final array contents: (tested using custom '[]' operator)
Element at index 0: 0
Element at index 1: 3
Element at index 2: 6
Element at index 3: 9
Element at index 4: 12
Element at index 5: 15
Element at index 6: 18
