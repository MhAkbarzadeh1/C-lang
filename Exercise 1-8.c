#include <stdio.h>

main()
{
    int c;
    int blanks = 0, tabs = 0, newline = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        else if (c == '\t')
            ++tabs;
        else if (c == '\n')
            ++newline;
    }

    printf("blanks: %d\n", blanks);
    printf("tabs: %d\n", tabs);
    printf("newline: %d\n", newline);
}
