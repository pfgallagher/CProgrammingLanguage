#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
int isBlankLine(char line[], int len);
void trimEnd(char line[], int len);

/* removes blank lines and trailing blanks / tabs */
int main() {
  int len;            /* current line length */
  char line[MAXLINE]; /* current input line */
  while (0 < (len = getLine(line, MAXLINE))) {
    if (!isBlankLine(line, len)) {
      trimEnd(line, len);
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

int isBlankLine(char line[], int len) {
  int i;
  for (i = 0; i < len; ++i) {
    if (line[i] != '\n') return 0;
  }
  return 1;
}

void trimEnd(char line[], int len) {
  while (len) {
    if ((line[len - 1] != ' ' && line[len - 1] != '\t') &&
        (line[len] == ' ' || line[len] == '\t')) {
      line[len] = '\n';
      line[len + 1] = '\0';
      break;
    }
    --len;
  }
}