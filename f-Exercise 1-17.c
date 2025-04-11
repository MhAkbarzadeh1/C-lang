#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;            
    int max = 0;        
    int blen;
    char line[MAXLINE];     
    char longest[MAXLINE];  

    while ((len = getline(line, MAXLINE)) > 0) {
        blen = len;

        if (line[len - 1] != '\n') {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ++blen;
            ++blen; 
        }

        if (blen > max) {
            max = blen;
            copy(longest, line); 
        }
    }

    if (max > 80) {
        printf("max: %d\n", max);
        printf("longest:\n%s", MAXLINE, longest);
    }
    else {
        printf("it has to be over 80 char ");
    }

    return 0;
}

int getline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0'; 
    return i;  
}

void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')  
        ++i;
}
