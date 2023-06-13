#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct linked_list {
  int count; // A "linked list" contains a count of the number of nodes and
  struct node *head_ptr; // a pointer to the first node
};

struct node {
  int element;                // A node has an element (int) and
  struct node *next_node_ptr; // a pointer to the next node
};

// Declare and define a pointer to a "linked list"
// Set it's count to zero and it's head address to NULL
struct linked_list *create_new_list(void) {
  struct linked_list *list_ptr;
  list_ptr = (struct linked_list *)malloc(sizeof(struct linked_list));
  list_ptr->count = 0;
  list_ptr->head_ptr = NULL;
  return list_ptr;
}

// Declare and define a pointer to a node
// Set it's element to the value passed, and the pointer to NULL
struct node *create_new_node(int value) {
  struct node *node_ptr;
  node_ptr = (struct node *)malloc(sizeof(struct node));
  node_ptr->element = value;
  node_ptr->next_node_ptr = NULL;
  return node_ptr;
}

// Insert a node into the beginning of the list
// Accepts pointers to a node, and to the linked list you want to modify
void insert_node_at_beginning(struct node *node_ptr,
                              struct linked_list *lst_ptr) {
  if (lst_ptr->count == 0) {
    // Condition: If the list is empty
    lst_ptr->head_ptr = node_ptr;   // The head address is now the inserted node
    node_ptr->next_node_ptr = NULL; // The node's next address is NULL
    lst_ptr->count++;
  } else {
    // Condition: If the list is nonempty
    node_ptr->next_node_ptr =
        lst_ptr->head_ptr; // The node now points to the next node which was
                           // what the original head pointed to

    lst_ptr->head_ptr = node_ptr; // The head address is the new node (which is
                                  // now the first node)
    lst_ptr->count++;
  }
}

// Insert a node into the end of a list
// Accepts pointers to a node, and to the linked list you want to modify
void insert_node_at_end(struct node *node_ptr, struct linked_list *lst_ptr) {
  if (lst_ptr->count == 0) {
    // Condition: If the list is empty
    lst_ptr->head_ptr = node_ptr;   // The head address is now the inserted node
    node_ptr->next_node_ptr = NULL; // The node's next address is NULL
    lst_ptr->count++;
  } else {
    // Condition: If the list is nonempty
    struct node *temp_ptr =
        lst_ptr->head_ptr; // Define a temporary pointer storing the address in
                           // head_address. Hence, it points to the first node
    while (temp_ptr->next_node_ptr != NULL) // ??? (and below)
      temp_ptr = temp_ptr->next_node_ptr;
    temp_ptr->next_node_ptr = node_ptr;
    node_ptr->next_node_ptr = NULL;
    lst_ptr->count++;
  }
}

void insert_after(int ele, struct node *node, struct linked_list *list);
void remove_first_node(struct linked_list *list);
void remove_last_node(struct linked_list *list);

int main() { return 0; }
