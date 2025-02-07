#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#pragma pack(1)

struct Person {
  int id;
  char *name;
  int age;
  int height;
  int weight;
};

void insertionSort(struct Person **, size_t);

int32_t main(int argc, char **argv) {
  struct Person **array = (struct Person **)malloc(sizeof(struct Person *) * 5);

  array[0] = (struct Person *)malloc(sizeof(struct Person));
  array[0]->id = 1;
  array[0]->name = "Sokka";
  array[0]->age = 15;
  array[0]->height = 150;
  array[0]->weight = 45;

  array[1] = (struct Person *)malloc(sizeof(struct Person));
  array[1]->id = 2;
  array[1]->name = "Aang";
  array[1]->age = 112;
  array[1]->height = 137;
  array[1]->weight = 35;

  array[2] = (struct Person *)malloc(sizeof(struct Person));
  array[2]->id = 3;
  array[2]->name = "Zuko";
  array[2]->age = 16;
  array[2]->height = 160;
  array[2]->weight = 50;

  array[3] = (struct Person *)malloc(sizeof(struct Person));
  array[3]->id = 4;
  array[3]->name = "Katara";
  array[3]->age = 14;
  array[3]->height = 145;
  array[3]->weight = 38;

  array[4] = (struct Person *)malloc(sizeof(struct Person));
  array[4]->id = 5;
  array[4]->name = "Toph";
  array[4]->age = 12;
  array[4]->height = 113;
  array[4]->weight = 30;

  insertionSort(array, 5U);

  for (size_t i = 0; i < 5; i++) {
    struct Person *ptr = array[i];
    printf("%d %s %d %d %d\n", ptr->id, ptr->name, ptr->age, ptr->height,
           ptr->weight);
  }

  return 0;
}

void insertionSort(struct Person **a, size_t length) {
  for (ssize_t j = 1; j < length; j++) {
    ssize_t i = 0;
    while (a[j]->height > a[i]->height)
      i++;
    struct Person *m = a[j];
    for (ssize_t k = 0; k <= j - i - 1; k++)
      a[j - k] = a[j - k - 1];

    a[i] = m;
  }
}
