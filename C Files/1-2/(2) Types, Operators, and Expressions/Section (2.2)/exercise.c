#include <float.h>
#include <limits.h>
#include <stdio.h>

/* Exercise (2-1) */
/* Required : char, short, int, long (both signed and unsigned) */

int main() {
  printf("The range of the unsigned char type is: %u to %u\n", 0, UCHAR_MAX);
  printf("The range of the signed char type is: %d to %d\n", CHAR_MIN,
         SCHAR_MAX);

  printf("\nThe range of the signed short type is: %d to %d\n", SHRT_MIN,
         SHRT_MAX);
  printf("The range of the unsigned short type is: %u to %u\n", 0, USHRT_MAX);

  printf("\nThe range of the signed int type is: %d to %d\n", INT_MIN, INT_MAX);
  printf("The range of the unsigned int type is: %d to %u\n", 0, UINT_MAX);

  printf("\nThe range of the signed long type is: %ld to %ld\n", LONG_MIN,
         LONG_MAX);
  printf("The range of the unsigned long type is: %d to %lu\n", 0, ULONG_MAX);

  printf("\nThe range of the signed float type is: %f to %f\n", FLT_MIN,
         FLT_MAX);

  return 0;
}
