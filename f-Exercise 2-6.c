#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned mask = ~(~0 << n) << (p + 1 - n);  
    x &= ~mask;  

    y &= ~(~0 << n); 
    y <<= (p + 1 - n);  

    return x | y; 
}

int main() {
    unsigned x = 0b11111111000000001111111100000000;  
    unsigned y = 0b101010101010; 

    unsigned result = setbits(x, 16, 4, y);  
    printf("Result: %u\n", result); 
    return 0;
}
