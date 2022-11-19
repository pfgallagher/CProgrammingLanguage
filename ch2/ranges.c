#include <float.h>
#include <limits.h>
#include <stdio.h>

long power(long base, int n);
long min(int size);
long max(int size);
long umax(int size);

/* print ranges of various types */
int main() {
  printf("signed char via headers (min: %d; max: %d)\n", CHAR_MIN, CHAR_MAX);
  printf("signed char via computation (min: %ld; max: %ld)\n",
         min(sizeof(char)), max(sizeof(char)));
  printf("unsigned char via headers (min: %d; max: %u)\n", 0, UCHAR_MAX);
  printf("unsigned char via computation (min: %d; max: %ld)\n", 0,
         umax(sizeof(char)));
  printf("signed short via headers (min: %d; max: %d)\n", SHRT_MIN, SHRT_MAX);
  printf("signed short via computation (min: %ld; max: %ld)\n",
         min(sizeof(short)), max(sizeof(short)));
  printf("unsigned short via headers (min: %d; max: %u)\n", 0, USHRT_MAX);
  printf("unsigned short via computation (min: %d; max: %ld)\n", 0,
         umax(sizeof(short)));
  printf("signed int via headers (min: %d; max: %d)\n", INT_MIN, INT_MAX);
  printf("signed int via computation (min: %ld; max: %ld)\n", min(sizeof(int)),
         max(sizeof(int)));
  printf("unsigned int via headers (min: %d; max: %u)\n", 0, UINT_MAX);

  printf("unsigned int via computation (min: %d; max: %ld)\n", 0,
         umax(sizeof(int)));
  printf("signed long via headers (min: %ld; max: %ld)\n", LONG_MIN, LONG_MAX);
  printf("unsigned long via headers (min: %d; max: %lu)\n", 0, ULONG_MAX);
  printf("float via headers (min: %f; max: %f)\n", -FLT_MAX, FLT_MAX);
  printf("double via headers (min: %f; max: %f)\n", -DBL_MAX, DBL_MAX);
  printf("long double via headers (min: %Lf; max: %Lf)\n", -LDBL_MAX, LDBL_MAX);
  return 0;
}

long max(int size) { return ((power(2, size * CHAR_BIT) / 2)) - 1; }

long min(int size) { return -((power(2, size * CHAR_BIT) / 2)); }

long umax(int size) { return (power(2, size * CHAR_BIT)) - 1; }

long power(long base, int n) {
  long p;
  for (p = 1; 0 < n; --n) p = p * base;
  return p;
}