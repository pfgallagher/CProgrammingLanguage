#include <stdio.h>

/* print Fahrenheit-Celsius table
        for fahr = 0, 20, ..., 300 */
int main() {
  int fahrenheit, celsius;
  int lower, upper, step;

  lower = 0;   /* lower limit of temperature table */
  upper = 300; /* upper limit */
  step = 20;   /* step size */

  fahrenheit = lower;
  while (fahrenheit <= upper) {
    celsius = 5 * (fahrenheit - 32) / 9;
    printf("%d\t%d\n", fahrenheit, celsius);
    fahrenheit = fahrenheit + step;
  }
  return 0;
}
