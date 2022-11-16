#include <stdio.h>

/* print a histogram of the frequencies of different chars from input */
int main() {
  int c, i, j;
  int charFreq[26];

  for (i = 0; i < 26; ++i) charFreq[i] = 0;

  while ((c = getchar()) != EOF) {
    if ('a' <= c && c <= 'z') {
      ++charFreq[c - 'a'];
    }
  }
  for (i = 0; i < 26; ++i) {
    printf("%c: ", i + 97);
    for (j = 0; j < charFreq[i]; ++j) {
      putchar('*');
    }
    putchar('\n');
  }

  return 0;
}