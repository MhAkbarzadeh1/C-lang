#include <stdio.h>

#define MAX_LINE 1000

int getline(char line[], int limit);
int rmv(char line[]);

int main(void) {
    int len;
    char line[MAX_LINE];

    while ((len = getline(line, MAX_LINE)) > 0) {
        len = rmv(line);
        if (len > 0)
            fwrite(line, sizeof(char), len, stdout); 
    }

    return 0;
}

int getline(char line[], int limit) {
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i++] = c;
    }

    line[i] = '\0';
    return i;
}

int rmv(char line[]) {
    int i = 0;

    while (line[i] != '\0' && line[i] != '\n')
        ++i;

    int end = i - 1;

    while (end >= 0 && (line[end] == ' ' || line[end] == '\t'))
        --end;

    if (end < 0) {
        line[0] = '\0';
        return 0;
    }

    line[++end] = '\n';
    line[++end] = '\0';

    return end;
}
