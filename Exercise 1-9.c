#include <stdio.h>

main()
{
    int c;
    int space = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (space == 0) {
                putchar(c);
                space = 1;
            }
        }
        else {
            putchar(c);
            space = 0;
        }
    }
}
