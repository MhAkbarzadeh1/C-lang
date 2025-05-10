#include <stdio.h>
#include <stdlib.h>

#define EOF -1

int buf = EOF; 
int getch(void);
void ungetch(int c);

int getch(void)
{
    int temp = buf;
    buf = EOF;  
    return (temp != EOF) ? temp : getchar(); 
 }

void ungetch(int c)
{
    if (buf != EOF)
        printf("too many characters\n");  
    else if (c == EOF)
        buf = EOF; 
    else
        buf = c;  
}

int main(void) {
    int c;

    printf("Enter a character: ");
    c = getch();
    printf("You entered: %c\n", c);

    printf("Pushing back the character '%c'.\n", c);
    ungetch(c);  

    printf("Reading character : ");
    c = getch();  
    printf("You entered: %c\n", c);

    printf("Pushing back EOF.\n");
    ungetch(EOF);  
    c = getch();  
    if (c == EOF)
        printf("EOF reached\n");
    else
        printf("You entered: %c\n", c);

    return 0;
}
