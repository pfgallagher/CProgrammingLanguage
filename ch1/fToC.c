#include <stdio.h>

/* #define name replacement text  <- symbolic constant */
#define LOWER 0   /* lower limit of table */
#define UPPER 300 /* upper limt */
#define STEP 20   /* step size */

/* print Fahrenheit-Celsius table
        for fahrenheit = 0, 20, ..., 300; floating-point version */
int main() {
  printf("%3s %6s\n", "f", "c");
  int fahrenheit;
  // for (fahrenheit = LOWER; fahrenheit <= UPPER; fahrenheit = fahrenheit +
  // STEP)
  // {
  // 	printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
  // }
  for (fahrenheit = UPPER; 0 <= fahrenheit; fahrenheit = fahrenheit - STEP) {
    printf("%3d %6.1f\n", fahrenheit, (5.0 / 9.0) * (fahrenheit - 32));
  }
  return 0;
}
