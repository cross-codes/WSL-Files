#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 1024

#pragma pack(1)

enum Status
{
  FILLED,
  EMPTY,
  DELETED
};

struct Student
{
  long long ID;
  char name[30];
};

struct HashTableElement
{
  struct Student student;
  enum Status status;
};

int hash(int, int, int);
void insert(struct HashTableElement **, struct Student *, int);
void delete(struct HashTableElement **, int, int);
struct HashTableElement *search(struct HashTableElement **, int, int);

int32_t main(int argc, char **argv)
{
  struct HashTableElement **table = (struct HashTableElement **)malloc(
      sizeof(struct HashTableElement *) * 1024);

  for (size_t i = 0; i < 1024; i++)
    table[i] =
        (struct HashTableElement *)malloc(sizeof(struct HashTableElement));

  FILE *file   = fopen("t1_queries.txt", "r");
  short choice = 0;
  while (fscanf(file, "%hd", &choice) != 0)
  {
    if (choice == 1)
    {
      int ID;
      char name[30];
      fscanf(file, "%d,%29[^\n]", &ID, name);
      struct Student *student = (struct Student *)malloc(sizeof(struct Student));
    }
    else if (choice == 2)

    {
    }
    else
    {
      int ID;
      fscanf(file, "%d", &ID);
      search(table, ID, 1024);
    }
  }
  return 0;
}

int hash(int ID, int m, int i)
{
  double A = 0.6180339887;
  return (int)(floor(m * ((ID * A) - floor(ID * A))) + i) % m;
}

void insert(struct HashTableElement **table, struct Student *student, int m)
{
  struct HashTableElement *hte =
      (struct HashTableElement *)malloc(sizeof(struct HashTableElement));
  hte->student = *student;
  hte->status  = FILLED;

  int i        = 0;
  do
  {
    int q = hash(student->ID, m, i);
    if (table[q]->status == EMPTY || table[q]->status == DELETED)
    {
      table[q] = hte;
      return;
    }

    i++;
  } while (i != m);
}

struct HashTableElement *search(struct HashTableElement **table, int ID, int m)
{
  int i = 0, q;
  do
  {
    q = hash(ID, m, i);
    if (table[q]->student.ID == ID)
      return table[q];

    i++;
  } while (table[q]->status == EMPTY && i != m);

  return NULL;
}

void delete(struct HashTableElement **table, int ID, int m)
{
  struct HashTableElement *s = search(table, ID, m);
  if (s != NULL)
    s->status = DELETED;
}
