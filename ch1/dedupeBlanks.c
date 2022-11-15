#include <stdio.h>

/* copy input to output, replacing each string of one or more blanks with a
 * single blank */
int main() {
  int c, last;
  while ((c = getchar()) != EOF) {
    if (c != ' ' || last != ' ') putchar(c);
    last = c;
  }
  return 0;
}