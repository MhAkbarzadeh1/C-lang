#include <stdio.h>
#define COL 80
#define MAX_LINE 1000

main(void) {
    char currentWord[MAX_LINE];
    int i;
    for (i = 0; i < MAX_LINE; ++i)
        currentWord[i] = '\0';

    int c, length = 0, pos = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            currentWord[pos] = '\0';

            if (length + pos >= COL) {
                putchar('\n');
                length = 0;
            }

            printf("%s", currentWord);

            putchar(c);

            if (c == '\n') {
                length = 0;
            }
            else if (c == '\t') {
                length += 4; 
            }
            else {
                length += pos + 1;
            }

            pos = 0;
        }
        else {
            currentWord[pos++] = c;

            if (pos >= MAX_LINE - 1) {
                currentWord[pos] = '\0';
                if (length + pos >= COL) {
                    putchar('\n');
                    length = 0;
                }
                printf("%s", currentWord);
                length += pos;
                pos = 0;
            }
        }
    }

    if (pos > 0) {
        currentWord[pos] = '\0';
        if (length + pos >= COL)
            putchar('\n');
        printf("%s", currentWord);
    }

}
