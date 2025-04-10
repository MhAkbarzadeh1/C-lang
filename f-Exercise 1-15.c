#include <stdio.h>

int tmp(int fahr);

int main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;  
    upper = 300; 
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = tmp(fahr);
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}

int tmp(int fahr)
{
    return (5.0 * (fahr - 32) / 9);
}
