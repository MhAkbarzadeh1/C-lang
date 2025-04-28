#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]) {
    int i, j;
    int c;

    i = j = 0;
    while ((c = s1[i++]) != '\0') {
        if (s1[i] == '-' && s1[i + 1] != '\0' &&
            ((isalnum(c) && isalnum(s1[i + 1])) && (c <= s1[i + 1]))) {
            i++; 
            while (c <= s1[i]) {
                s2[j++] = c++;
            }
        }
        else {
            s2[j++] = c;
        }
    }
    s2[j] = '\0'; 
}


int main() {
    char s1[] = "a-d0-3A-C";
    char s2[100];

    expand(s1, s2);

    printf("in: %s\n", s1);
    printf("out: %s\n", s2);

    return 0;
}
