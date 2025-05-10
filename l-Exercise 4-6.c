#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

#define MAXOP   100 
#define NUMBER  '0'  
#define FUNCTION 'f'  
#define VAR     'v'   

int getop(char[]);
void push(double);
double pop(void);
void clearStack(void);

double variables[26]; 
double lastPrintedValue = 0.0;  

int main(void)
{
    int type;
    double op2;
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
                printf("zero devisor\n");
            break;
        case '\n':
            lastPrintedValue = pop();  
            printf("\t%.8g\n", lastPrintedValue);
            break;

        case FUNCTION:
            if (strcmp(s, "sin") == 0)
                push(sin(pop()));
            else if (strcmp(s, "exp") == 0)
                push(exp(pop()));
            else if (strcmp(s, "pow") == 0) {
                op2 = pop();
                push(pow(pop(), op2));
            }
            else
                printf("unknown function %s\n", s);
            break;

        case VAR:
            if (strlen(s) == 1) {
                if (s[0] == '=') {
                    variables[s[1] - 'a'] = pop();
                }
                else {
                    printf("Variable %c = %.8g\n", s[0], variables[s[0] - 'a']);
                    push(variables[s[0] - 'a']);
                }
            }
            else {
                printf("invalid variable command\n");
            }
            break;

        default:
            printf("unknown command %s\n", s);
            break;
        }
    }
    return EXIT_SUCCESS;
}


#define MAXVAL  100  

int sp = 0;         
double val[MAXVAL];  

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;   
    i = 0;
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

#define BUFSIZE 100

char buf[BUFSIZE]; 
int  bufp = 0;     

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

void clearStack(void)
{
    sp = 0;
}
