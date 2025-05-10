#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

#define MAXLINE 100 
#define MAXOP 100   
#define NUMBER '0'  
#define MAXVAL 100  

int sp = 0;         
double val[MAXVAL]; 
char line[MAXLINE]; 
int linei = 0;   

int getline_custom(char s[], int lim);
int getop(char s[]);
void push(double f);
double pop(void);

int main() {
    int type;
    char s[MAXOP];
    double op2;

    while (getline_custom(line, MAXLINE) > 0) {
        linei = 0;
        while (line[linei] != '\0') {
            type = getop(s);
            if (type == '\0') 
                break;
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
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("unknown command %s\n", s);
                break;
            }
        }
    }
    return 0;
}

int getline_custom(char s[], int lim) {
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

int getop(char s[]) {
    int i, c;

    while ((c = line[linei]) == ' ' || c == '\t')
        linei++;
    if (c == '\0')
        return '\0'; 

    s[0] = c;
    s[1] = '\0';

    if (c == '\n') {
        linei++;
        return c;
    }

    if (c == '+' || c == '-' || c == '*' || c == '/') {
        linei++;
        return c;
    }

    if ((c >= '0' && c <= '9') || c == '.') {
        i = 0;
        while ((c = line[linei]) >= '0' && c <= '9') {
            s[i++] = c;
            linei++;
        }
        if (c == '.') {
            s[i++] = c;
            linei++;
            while ((c = line[linei]) >= '0' && c <= '9') {
                s[i++] = c;
                linei++;
            }
        }
        s[i] = '\0';
        return NUMBER;
    }

    linei++;
    return c; 
}

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
