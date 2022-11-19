#include <stdio.h>

#define IN 1  /* inside a comment */
#define OUT 0 /* outside a comment */

/* print c source file without block comments */
int main() {
  int c, state;
  state = OUT;
  while ((c = getchar()) != EOF)
    if (c == '/' || c == '*') {
      int next = getchar();
      if (c == '/' && next == '*')
        state = IN;
      else if (c == '*' && next == '/')
        state = OUT;
      else {
        putchar(c);
        putchar(next);
      }
    } else if (state == OUT)
      putchar(c);
  return 0;
}