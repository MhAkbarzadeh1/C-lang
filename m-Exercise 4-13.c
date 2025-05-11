#include <stdio.h>
#include <string.h>

void reverse_r(char s[], int left, int right) {
    if (left >= right)
        return;

    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    reverse_r(s, left + 1, right - 1);
}

void reverse(char s[]) {
    reverse_r(s, 0, strlen(s) - 1);
}

int main() {
    char str[] = "hello world";
    reverse(str);
    printf("%s\n", str);  
}
