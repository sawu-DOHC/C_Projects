// "brute force" method
//bool isPrime ( int number ){
//    bool isPrime = true;
//
//    if (number <= 3){ // exclude 1 and 2
//        isPrime = false;
//        return isPrime;
//    }
//
//    int limit = number -1; // exclude the number itself
//
//    for ( int i = 4; i <= limit; i++){
//        if ( number % i == 0){
//            isPrime = false;
//            break; // exit the function since we only need to find one instance of 0 remainder division
//        }
//    }
//
//    return isPrime;
//}
#include <cmath>
// optimized version to reduce the number of checks
// limit the range to the square root of the number being tested,
// because if n is divisible by any number greater than its square root,
// the corresponding factor must be smaller than the square root.

// assume the number is NOT prime
// if the number is not prime, it must have at least one factor smaller than or equal to the square root of n.
// this is because if n = a * b, then at least one of a or b must be <= sqrt(n).
// n = a * b
// if both a and b > sqrt(n), then a * b > n, which is a contradiction.
// thus, at least ONE factor (a or b) must be <= sqrt(n).
// this means once you check up to the square root you will have found 2 factors,
// factor pairs become reversed when you start checking past the square root
bool isPrime ( int number ){
    bool isPrime = true;

    if (number <= 2){
        isPrime = false;
        return isPrime;
    }

    int limit = sqrt(number);

    for ( int i = 3; i <= limit; i++){
        if ( number % i == 0 ){
            isPrime = false;
            break;
        }
    }

return true;


}