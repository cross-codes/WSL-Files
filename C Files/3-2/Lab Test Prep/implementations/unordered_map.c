#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

enum state
{
  FILLED,
  EMPTY,
  DELETED
};

struct table_element
{
  enum state state;
  int key;
  int value;
};

struct map
{
  struct table_element **table;
  size_t size;
};

typedef enum state State;
typedef struct table_element Element;
typedef struct map Map;

int hash(int k, int size, int i)
{
  return (k % size + i) % size;
}

Map *new_map(int size)
{
  Map *map   = (Map *)malloc(sizeof(Map));
  map->table = (Element **)malloc(sizeof(Element *) * size);
  for (int i = 0; i < size; i++)
  {
    map->table[i]        = (Element *)malloc(sizeof(Element));
    map->table[i]->state = EMPTY;
  }

  map->size = size;
  return map;
}

void insert(Map *map, int key, int value)
{
  int i = 0;
  do
  {
    int q = hash(key, map->size, i);
    if (map->table[q]->state == EMPTY)
    {
      map->table[q]->key   = key;
      map->table[q]->value = value;
      map->table[q]->state = FILLED;
      return;
    }
    i++;
  } while (i != map->size);

  perror("Size exceeded");
  __builtin_trap();
}

int search(Map *map, int key)
{
  int i = 0, q = hash(key, map->size, i);
  do
  {
    q = hash(key, map->size, i);
    if (map->table[q]->state == FILLED && map->table[q]->key == key)
      return q;
    i++;
  } while (map->table[q]->state != EMPTY && i != map->size);

  return -1;
}

int get(Map *map, int key)
{
  int q = search(map, key);
  if (q == -1)
  {
    return -1;
  }

  return map->table[q]->value;
}

void delete(Map *map, int key)
{
  int i = search(map, key);
  if (i != -1)
    map->table[i]->state = DELETED;
}

int main(int argc, char **argv)
{
  Map *map = new_map(5);
  insert(map, 12, 20);
  printf("%d\n", search(map, 12));
  printf("%d\n", get(map, 11));
  insert(map, 11, 200);
  printf("%d\n", get(map, 11));
  delete (map, 11);
  printf("%d\n", get(map, 11));

  return 0;
}
