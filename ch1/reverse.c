#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char line[], int len);

/* reverse each line of input */
int main() {
  int len;            /* current line length */
  char line[MAXLINE]; /* current input line */
  while (0 < (len = getLine(line, MAXLINE))) {
    reverse(line, len);
    printf("%s", line);
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

/* reverse: reverse given line */
void reverse(char line[], int len) {
  int i;
  i = 0;
  while (line[len] == '\0' || line[len] == '\n') {
    --len;
  }
  while (i < len) {
    int temp = line[len];
    line[len] = line[i];
    line[i] = temp;
    ++i;
    --len;
  }
}