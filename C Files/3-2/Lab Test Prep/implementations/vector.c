#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct vector
{
  ssize_t last_element_index;
  size_t current_size;
  int *array;
};

typedef struct vector Vector;

Vector *new_vector(int size)
{
  assert(size >= 0);
  Vector *v             = (Vector *)malloc(sizeof(Vector));
  v->array              = (int *)malloc(sizeof(int) * size);
  v->last_element_index = size - 1;
  v->current_size       = size;

  return v;
}

void push_back(Vector *vec, int value)
{
  if (vec->last_element_index == vec->current_size - 1)
  {
    if (vec->current_size > 0)
    {
      vec->array =
          (int *)realloc(vec->array, (vec->current_size << 1) * sizeof(int));
      vec->current_size <<= 1;
    }
    else
    {
      vec->array        = (int *)realloc(vec->array, sizeof(int));
      vec->current_size = 1;
    }
  }

  vec->array[++vec->last_element_index] = value;
}

int main(int argc, char **argv)
{
  clock_t start = clock();

  Vector *vec   = new_vector(0);
  push_back(vec, 2);
  push_back(vec, 1);
  push_back(vec, 8);
  push_back(vec, 9);
  push_back(vec, 5);
  push_back(vec, 5);
  push_back(vec, 5);
  push_back(vec, 5);
  push_back(vec, 5);

  for (int i = 0; i < 9; i++)
    printf("%d ", vec->array[i]);

  clock_t end = clock();
  printf("\n%ld\n", (end - start) / CLOCKS_PER_SEC);

  return 0;
}
