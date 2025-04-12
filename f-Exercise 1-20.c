#include <stdio.h>

#define TABSTOP 8  

main(void) {
    int c;
    int pos = 0; 

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int space = TABSTOP - (pos % TABSTOP); 
            for (int i = 0; i < space; i++) {
                putchar('s'); // 's' means space
                pos++;
            }
        }
        else if (c == '\n') {
            putchar(c);
            pos = 0; 
        }
        else {
            putchar(c);
            pos++;
        }
    }

}
