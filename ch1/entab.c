#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define TABSIZE 2    /* number of spaces to replace with tabs */

char line[MAXLINE]; /* current input line */
int len;            /* current line length */

int getLine(void);
int tabIsNeeded(int offset);
void entab(void);

/* replace consecutive spaces in input with tabs */
int main() {
  while (0 < (len = getLine())) {
    entab();
  }
  return 0;
}

int getLine() {
  int c, i;
  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

int tabIsNeeded(int offset) {
  int needed = 1;
  for (int i = offset; i < (offset + TABSIZE); i++)
    if (line[i] != ' ') needed = 0;
  return needed;
}

void entab() {
  for (int i = 0; i < len; i++)
    if (line[i] == ' ') {
      if (tabIsNeeded(i)) {
        putchar('\t');
        i += (TABSIZE - 1);
      } else {
        putchar(line[i]);
      }
    } else {
      putchar(line[i]);
    }
}