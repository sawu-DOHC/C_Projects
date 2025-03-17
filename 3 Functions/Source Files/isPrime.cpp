// "brute force" method
bool isPrime ( int number ){
    bool isPrime = true;

    if (number <= 2){ // exclude 1 and 2
        isPrime = false;
        return isPrime;
    }

    int limit = number -1; // exclude the number itself

    for ( int i = 2; i <= limit; i++){
        if ( number % i == 0){
            isPrime = false;
            break; // exit the function since we only need to find one instance of 0 remainder division
        }
    }

    return isPrime;
}