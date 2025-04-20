#include <stdio.h>
#include <ctype.h>

int main() {
    // here, im put some examples input 
    printf("%d\n", htoi("0x1A3F")); 
    printf("%d\n", htoi("7b"));     
    printf("%d\n", htoi("0XFF"));   
    return 0;
}

int htoi(char s[]) {
    int i = 0;
    int n = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;

    for (; s[i] != '\0'; ++i) {
        if (isdigit(s[i])) {
            n = 16 * n + (s[i] - '0');
        }
        else if (s[i] >= 'a' && s[i] <= 'f') {
            n = 16 * n + (s[i] - 'a' + 10);
        }
        else if (s[i] >= 'A' && s[i] <= 'F') {
            n = 16 * n + (s[i] - 'A' + 10);
        }
        else {
            break;
        }
    }

    return n;
}
