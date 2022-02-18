#include <stdio.h>

#define LOWER 0	  /* lower limit of table */
#define UPPER 300 /* upper limt */
#define STEP 20	  /* step size */

/* print Celsius-Fahrenheit table
        for celsius = 0, 20, ..., 300; floating-point version */
int main()
{
	printf("%3s %6s\n", "c", "f");
	int celsius;
	// for (celsius = LOWER; celsius <= UPPER; celsius = celsius + STEP)
	// {
	// 	printf("%3d %6.1f\n", celsius, (celsius * (9.0 / 5.0)) + 32);
	// }
	for (celsius = UPPER; 0 <= celsius; celsius = celsius - STEP)
	{
		printf("%3d %6.1f\n", celsius, (celsius * (9.0 / 5.0)) + 32);
	}
	return 0;
}
