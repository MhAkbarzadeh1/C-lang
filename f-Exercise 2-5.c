#include <stdio.h>
#include <stdlib.h>

int any(char s1[], char s2[]);

int main(void)
{
    char s1[] = "abced";
    char s2[] = "d";
    printf("%d\n", any(s1, s2));

    return 1;
}

int any(char s1[], char s2[])
{
    int i, k;

    for (i = 0; s1[i] != '\0'; i++)
        for (k = 0; s2[k] != '\0'; k++)
            if (s1[i] == s2[k])
                return i;
    return -1;
}
