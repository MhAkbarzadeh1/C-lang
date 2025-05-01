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

void itoa(int n, char s[], int w) {
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

    int len = strlen(s);
    if (len < w) {
        for (int j = len; j >= 0; j--)
            s[j + (w - len)] = s[j];

        for (int j = 0; j < w - len; j++)
            s[j] = ' ';
    }
}

int main() {
    char size[100];

    itoa(123, size, 6);
    printf("'%s'\n", size);

    itoa(-45, size, 5);
    printf("'%s'\n", size);

    return 0;
}
