#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int getint(int* pn);
int getch(void);
void ungetch(int);

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int main(void)
{
    int array[SIZE];
    int n, status;

    printf("Enter int:\n");

    for (n = 0; n < SIZE && (status = getint(&array[n])) != EOF; n++) {
        if (status == 0) {
            printf("Not a number, stopping input.\n");
            break;
        }
    }

    printf("You entered:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

int getint(int* pn)
{
    int c, sign;

    while (isspace(c = getch())) 
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    int next = c;

    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            ungetch(next);
            return 0;
        }
    }

    *pn = 0;
    do {
        *pn = 10 * *pn + (c - '0');
    } while (isdigit(c = getch()));

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
