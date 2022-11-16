#include <stdio.h>

/* count digits, whitespace, and others */
int main() {
  int c, i, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;
  for (i = 0; i < 10; ++i) ndigit[i] = 0;

  while ((c = getchar()) != EOF)
    if ('0' <= c && c <= '9')
      ++ndigit[c - '0'];
    else if (c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;
  printf("digits =");
  for (i = 0; i < 10; ++i) printf(" %d", ndigit[i]);
  printf(", white space = %d, other = %d\n", nwhite, nother);
  return 0;
}