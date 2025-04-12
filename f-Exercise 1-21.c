#include <stdio.h>
#define TABSTOP 8

int main(void) {
    int c;
    int pos = 0;        
    int spacec = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            spacec++;
            pos++;
            if (pos % TABSTOP == 0) {
                putchar('\t');
                spacec = 0;
            }
        }
        else {
            while (spacec > 0) {
                putchar(' ');
                spacec--;
            }

            putchar(c);

            if (c == '\n') {
                pos = 0;
            }
            else {
                pos++;
            }
        }
    }

    return 0;
}
