#include <stdio.h>

/* count blanks, tabs, and newlines */
int main() {
  int c, nws;
  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\t' || c == '\n') ++nws;
  printf("%d\n", nws);
  return 0;
}