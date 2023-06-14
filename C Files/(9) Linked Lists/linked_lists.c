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
    lst_ptr->head_ptr =
        node_ptr; // The head address is now the address of the inserted node.
    node_ptr->next_node_ptr = NULL; // The node's next address is NULL
    lst_ptr->count++;
  } else {
    // Condition: If the list is nonempty
    struct node *temp_ptr =
        lst_ptr->head_ptr; // Define a temporary pointer that initially stores
                           // the address of the first node

    while (temp_ptr->next_node_ptr != NULL)
      temp_ptr =
          temp_ptr->next_node_ptr; // Change the address stored to that of the
                                   // next node by continually assuming the
                                   // nodes next_node_pointer
    temp_ptr->next_node_ptr = node_ptr; // Set the last but one node to point to
                                        // the new node that will be appended
    node_ptr->next_node_ptr = NULL; // Set the new node's next_node_ptr to NULL
    lst_ptr->count++;
  }
}

// Insert a node after the first occurence of a node with an element
// Accepts the search element, and pointers to the node to be inserted and to
// the linked list itself
void insert_after(int element, struct node *node_ptr,
                  struct linked_list *lst_ptr) {
  // Condition: If the list is empty
  if (lst_ptr->count == 0) {
    printf("There are no nodes\n");
    return;
  } else {
    struct node *temp_ptr =
        lst_ptr->head_ptr; // Define a temporary node pointer that points to the
                           // first node
    struct node *prev_node_ptr =
        temp_ptr; // Define a pointer that should eventually point to the node
                  // behind the node that temp_ptr points to
    while (temp_ptr != NULL) { // Traverse through the linked list
      // Condition: If the matching element is found
      if (temp_ptr->element == element)
        break;
      prev_node_ptr =
          temp_ptr; // Set the previous node pointer to point to a node
      temp_ptr = temp_ptr->next_node_ptr; // Set the temporary pointer to point
                                          // to the next node
    }

    // Condition: If the matching element was never found
    if (temp_ptr == NULL) {
      printf("Element not found\n");
      return;
    } else {
      // Condition: If the element was found, but it was in the last node:
      if (temp_ptr->next_node_ptr == NULL) {
        temp_ptr->next_node_ptr =
            node_ptr; // Set the temporary pointer to point to the new node
        node_ptr->next_node_ptr =
            NULL; // Set the new node's next_node_ptr to NULL
        lst_ptr->count++;
      } else {
        prev_node_ptr =
            temp_ptr; // Set the previous node pointer to the matching node
        temp_ptr =
            temp_ptr->next_node_ptr; // Set the temporary pointer to the point
                                     // to the node after the matching node
        prev_node_ptr->next_node_ptr =
            node_ptr; // Set the matching node's next_node_ptr to point to the
                      // new node
        node_ptr->next_node_ptr =
            temp_ptr; // Set the new node's next_node_ptr to point to the
                      // original node after the matching node
        lst_ptr->count++;
      }
      return;
    }
  }
  return;
}

void remove_first_node(struct linked_list *list);
void remove_last_node(struct linked_list *list);

int main() { return 0; }
