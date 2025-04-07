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

    printf("تعداد فاصله‌ها: %d\n", blanks);
    printf("تعداد تب‌ها: %d\n", tabs);
    printf("تعداد خطوط جدید: %d\n", newline);
}
