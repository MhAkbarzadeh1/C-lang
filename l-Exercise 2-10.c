#include <stdio.h>

int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}

 main() {
    char test1 = 'A';
    char test2 = 'Z';

    printf("%c -> %c\n", test1, lower(test1));
    printf("%c -> %c\n", test2, lower(test2));

}
