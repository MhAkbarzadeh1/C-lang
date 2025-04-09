#include <stdio.h>

main() {
    int c,i;
    int wordLength = 0;
    int lengths[20];

    for (i = 0; i < 20; i++) {
        lengths[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (wordLength > 0) {
                if (wordLength < 20)
                    lengths[wordLength]++;
                else
                    lengths[19]++;
                wordLength = 0;
            }
        }
        else {
            wordLength++;
        }
    }

    if (wordLength > 0) {
        if (wordLength < 20)
            lengths[wordLength]++;
        else
            lengths[19]++;
    }

    i = 1;
    while (i < 20) {
        if (lengths[i] > 0) {
            printf("len %2d: ", i);

            int stars = lengths[i];
            while (stars > 0) {
                printf("*");
                stars--;
            }

            printf("\n");
        }
        i++;
    }

}
