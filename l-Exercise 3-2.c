#include <stdio.h>
#define MAXLINE 1000

void escape(char s[], char t[]) {
    int i = 0, j = 0;

    while (t[i] != '\0') {
        switch (t[i]) {
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        default:
            s[j++] = t[i];
            break;
        }
        i++;
    }
    s[j] = '\0';
}

void unescape(char s[], int lim) {
    int i = 0, c;

    while (i < lim - 1 && (c = getchar()) != EOF) {
        if (c == '\\') {  
            c = getchar();
            if (c == 'n')
                s[i++] = '\n';
            else if (c == 't')
                s[i++] = '\t';
            else {
                s[i++] = '\\';
                if (i < lim - 1)
                    s[i++] = c;
            }
        }
        else {
            s[i++] = c;
        }
    }
    s[i] = '\0';
}

int main(void) {
    char s[MAXLINE], t[MAXLINE];

    unescape(t, MAXLINE); 

    escape(s, t);       

    printf("%s", s);

    return 0;
}
