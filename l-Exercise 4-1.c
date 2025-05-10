#include <stdio.h>
#include <string.h>

int strindex(char s[], char t[]) {
    int i, j;
    int lens = strlen(s);
    int lent = strlen(t);

    if (lent == 0 || lens < lent)
        return -1;

    for (i = lens - lent; i >= 0; i--) {
        for (j = 0; j < lent && s[i + j] == t[j]; j++)
            ;
        if (j == lent)
            return i;  
    }

    return -1;
}

int main(void) {
    char line[] = "abcdedfgjijkabc";
    char pattern[] = "abc";

    int found = strindex(line, pattern);
    printf("right index: %d\n", found);
}
