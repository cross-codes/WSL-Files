#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma pack(1)

#define MAX 100

struct employee {
  int ID;
  float salary;
  char division[25];
} employeeData[MAX];

void addemployee(int ID, float salary, char *division, int pos);
void quickpointersort(struct employee *v[], int left, int right);
void sw(struct employee *v[], int i, int j);

int main() {
  int count = 0;
  printf("Enter the number of employees you would like to add: ");
  scanf("%d", &count);
  if (count > MAX)
    return 0;

  struct employee *arr_point[count];
  for (int i = 0; i < count; i++) {
    int ID;
    float salary;
    char *division;

    division = (char *)malloc(25 * sizeof(char));
    printf("Enter the ID: ");
    scanf("%d", &ID);
    printf("Enter the salary: ");
    scanf("%f", &salary);
    printf("Enter the division: ");
    scanf("%s", division);

    addemployee(ID, salary, division, i);
    arr_point[i] = &(employeeData[i]);
    free(division);
  }
  quickpointersort(arr_point, 0, count - 1);

  for (int i = 0; i < count; i++) {
    printf("Employee %d\n", i + 1);
    printf("ID: %d\n"
           "Salary: %.2f\n"
           "Division: %s\n",
           arr_point[i]->ID, arr_point[i]->salary, arr_point[i]->division);
  }

  return 0;
}

void addemployee(int ID, float salary, char *division, int pos) {
  struct employee nargs;
  nargs.ID = ID;
  nargs.salary = salary;
  strcpy(nargs.division, division);
  employeeData[pos] = nargs;
}

void quickpointersort(struct employee *v[], int left, int right) {
  int i, last;

  if (left > right)
    return;

  sw(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if (v[i]->salary < v[left]->salary)
      sw(v, ++last, i);
  sw(v, left, last);
  quickpointersort(v, left, last - 1);
  quickpointersort(v, last + 1, right);
}

void sw(struct employee *v[], int i, int j) {
  struct employee *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
