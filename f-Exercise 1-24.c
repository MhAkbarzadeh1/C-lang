#include <stdio.h>

int brace = 0, brack = 0, paren = 0; 

void v() {
    int c, d;
    c = getchar();  
    d = getchar();  

    while (c != '*' || d != '/') {
        c = d;  
        d = getchar();  
    }
}

void inquote(int c) {
    int d;
    putchar(c); 

    while ((d = getchar()) != c) {
        if (d == '\\') {
            getchar(); 
        }
        putchar(d); 
    }

    putchar(c); 
}

void search(int c) {
    if (c == '{') brace++; 
    else if (c == '}') brace--; 
    else if (c == '[') brack++;  
    else if (c == ']') brack--;  
    else if (c == '(') paren++;  
    else if (c == ')') paren--; 
}

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '/') {  
            if ((c = getchar()) == '*') {
                v(); 
            }
            else {
                search(c); 
            }
        }
        else if (c == '\'' || c == '"') {
            inquote(c); 
        }
        else {
            search(c); 
        }
    }

    if (brace > 0) printf("Wrong braces\n");
    if (brack > 0) printf("Wrong brackets\n");
    if (paren > 0) printf("Wrong parentheses\n");

    return 0;
}
