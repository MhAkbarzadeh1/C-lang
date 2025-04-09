#include <stdio.h>
#define cha 128

main(void) {
    int c, i;
    int _char[cha];

    char stars[] = "********************************************************************************************************************************";

    for (i = 0; i < cha; ++i) {
        _char[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < cha)
            _char[c]++;
    }

    for (i = 0; i < cha; ++i) {
        if (_char[i] > 0) {
            printf("%c: %.*s\n", i, _char[i], stars);
        }
    }

}
