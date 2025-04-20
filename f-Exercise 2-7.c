#include <stdio.h>
#include <stdlib.h>

unsigned invert(unsigned x, int p, int n);

int main(void)
{
    printf("%u\n", invert(240, 4, 3));  
    return 1;
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned mask;
    mask = (~(~0U << n)) << (p - n + 1);  
    return mask ^ x; 
}
