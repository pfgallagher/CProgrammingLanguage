#include <stdio.h>

#define MAXLINE 20 /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
int checkLineOverflow(char line[], int len);

/* print longest input line */
int main() {
  int len;               /* current line length */
  int max = 0;           /* maximum length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */
  while (0 < (len = getLine(line, MAXLINE))) {
    len += checkLineOverflow(line, len);
    if (max < len) {
      max = len;
      copy(longest, line);
    }
  }
  if (0 < max) /* there was a line */
    printf("length %d: %s", max, longest);
  if (MAXLINE < max) printf("...");
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

int checkLineOverflow(char line[], int len) {
  int last = line[len - 1];
  int overflow = 0;
  if (last != '\n' && last != EOF) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
      ++overflow;
    }
  }
  return overflow;
}