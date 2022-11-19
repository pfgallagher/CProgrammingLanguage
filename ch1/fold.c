#include <stdio.h>

#define MAXLINE 80   /* maximum line size */
#define MAXWORD 1000 /* maximum word size */

char word[MAXWORD]; /* current word */
int len;            /* current word length */

int getWord(void);

int main() {
  int curLineLength = 0;
  while (0 < (len = getWord())) {
    if (curLineLength == 0) {
      curLineLength = len;
      printf("%s", word);
    } else if ((curLineLength + 1 + len) <= MAXLINE) {
      curLineLength += (1 + len);
      printf(" %s", word);
    } else {
      putchar('\n');
      curLineLength = len;
      printf("%s", word);
    }
    if (word[len - 1] == '\n') {
      curLineLength = 0;
    }
  }
  return 0;
}

int getWord() {
  int c, i;
  for (i = 0;
       i < MAXWORD - 1 && (c = getchar()) != EOF && c != ' ' && c != '\n';
       i++) {
    word[i] = c;
  }
  if (c == '\n') {
    word[i] = c;
    i++;
  }
  word[i] = '\0';
  return i;
}
