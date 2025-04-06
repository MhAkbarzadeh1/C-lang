#include <stdio.h>

int main() {
    int c;

    while (c = getchar() != EOF) {
        printf("res= of (getchar() != EOF): %d\n", c);
    }

    printf("res of (getchar() != EOF): %d\n", c);

}
/* #include <stdio.h>
main()
{
  int c;
  c = getchar() != EOF;
    printf("res= %d", c);
}
*/
