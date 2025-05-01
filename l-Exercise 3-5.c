#include <stdio.h>
#include <string.h>

void reverse(char s[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itob(int n, char s[], int b) {
    int i = 0;
    unsigned int num;
    int sign = n;

    if (b < 2 || b > 16) {
        s[0] = '\0'; 
        return;
    }

    if (n < 0)
        num = -n;
    else
        num = n;

    do {
        int digit = num % b;
        s[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'A';
    } while ((num /= b) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

int main() {
    char size[100];

    itob(255, size, 2);  
    printf("Binary: %s\n", size);

    itob(255, size, 8);
    printf("Octal: %s\n", size);

    itob(255, size, 10);
    printf("Decimal: %s\n", size);

    itob(255, size, 16);
    printf("Hexadecimal: %s\n", size);

    return 0;
}
