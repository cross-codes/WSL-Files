#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

#define MAXVAL 100
enum boolean { false, true };

/* INFO: Methods to detect cycles in a linked list
 * There is generally no method to identify whether or not a linked list is
 * circular. This is because there is no difference in the way the linked list
 * and node are defined. As such, the implementation is also not unique, because
 * the concept of the last node is not well defined. Hence the functions
 * implemented here assume that a linked list already exsits, and it only checks
 * if the linked list is circular */

struct node {
  int element;
  struct node *next_node_pointer;
};

struct linked_list {
  int count;
  struct node *head_ptr;
};

// NOTE: If a linked list is not ciruclar, it must necessarily be linear
// and must hence have a node pointing to NULL
// The functions below are thus exhaustive

// Method 1: Storing the address of all the visited nodes
int is_circular_1(struct linked_list *lst_ptr) {
  struct node *addr[MAXVAL];
  int addr_count = 0;
  struct node *temp_ptr = lst_ptr->head_ptr;
  while (temp_ptr != NULL) {
    for (int j = 0; j < addr_count; j++)
      if (temp_ptr == addr[j])
        return true;
    addr[addr_count] = temp_ptr;
    addr_count++;
    temp_ptr = temp_ptr->next_node_pointer;
  }
  return false;
}

// Method 2: Floyd's fast and slow pointer method
int is_circular_2(struct linked_list *lst_ptr) {
  struct node *slow_ptr = lst_ptr->head_ptr, *fast_ptr = lst_ptr->head_ptr;
  while (slow_ptr != NULL && fast_ptr != NULL &&
         fast_ptr->next_node_pointer != NULL) {
    slow_ptr = slow_ptr->next_node_pointer;
    fast_ptr = fast_ptr->next_node_pointer->next_node_pointer;
    if (slow_ptr == fast_ptr)
      return true;
  }

  return false;
}

int main() {
  printf("Hello World\n");

  struct linked_list *l1;
  struct node *n1 = (struct node *)malloc(sizeof(struct node));
  struct node *n2 = (struct node *)malloc(sizeof(struct node));
  struct node *n3 = (struct node *)malloc(sizeof(struct node));
  struct node *n4 = (struct node *)malloc(sizeof(struct node));
  struct node *n5 = (struct node *)malloc(sizeof(struct node));
  l1 = (struct linked_list *)malloc(sizeof(struct linked_list));
  n1->element = 2;
  n2->element = 2;
  n3->element = 2;
  n4->element = 2;
  n5->element = 2;
  l1->count = 5;
  l1->head_ptr = n1;
  n1->next_node_pointer = n2;
  n2->next_node_pointer = n3;
  n3->next_node_pointer = n4;
  n4->next_node_pointer = n5;
  n5->next_node_pointer = n1;

  printf("Method 1 returns: %d\n", is_circular_1(l1));
  printf("Method 2 returns: %d\n", is_circular_2(l1));
  return 0;
}
