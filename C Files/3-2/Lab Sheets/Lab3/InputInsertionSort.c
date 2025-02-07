#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#pragma pack(1)

#define MAX_NAME_LENGTH 100

struct Person {
  int id;
  char *name;
  int age;
  int height;
  int weight;
};

void insertionSort(struct Person **, size_t);
void measureStatistics(char *, size_t, int);

int32_t main(int argc, char **argv) {

  measureStatistics("data/dat1000.csv", 1000, 1);
  measureStatistics("data/dat10000.csv", 10000, 2);
  measureStatistics("data/dat100000.csv", 100000, 3);
  measureStatistics("data/dat1000000.csv", 1000000, 4);

  return 0;
}

void measureStatistics(char *fileName, size_t length, int caseNumber) {
  FILE *file1 = fopen(fileName, "r");

  if (file1 == NULL) {
    printf("Error in opening file\n");
    return;
  }

  struct Person **array =
      (struct Person **)malloc(sizeof(struct Person *) * length);

  for (size_t i = 0; i < length; i++) {
    int id = -1, age = -1, height = -1, weight = -1;
    char *name = (char *)malloc(sizeof(char) * MAX_NAME_LENGTH);

    fscanf(file1, "%d,%99[^,],%d,%d,%d", &id, name, &age, &height, &weight);

    array[i] = (struct Person *)malloc(sizeof(struct Person));
    array[i]->id = id;
    array[i]->name = name;
    array[i]->age = age;
    array[i]->height = height;
    array[i]->weight = weight;
  }

  clock_t start = clock();
  insertionSort(array, length);
  clock_t end = clock();

  printf("Case #%d: Time taken: %lf s\n", caseNumber,
         (double)(end - start) / (CLOCKS_PER_SEC));

  fclose(file1);

  for (size_t i = 0; i < length; i++)
    free(array[i]);

  free(array);
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
