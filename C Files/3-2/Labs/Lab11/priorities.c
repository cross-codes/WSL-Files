#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct heap
{
  int *data;
  int size;
  int capacity;
  int depth;
};

struct person
{
  int id, age, height, weight;
  char *name;
};

typedef struct heap Heap;
typedef struct person Person;

void swap(int *A, int i, int j)
{
  int temp = A[i];
  A[i]     = A[j];
  A[j]     = temp;
}

Heap *create_heap()
{
  Heap *h     = (Heap *)malloc(sizeof(Heap));
  h->data     = (int *)malloc(sizeof(int));
  h->size     = 0;
  h->capacity = 1;
  h->depth    = 0;

  return h;
}

int get_parent(int i)
{
  return i > 0 ? (i - 1) >> 1 : 0;
}

int get_left_child(int i)
{
  return (i << 1) + 1;
}

int get_right_child(int i)
{
  return (i << 1) + 2;
}

void max_heapify(Heap *h, int index)
{
  int l       = get_left_child(index);
  int r       = get_right_child(index);

  int largest = INT_MIN;

  if (l < h->size && h->data[l] > h->data[index])
    largest = l;
  else
    largest = index;

  if (r < h->size && h->data[r] > h->data[largest])
    largest = r;

  if (largest != index)
  {
    swap(h->data, index, largest);
    max_heapify(h, largest);
  }
}

void build_max_heap(Heap *h)
{
  for (int i = (h->size - 1) >> 1; i >= 0; i--)
    max_heapify(h, i);
}

void add_to_tree(Heap *h, int value)
{
  if (h->size == h->capacity)
  {
    h->data = (int *)realloc(h->data, sizeof(int) * (h->capacity << 1));
    h->capacity <<= 1;
  }

  h->data[h->size] = value;
  h->depth         = 32 - __builtin_clz(++h->size);
}

int num_nodes_at_depth(Heap *h, int depth)
{
  int actual_depth = h->depth;

  if (actual_depth == 0)
    return 0;
  else if (depth < 1)
    return -1;
  else if (depth < actual_depth)
    return 1 << depth;
  else if (depth > actual_depth)
    return 0;
  else
    return h->size - (1 << (actual_depth - 1)) + 1;
}

int maximum(Heap *h)
{
  if (h->size == 0)
    return -1;
  else
    return h->data[0];
}

int extract_max(Heap *h)
{
  int max    = maximum(h);
  h->data[0] = h->data[h->size - 1];
  h->size--;
  max_heapify(h, 0);
  return max;
}

void increase_key(Heap *heap, int x, int k)
{
  heap->data[x] = k;
  int i         = 0;
  for (int j = 0; j < heap->size; j++)
    if (heap->data[j] == x)
      i = j;

  while (i > 1 && heap->data[get_parent(i)] < heap->data[i])
  {
    swap(heap->data, i, get_parent(i));
    i = get_parent(i);
  }
}

void insert(Heap *heap, int value)
{
  int k                  = value;
  heap->data[heap->size] = INT_MIN;
  heap->size++;
  increase_key(heap, INT_MIN, k);
}

int main()
{
  Heap *heap = create_heap();
  add_to_tree(heap, 2);
  printf("Number of node at depth %d: %d\n", heap->depth,
         num_nodes_at_depth(heap, heap->depth));
  add_to_tree(heap, 3);
  printf("Number of node at depth %d: %d\n", heap->depth,
         num_nodes_at_depth(heap, heap->depth));
  add_to_tree(heap, 4);
  printf("Number of node at depth %d: %d\n", heap->depth,
         num_nodes_at_depth(heap, heap->depth));
  add_to_tree(heap, 12);
  printf("Number of node at depth %d: %d\n", heap->depth,
         num_nodes_at_depth(heap, heap->depth));
  add_to_tree(heap, 1);
  printf("Number of node at depth %d: %d\n", heap->depth,
         num_nodes_at_depth(heap, heap->depth));
  add_to_tree(heap, 10);
  printf("Number of node at depth %d: %d\n", heap->depth,
         num_nodes_at_depth(heap, heap->depth));
  add_to_tree(heap, 11);
  printf("Number of node at depth %d: %d\n", heap->depth,
         num_nodes_at_depth(heap, heap->depth));
  add_to_tree(heap, 11);

  build_max_heap(heap);

  for (int i = 0; i < heap->size; i++)
    printf("%d ", heap->data[i]);

  printf("\nDepth : %d\n", heap->depth);

  return 0;
}
