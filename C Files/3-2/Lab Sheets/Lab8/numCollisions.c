#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#pragma pack(1)

struct Student
{
  long long ID;
  char name[30];
};

struct Node
{
  struct Student *element;
  struct Node *next;
};

void reportCollisionCount__(int (*)(long long ID, size_t));

int function1(long long, size_t);
int function2(long long, size_t);
int function3(long long, size_t);
int function4(long long, size_t);
int function5(long long, size_t);
int function6(long long, size_t);

int32_t main(int argc, char **argv)
{
  reportCollisionCount__(function1);
  reportCollisionCount__(function2);
  reportCollisionCount__(function3);
  reportCollisionCount__(function4);
  reportCollisionCount__(function5);
  reportCollisionCount__(function6);

  return 0;
}

int function1(long long ID, size_t N)
{
  return ID % N;
}

int function2(long long ID, size_t N)
{
  return ID % (1LL << (63 - __builtin_clzll(N)));
}

int function3(long long ID, size_t N)
{
  return ID % 997;
}

int function4(long long ID, size_t N)
{
  double A = 0.6180339887;
  return floor(N * ((ID * A) - floor(ID * A)));
}

int function5(long long ID, size_t N)
{
  return ID % 887;
}

int function6(long long ID, size_t N)
{
  return (ID * 997) % N;
}

void reportCollisionCount__(int (*hashFunction)(long long ID, size_t N))
{
  FILE *file = fopen("t1_data.txt", "r");
  size_t N   = 0;
  fscanf(file, "%zd", &N);
  struct Node *hashTable[N << 1];
  for (size_t i = 0; i < (N << 1); i++)
    hashTable[i] = NULL;

  size_t numberOfCollisions = 0;
  for (size_t i = 0; i < N; i++)
  {
    struct Student *student = (struct Student *)malloc(sizeof(struct Student));
    fscanf(file, "%lld,%29[^\n]", &student->ID, student->name);

    int hash          = hashFunction(student->ID, N << 1);
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->element     = student;
    node->next        = hashTable[hash];

    if (hashTable[hash] != NULL)
      numberOfCollisions++;

    hashTable[hash] = node;
  }

  printf("Number of collisions: %zd\n", numberOfCollisions);
  fclose(file);

  for (size_t i = 0; i < N; i++)
  {
    struct Node *next, *current;
    if (hashTable[i] != NULL)
    {
      current = hashTable[i];
      next    = hashTable[i]->next;
      while (current != NULL)
      {
        free(current);
        current = next;
        next    = next->next;
      }
    }
  }
}
