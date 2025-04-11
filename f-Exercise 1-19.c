#include <stdio.h>
#define MAXLINE 1000  

int getline(char line[], int maxline) {
    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

void reverse(char s[]) {
    int i, j;
    char temp;

    for (i = 0; s[i] != '\0'; ++i)
        ;

    if (s[i - 1] == '\n')
        i--;

    j = 0;
    i--; 

    while (j < i) {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        j++;
        i--;
    }
}

int main() {
    char line[MAXLINE];

    while (getline(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}
