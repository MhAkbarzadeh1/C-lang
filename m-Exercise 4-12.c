#include <stdio.h>

void itoa_r(int n, char s[], int* index) {
    if (n < 0) {
        s[(*index)++] = '-';
        n = -n;
    }

    if (n / 10)
        itoa_r(n / 10, s, index);

    s[(*index)++] = n % 10 + '0';
}

void itoa(int n, char s[]) {
    int index = 0;
    itoa_r(n, s, &index);
    s[index] = '\0';  
}

int main() {
    char str[100];
    itoa(-12345, str);
    printf("%s\n", str);  
    return 0;
}
