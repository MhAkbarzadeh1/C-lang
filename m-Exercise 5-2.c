#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];   
int bufp = 0;        

int getch(void) {         
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {        
    if (bufp >= BUFSIZE)
        printf("ungetch: buff\n");
    else
        buf[bufp++] = c;
}

int getfloat(float* pn) {
    int c, sign;
    float power;

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
        if (!isdigit(c) && c != '.') {
            ungetch(c);
            ungetch(next);
            return 0;
        }
    }

    *pn = 0;

    while (isdigit(c)) {
        *pn = 10 * *pn + (c - '0');
        c = getch();
    }

    if (c == '.') {
        c = getch();
        power = 1.0;
        while (isdigit(c)) {
            *pn = 10 * *pn + (c - '0');
            power *= 10;
            c = getch();
        }
        *pn /= power;
    }

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main(void) {
    float val;
    int status;

    printf("Enter a floating-point number: ");

    status = getfloat(&val);

    if (status > 0)
        printf("Parsed number: %f\n", val);
    else if (status == 0)
        printf("Input was not a valid number.\n");
    else
        printf("End of file or error.\n");

    return 0;
}
