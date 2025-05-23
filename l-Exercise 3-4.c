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

void itoa(int n, char s[]) {
    int i = 0;
    unsigned int num;
    int sign = n;

    if (n < 0)
        num = -n;     
    else
        num = n;

    do {
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

int main() {
    char size[100];

    itoa(1234, size);
    printf("itoa(1234) = %s\n", size);

    itoa(0, size);
    printf("itoa(0) = %s\n", size);

    itoa(-1234, size);
    printf("itoa(-1234) = %s\n", size);


    return 0;
}
