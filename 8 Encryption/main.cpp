#include <stdio.h>


int is_prime( int num ) {
    if ( num < 2 ) {
        return 0;
    }

    for ( int i = 2; i < num; i++ ) {  // Try dividing by all numbers before num
        if ( num % i == 0 ) return 0;  // Found a divisor, not prime
    }
    return 1;  // No divisors found, it's prime
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if ( is_prime( num ) ) {
        printf("%d is a prime number!\n", num);
    } else {
        printf("%d is NOT a prime number.\n", num);
    }

    return 0;
}
