#include <string>

int main() {

// CHARACTER
    char var1 = 'A';               // 1 byte

// BOOLEAN
    bool var2 = true;              // 1 byte

// INTEGER TYPES
    short var3 = 1;                // 2 bytes  Range   [                (-3.2768 × 10^4) to (3.2767 × 10^4)                ]
    int var4 = 1;                  // 4 bytes  Range   [           (-2.147483648 × 10^9) to (2.147483647 × 10^9)           ]
    long var5 = 1;                 // 4 bytes  Range   [           (-2.147483648 × 10^9) to (2.147483647 × 10^9)           ]
                                   // 8 bytes  Range   [ (-9.223372036854775808 × 10^18) to (9.223372036854775807 × 10^18) ]
    long long var6 = 1;            // 8 bytes  Range   [ (-9.223372036854775808 × 10^18) to (9.223372036854775807 × 10^18) ]


    unsigned int var7 = 1;         // 4 bytes  Range   [ (0) to (4.294967295 × 10^9)            ]
    unsigned long var8 = 1;        // 4 bytes  Range   [ (0) to (4.294967295 × 10^9)            ]
                                   // 8 bytes  Range   [ (0) to (1.8446744073709551615 × 10^19) ]
    unsigned long long var9 = 1;   // 8 bytes  Range   [ (0) to (1.8446744073709551615 × 10^19) ]

// FLOATING POINT NUMBERS
    float var10 = 1;               // 4 bytes  Range   [ (1.2 × 10^-38)     to (3.4 × 10^38)    ]
    double var11 = 1;              // 8 bytes  Range   [ (2.3 × 10^-308)    to (1.7 × 10^308)   ]
    long double var12 = 1;         // 8 bytes  Range   [ (3.4 × 10^-4932)   to (1.1 × 10^4932)  ]
                                   // 12 bytes Range   [ (3.4 × 10^-4932)   to (1.1 × 10^4932)  ]
                                   // 16 bytes Range   [ (3.4 × 10^-4932)   to (1.1 × 10^4932)  ]

// POINTER TYPES
    int* var13 = &var4;            // 4 to 8 bytes
    int* var14 = nullptr;          // 4 to 8 bytes


// STRING TYPES
    std::string var15 = "Hello";   // Size depends on the string length and implementation
    const char* var16 = "Hello";   // Size depends on the string length and implementation

    return 0;
}
