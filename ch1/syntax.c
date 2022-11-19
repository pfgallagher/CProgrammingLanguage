#include <stdio.h>

/* naively check c source file for balanced quotes, braces, brackets, and
 * parentheses */
int main() {
  int c, sQuoteCount = 1, dQuoteCount = 1, braceCount = 0, bracketCount = 0,
         parenCount = 0;
  while ((c = getchar()) != EOF) {
    switch (c) {
      case '(':
        parenCount++;
        break;
      case ')':
        parenCount--;
        break;
      case '[':
        bracketCount++;
        break;
      case ']':
        bracketCount--;
        break;
      case '{':
        braceCount++;
        break;
      case '}':
        braceCount--;
        break;
      case '\'':
        sQuoteCount *= -1;
        break;
      case '"':
        dQuoteCount *= -1;
        break;
    }
  }
  if (sQuoteCount != 1) {
    printf("Missing '\n");
  }
  if (dQuoteCount != 1) {
    printf("Missing \"\n");
  }
  if (braceCount < 0) {
    printf("Missing {\n");
  }
  if (0 < braceCount) {
    printf("Missing }\n");
  }
  if (bracketCount < 0) {
    printf("Missing [\n");
  }
  if (0 < bracketCount) {
    printf("Missing ]\n");
  }
  if (parenCount < 0) {
    printf("Missing (\n");
  }
  if (0 < parenCount) {
    printf("Missing )\n");
  }
  return 0;
}
