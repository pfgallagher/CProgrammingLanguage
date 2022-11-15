#include <stdio.h>

int main() {
  printf("%d\n", getchar() != EOF); /* Example of incorrect assignment, which
                                       will only ever equal 0 or 1. */
  printf("%d\n", EOF);              // Prints EOF, which is -1
  return 0;
}