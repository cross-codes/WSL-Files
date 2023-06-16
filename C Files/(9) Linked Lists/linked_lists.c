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
  // Condition: There are no nodes in the linked list
  if (lst_ptr->count == 0) {
    printf("There are no nodes\n");
    return;
  }
  struct node *temp_ptr = lst_ptr->head_ptr; // Initialize a temporary pointer
                                             // that points to the first node
  while (temp_ptr != NULL &&
         temp_ptr->element !=
             element) // Traverse through the list till first match
    temp_ptr = temp_ptr->next_node_ptr;

  // Condition: The match was not found
  if (temp_ptr == NULL) {
    printf("Element not found\n");
    return;
  }

  struct node *node_after_element_ptr =
      temp_ptr->next_node_ptr; // Initialize a pointer that points to the node
                               // after the matching node
  temp_ptr->next_node_ptr = node_ptr; // Make the matching node's nnp the new
                                      // node's address
  node_ptr->next_node_ptr =
      node_after_element_ptr; // Make the new node's nnp the address of the node
                              // after the match originally
  lst_ptr->count++;
}

// Remove the first node in a linked list
// Accepts a pointer to the linked list
void remove_first_node(struct linked_list *lst_ptr) {
  if (lst_ptr->count == 0)
    printf("Current linked list is empty\n");
  else {
    struct node *temp_ptr = lst_ptr->head_ptr;
    lst_ptr->head_ptr =
        temp_ptr->next_node_ptr; // Make the head point to the second node
    free(temp_ptr);              // Remove the temporary pointer
    lst_ptr->count--;
  }
  return;
}

// Remove the last node in a linked list
// Accepts a pointer to a linked list
void remove_last_node(struct linked_list *lst_ptr) {
  // Condition: If the linked list is empty
  if (lst_ptr->count == 0) {
    printf("The linked list is empty\n");
    return;
  } // Condition: If the linked list has only one node
  else if (lst_ptr->count == 1) {
    lst_ptr->count--;
    free(lst_ptr->head_ptr);  // Free the last node
    lst_ptr->head_ptr = NULL; // Set the head pointer to null
    return;
  }
  struct node *temp_ptr = lst_ptr->head_ptr;
  struct node *prev_node_ptr = temp_ptr;

  while ((temp_ptr->next_node_ptr) != NULL) {
    prev_node_ptr = temp_ptr;
    temp_ptr = temp_ptr->next_node_ptr;
  }

  prev_node_ptr->next_node_ptr = NULL;
  lst_ptr->count--;
  free(temp_ptr);
}

// Return a pointer to the first node that has a matching element
// Accepts the element itself, and a pointer to the linked list
struct node *search(int data, struct linked_list *lst_ptr) {
  // Condition: If the linked list is empty
  if (lst_ptr->count == 0) {
    printf("The linked list is empty\n");
    return NULL;
  }

  struct node *temp_ptr = lst_ptr->head_ptr;
  while (temp_ptr->next_node_ptr != NULL && temp_ptr->element != data)
    temp_ptr = temp_ptr->next_node_ptr;

  return temp_ptr;
}

int main() { return 0; }
