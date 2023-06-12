#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct linked_list {
  int count; // A "linked list" contains a count of the number of nodes and
  struct node *head_address; // a pointer to the first node
};

struct node {
  int element;               // A node has an element (int) and
  struct node *next_address; // a pointer to the next node
};

// Declare and define a pointer to a "linked list"
// Set it's count to zero and it's head address to NULL
struct linked_list *create_new_list(void) {
  struct linked_list *list;
  list = (struct linked_list *)malloc(sizeof(struct linked_list));
  list->count = 0;
  list->head_address = NULL;
  return list;
}

// Declare and define a pointer to a node
// Set it's element to the value passed, and the pointer to NULL
struct node *create_new_node(int value) {
  struct node *node;
  node = (struct node *)malloc(sizeof(struct node));
  node->element = value;
  node->next_address = NULL;
  return node;
}

// Insert a node into the beginning of the list
// Accepts pointers to a node, and to the linked list you want to modify
void insert_node_at_beginning(struct node *node, struct linked_list *lst) {
  if (lst->count == 0) {
    // Condition: If the list is empty
    lst->head_address = node;  // The head address is now the inserted node
    node->next_address = NULL; // The node's next address is NULL
    lst->count++;
  } else {
    // Condition: If the list is nonempty
    node->next_address =
        lst->head_address; // The node now points to the next node which was
                           // what the original head pointed to

    lst->head_address =
        node; // The head address is the new node (which is now the first node)
    lst->count++;
  }
}

// Insert a node into the end of a list
// Accepts pointers to a node, and to the linked list you want to modify
void insert_node_at_end(struct node *node, struct linked_list *lst) {
  if (lst->count == 0) {
    // Condition: If the list is empty
    lst->head_address = node;  // The head address is now the inserted node
    node->next_address = NULL; // The node's next address is NULL
    lst->count++;
  } else {
    // Condition: If the list is nonempty
    struct node *temp =
        lst->head_address; // Define a temporary pointer storing the address in
                           // head_address. Hence, it points to the first node
    while (temp->next_address != NULL) // ??? (and below)
      temp = temp->next_address;
    temp->next_address = node;
    node->next_address = NULL;
    lst->count++;
  }
}

void insert_after(int ele, struct node *node, struct linked_list *list);
void remove_first_node(struct linked_list *list);
void remove_last_node(struct linked_list *list);

int main() { return 0; }
