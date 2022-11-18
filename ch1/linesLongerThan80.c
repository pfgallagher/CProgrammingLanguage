#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print lines longer than 80 */
int main() {
  int len;            /* current line length */
  char line[MAXLINE]; /* current input line */
  while (0 < (len = getLine(line, MAXLINE))) {
    if (80 < len) {
      printf("%s", line);
    }
  }
  return 0;
}

/* getLine: read a line into s, return length */
int getLine(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;
  i = 0;
  while ((to[i] = from[i]) != '\0') ++i;
}
