#include <stdio.h>
main()
{
	printf("Hello World!\c");
	// The compiler does not recognize \c as a valid escape sequence But the \c prnted in output with other characters. it literally prints \c as part of the string.
}