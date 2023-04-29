#include <stdio.h>

/*. Write a complete C program that will take one of the following options from
the user, and performs jobs accordingly: Option-1: Convert from degree Celsius
to deg. Fahrenheit Option-2: Convert from deg. Fahrenheit to deg. Celsius
Option-3: Quit the program execution
For deciding which job to execute based on the option number provided by the
user, you need to use a switch statement.
You must also ensure the user inputs a temperature value greater than –273.15
deg. C (for option-1) and –459.67 deg. F (for option-2), by repeatedly asking
the user to input a valid temperature as long as it not within the limit.*/

float ctof(float c);
float ftoc(float f);

int main() {
  int choice;

  printf("Menu\n");
  printf("Option-1: Convert from Celsius to Fahrenheit\n");
  printf("Option-2: Convert from Fahrenheit to Celsius\n");
  printf("Exit the program\n");

  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch (choice) {
  case 1: {
    float c;
    int checker = 1;
    while (checker) {
      printf("Enter the temperature in celsius: ");
      scanf("%f", &c);
      if (c > -273.15) {
        checker = 0;
        break;
      } else {
        checker = 1;
        printf("Please try again noob\n");
      }
    }
    float f = ctof(c);
    printf("The value in farenheit is: %f\n", f);
    break;
  }

  case 3: {
    printf("Thank you for using the program\n");
    break;
  }
  default:
    printf("Invalid input\n");
  }

  return 0;
}

float ctof(float c) {
  float f = (9.0 / 5.0) * c + 32.0;
  return f;
}
