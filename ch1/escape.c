#include <stdio.h>

/* copy input to output, replacing tabs with \t, backspaces with \b, and
 * backslashes with \\ */
int main() {
  int c, escaped;
  while ((c = getchar()) != EOF) {
    escaped = 0;
    if (c == '\t') {
      putchar('\\');
      putchar('t');
      escaped = 1;
    }
    if (c == '\b') {
      putchar('\\');
      putchar('b');
      escaped = 1;
    }
    if (c == '\\') {
      putchar('\\');
      putchar('\\');
      escaped = 1;
    }
    if (!escaped) {
      putchar(c);
    }
  }
  return 0;
}