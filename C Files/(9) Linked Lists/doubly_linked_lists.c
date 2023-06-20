#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

#define sz sizeof

// A doubly linked list (dll) contains a count, and a pointer to the first node
struct dll {
  int count;
  struct dllnode *head_ptr;
};

// A node in a dll, contains:
struct dllnode {
  int element;         // An element
  struct dllnode *pnp; // A pointer to the previous node (pnp) in the dll
  struct dllnode *nnp; // A pointer to the next node (nnp) in the dll
};

// Function to create a new dll
struct dll *create_new_dll(void) {
  struct dll *list_ptr;
  list_ptr = (struct dll *)malloc(sz(struct dll));
  list_ptr->count = 0;
  list_ptr->head_ptr = NULL;

  return list_ptr;
}

// Function to create a new node
struct dllnode *create_new_node(int value) {
  struct dllnode *node_ptr;
  node_ptr = (struct dllnode *)malloc(sz(struct dllnode));

  node_ptr->element = value;
  node_ptr->pnp = NULL;
  node_ptr->nnp = NULL;

  return node_ptr;
}

// Function to add a node into the beginning of a dll
void insert_into_beginning(struct dllnode *node_ptr, struct dll *lst_ptr) {
  // Condition: List is empty
  if (lst_ptr->count == 0) {
    lst_ptr->head_ptr = node_ptr;
    node_ptr->pnp = NULL;
    node_ptr->nnp = NULL;
    lst_ptr->count++;
  } // Condition: List is non-empty
  node_ptr->pnp = NULL;
  node_ptr->nnp = lst_ptr->head_ptr;
  node_ptr->nnp->pnp = node_ptr;
  lst_ptr->head_ptr = node_ptr;
  lst_ptr->count++;
}

// Function to remove the first node
void remove_first_node(struct dll *lst_ptr) {
  // Condition: List is empty
  if (lst_ptr->count == 0) {
    printf("List is empty\n");
    return;
  } // Conditon: List is non empty
  struct dllnode *temp_ptr = lst_ptr->head_ptr;
  lst_ptr->head_ptr = temp_ptr->nnp;
  lst_ptr->head_ptr->pnp = NULL;
  free(temp_ptr);
  lst_ptr->count--;
}

// ╭────────────────────╮
// │Additional functions│
// ╰────────────────────╯

// Function that inserts node at the end of the linked list
void insert_node_at_end(struct dll *lst_ptr, struct dllnode *node_ptr) {
  // Condition: List is empty
  if (lst_ptr->count == 0) {
    lst_ptr->head_ptr = node_ptr;
    node_ptr->pnp = NULL;
    node_ptr->nnp = NULL;
    return;
  } // Condition: List is non empty
  struct dllnode *temp_ptr = lst_ptr->head_ptr;
  while (temp_ptr->nnp != NULL)
    temp_ptr = temp_ptr->nnp;
  temp_ptr->nnp = node_ptr;
  node_ptr->pnp = temp_ptr;
  node_ptr->nnp = NULL;
}

int main() { return 0; }
