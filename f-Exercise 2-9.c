#include <stdio.h>

// It runs once per 1-bit, not per bit — faster.

int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x &= (x - 1))
        b++;
    return b;
}
