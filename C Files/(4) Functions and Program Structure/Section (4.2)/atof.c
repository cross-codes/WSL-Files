#include <ctype.h>
#include <math.h>
#include <stdio.h>

double atof(char a[]);

int main() {
  char num[] = "1.23e6";

  printf("The value is %lf\n", atof(num));

  return 0;
}

double atof(char s[]) {
  int i = 0, sign;
  double val, power, normalized, exponent;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10 * val + (s[i] - '0');
    power *= 10.0;
  }
  normalized = sign * val / power;
  if (s[i] == 'e' || s[i] == 'E') {
    i++;
    for (exponent = 0.0; isdigit(s[i]); i++)
      exponent = 10 * exponent + (s[i] - '0');
    return normalized * pow(10.0, exponent);
  }
  return normalized;
}
