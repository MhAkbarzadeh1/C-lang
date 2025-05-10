#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];  
int bufp = 0;       

int getch(void);
void ungetch(int c);
void ungets(char s[]);

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[])
{
    int len = strlen(s);
    for (int i = len - 1; i >= 0; i--) {
        ungetch(s[i]);
    }
}

int main(void) {
    char s[] = "Hello, world!";

    printf("Pushing the strin..\n");
    ungets(s);  

    printf("Characters from buffer:\n");
    int c;
    while ((c = getch()) != EOF) {
        putchar(c);  
    }

    return 0;
}
