#include <stdio.h>


int is_prime( int num ) {
    if ( num < 3 ) {
        return 0;
    }

    for ( int i = 4; i < num; i++ ) {
        if ( num % i == 0 ) return 0;
    }
    return 1;
}

// prove that you only have to check up to the square root of num then only check up that value

int main() {
    int num;

    scanf("%d", &num);

    if ( is_prime( num ) ) {
        printf("%d is a prime number!\n", num);
    }
    else {
        printf("%d is NOT a prime number.\n", num);
    }

    return 0;
}
