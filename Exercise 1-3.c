#include <stdio.h>
/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300 */
main()
{
	int fahr, celsius;
	int lower, upper, step;
	lower = 0; /* lower limit of temperature scale */
	upper = 300; /* upper limit */
	step = 20; /* step size */
	fahr = lower;
	printf("%3s\t%6s\n", "fahr", "celsius");
	printf("---------------\n");
	while (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9;
		printf("%3d\t%6d\n", fahr, celsius);
		fahr = fahr + step;
	}
}
