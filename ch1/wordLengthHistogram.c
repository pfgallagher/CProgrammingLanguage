#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* print a histogram of the word length from input */
int main() {
  int c, state, count, i, j;
  int lengthCount[10];

  for (i = 0; i < 10; ++i) lengthCount[i] = 0;
  state = OUT;

  while ((c = getchar()) != EOF) {
    if ((c == ' ' || c == '\n' || c == '\t') && state == IN) {
      state = OUT;
      ++lengthCount[count - 1];
      count = 0;
    } else {
      ++count;
      state = IN;
    }
  }
  for (i = 1; i <= 10; ++i) {
    printf("%2d: ", i);
    for (j = 0; j < lengthCount[i - 1]; ++j) {
      putchar('*');
    }
    putchar('\n');
  }
  return 0;
}