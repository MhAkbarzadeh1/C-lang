#include <stdio.h>
#include <stdlib.h>  
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("stack empty\n");
        return 0.0;
    }
}

void printTop(void) {
    if (sp > 0)
        printf("Top of stack: %.8g\n", val[sp - 1]);
    else
        printf("Stack is empty\n");
}

void duplicateTop(void) {
    if (sp > 0) {
        double top = val[sp - 1];
        push(top);
    }
    else {
        printf("stack empty, cannot duplicate\n");
    }
}

void swapTopTwo(void) {
    if (sp >= 2) {
        double tmp;
        tmp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = tmp;
    }
    else {
        printf("not enough elements \n");
    }
}

void clearStack(void) {
    sp = 0;
    printf("Stack cleared\n");
}

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp < BUFSIZE)
        buf[bufp++] = c;
    else
        printf("too many characters\n");
}

int getop(char s[]) {
    int i = 0, c, next;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c;

    if (c == '-') {
        next = getch();
        if (!isdigit(next) && next != '.') {
            ungetch(next);
            return c;
        }
        s[++i] = c = next;
    }

    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

int main() {
    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("zero divisor\n");
            break;
        case '%':
            op2 = pop();
            op1 = pop();
            if ((int)op2 != 0)
                push((int)op1 % (int)op2);
            else
                printf("zero mod\n");
            break;
        case '?':   
            printTop();
            break;
        case 'd':   
            duplicateTop();
            break;
        case 's':   
            swapTopTwo();
            break;
        case 'c':   
            clearStack();
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("unknown command %s\n", s);
            break;
        }
    }
    return 0;
}
