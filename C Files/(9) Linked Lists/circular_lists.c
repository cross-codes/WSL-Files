#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct node {
  int element;
  struct node *next_node_pointer;
};

struct linked_list {
  int count;
  struct node *head_ptr;
};

// Detect cycles
int isCircular(struct linked_list *lst_ptr) {
  struct node *slow_ptr = lst_ptr->head_ptr;
  struct node *fast_ptr = lst_ptr->head_ptr;

  return 0;
}

int main() { return 0; }
