#include <stdio.h>

void squeeze_alt(char s1[], char s2[]) {
    int i, j, k;
    int d;

    for (i = j = 0; s1[i] != '\0'; i++) {
        d = 0;
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                d = 1;
                break;
            }
        }
        if (!d) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int main() {
    char s1[] = "hello world";
    char s2[] = "ole";

    squeeze_alt(s1, s2);
    printf("Result: %s\n", s1);

    return 0;
}
