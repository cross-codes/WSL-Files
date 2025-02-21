#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#pragma pack(1)

#define MAX_NAME_LENGTH 100

typedef struct person {
  int id;
  char *name;
  int age;
  int height;
  int weight;
} Person;

void swap(Person **, ptrdiff_t, ptrdiff_t);

ptrdiff_t twoWayHoarePartition(Person **, ptrdiff_t, ptrdiff_t, ptrdiff_t);
ptrdiff_t threeWayHoarePartition(Person **, ptrdiff_t, ptrdiff_t, ptrdiff_t);
ptrdiff_t lomutoPartition(Person **, ptrdiff_t, ptrdiff_t, ptrdiff_t);

void testStatistic(ptrdiff_t (*f)(Person **, ptrdiff_t, ptrdiff_t, ptrdiff_t));

void measure__(ptrdiff_t (*f)(Person **, ptrdiff_t, ptrdiff_t, ptrdiff_t),
               char *fileName, ptrdiff_t length, int caseNumber);

int32_t main(int argc, char **argv) {
  testStatistic(twoWayHoarePartition);
  testStatistic(threeWayHoarePartition);
  testStatistic(lomutoPartition);

  measure__(twoWayHoarePartition, "dat1000000.csv", 1000000, 1);
  measure__(threeWayHoarePartition, "dat1000000.csv", 1000000, 2);
  measure__(lomutoPartition, "dat1000000.csv", 1000000, 3);
  return 0;
}

void swap(Person *array[], ptrdiff_t i, ptrdiff_t j) {
  Person *temp = array[j];
  array[j] = array[i];
  array[i] = temp;
}

ptrdiff_t twoWayHoarePartition(Person **array, ptrdiff_t lowIdx,
                               ptrdiff_t highIdx, ptrdiff_t pivotIndex) {
  swap(array, pivotIndex, lowIdx);
  ptrdiff_t leftIdx = lowIdx + 1, rightIdx = highIdx;
  Person *pivotPointer = array[lowIdx];

  while (leftIdx < rightIdx) {
    for (; leftIdx <= highIdx && array[leftIdx]->height <= pivotPointer->height;
         leftIdx++)
      ;

    for (; array[rightIdx]->height > pivotPointer->height; rightIdx--)
      ;

    if (leftIdx < rightIdx) {
      swap(array, leftIdx, rightIdx);
    }
  }

  ptrdiff_t pivotPosition;
  if (array[leftIdx]->height < pivotPointer->height && leftIdx <= rightIdx)
    pivotPosition = leftIdx;
  else
    pivotPosition = leftIdx - 1;

  swap(array, lowIdx, pivotPosition);
  return pivotPosition;
}

ptrdiff_t threeWayHoarePartition(Person **array, ptrdiff_t lowIdx,
                                 ptrdiff_t highIdx, ptrdiff_t pivotIndex) {
  swap(array, pivotIndex, highIdx);
  ptrdiff_t leftIdx = lowIdx, rightIdx = highIdx - 1;
  ptrdiff_t midIdx = lowIdx;
  Person *pivotPointer = array[highIdx];

  while (midIdx <= rightIdx) {
    if (array[midIdx]->height < pivotPointer->height) {
      swap(array, leftIdx, midIdx);
      leftIdx++;
      midIdx++;
    } else if (array[midIdx]->height > pivotPointer->height) {
      swap(array, midIdx, rightIdx);
      rightIdx--;
    } else
      midIdx++;
  }

  swap(array, midIdx, highIdx);
  return midIdx;
}

ptrdiff_t lomutoPartition(Person **array, ptrdiff_t startIdx, ptrdiff_t endIdx,
                          ptrdiff_t discard) {
  Person *x = array[endIdx];
  ptrdiff_t i = startIdx - 1;
  for (ptrdiff_t j = startIdx; j < endIdx - 1; j++) {
    if (array[j]->height <= x->height) {
      i++;
      swap(array, i, j);
    }
  }

  swap(array, i + 1, endIdx);
  return i + 1;
}

void testStatistic(ptrdiff_t (*idempotent)(Person **, ptrdiff_t, ptrdiff_t,
                                           ptrdiff_t)) {
  Person **array = (Person **)malloc(sizeof(Person *) * 5);

  array[0] = (Person *)malloc(sizeof(Person));
  array[0]->id = 1;
  array[0]->name = "Sokka";
  array[0]->age = 15;
  array[0]->height = 150;
  array[0]->weight = 45;

  array[1] = (Person *)malloc(sizeof(Person));
  array[1]->id = 2;
  array[1]->name = "Aang";
  array[1]->age = 112;
  array[1]->height = 137;
  array[1]->weight = 35;

  array[2] = (Person *)malloc(sizeof(Person));
  array[2]->id = 3;
  array[2]->name = "Zuko";
  array[2]->age = 16;
  array[2]->height = 160;
  array[2]->weight = 50;

  array[3] = (Person *)malloc(sizeof(Person));
  array[3]->id = 4;
  array[3]->name = "Katara";
  array[3]->age = 14;
  array[3]->height = 145;
  array[3]->weight = 38;

  array[4] = (Person *)malloc(sizeof(Person));
  array[4]->id = 5;
  array[4]->name = "Toph";
  array[4]->age = 12;
  array[4]->height = 113;
  array[4]->weight = 30;

  printf("Calling partition on index %zu with height %d\n", 4UL,
         array[4]->height);
  ptrdiff_t pos = idempotent(array, 0, 4, 4);

  printf("Partitioned array: ");
  for (ptrdiff_t i = 0; i < 5; i++)
    printf("%d ", array[i]->height);

  printf("\nReported pivot index: %zu\n", pos);
}

void measure__(ptrdiff_t (*idempotent)(Person **, ptrdiff_t, ptrdiff_t,
                                       ptrdiff_t),
               char *fileName, ptrdiff_t length, int caseNumber) {
  FILE *file1 = fopen(fileName, "r");

  if (file1 == NULL) {
    printf("Error in opening file\n");
    return;
  }

  Person **array = (Person **)malloc(sizeof(Person *) * length);

  for (ptrdiff_t i = 0; i < length; i++) {
    int id = -1, age = -1, height = -1, weight = -1;
    char *name = (char *)malloc(sizeof(char) * MAX_NAME_LENGTH);

    fscanf(file1, "%d,%99[^,],%d,%d,%d", &id, name, &age, &height, &weight);

    array[i] = (Person *)malloc(sizeof(Person));
    array[i]->id = id;
    array[i]->name = name;
    array[i]->age = age;
    array[i]->height = height;
    array[i]->weight = weight;
  }

  clock_t start = clock();
  ptrdiff_t pos = idempotent(array, 0, length - 1, rand() % 100);
  clock_t end = clock();

  printf("Case #%d: Time taken: %lf s\n", caseNumber,
         (double)(end - start) / (CLOCKS_PER_SEC));

  fclose(file1);

  for (ptrdiff_t i = 0; i < length; i++)
    free(array[i]);

  free(array);
}
