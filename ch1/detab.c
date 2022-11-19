#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */
#define TABSIZE 2    /* number of spaces to replace tabs with */

char line[MAXLINE]; /* current input line */
int len;            /* current line length */

int getLine(void);
void detab(void);

/* replace tabs in input with proper number of spaces */
int main() {
  while (0 < (len = getLine())) {
    detab();
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

void detab() {
  for (int i = 0; i < len; i++)
    if (line[i] != '\t')
      putchar(line[i]);
    else
      for (int j = 0; j < TABSIZE; j++) putchar(' ');
}