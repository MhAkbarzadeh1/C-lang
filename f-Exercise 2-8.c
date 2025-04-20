#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(void) {
    unsigned x = 240;  
    int n = 4;      
    printf("Result: %u\n", rightrot(x, n)); 
    return 0;
}

unsigned rightrot(unsigned x, int n) {
    int word_size = sizeof(x) * 8;  
    n = n % word_size;  
    return (x >> n) | (x << (word_size - n)); 
}
