#include "defs.h"

struct linked_list *createNewList() {
  struct linked_list *lst_ptr =
      (struct linked_list *)malloc(sizeof(struct linked_list));
  lst_ptr->count = 0;
  lst_ptr->head = NULL;

  return lst_ptr;
}

struct node *createNewNode(float x1, float y1, float x2, float y2) {
  struct node *node_ptr = (struct node *)malloc(sizeof(struct node));
  node_ptr->l1.p1.x = x1;
  node_ptr->l1.p1.y = y1;
  node_ptr->l1.p2.x = x2;
  node_ptr->l1.p2.y = y2;

  node_ptr->next = NULL;

  return node_ptr;
}

void insertNodeAtStartIntoList(struct linked_list *l1, struct node *n1) {
  if (l1->count == 0) {
    l1->head = n1;
    n1->next = NULL;
    l1->count++;
  } else {
    n1->next = l1->head;
    l1->head = n1;
    l1->count++;
  }
}

void printLinkedList(struct linked_list *l1) {
  struct node *temp_node_ptr = l1->head;
  for (int i = 0; temp_node_ptr != NULL;
       i++, temp_node_ptr = temp_node_ptr->next)
    printf("The line segment no. %d is:\n"
           "Point 1: X: %f, Y: %f\n"
           "Point 2: X: %f, Y: %f\n",
           i + 1, temp_node_ptr->l1.p1.x, temp_node_ptr->l1.p1.y,
           temp_node_ptr->l1.p2.x, temp_node_ptr->l1.p2.y);
  printf("\n");
}

struct line_segment findLineSegment(float val, struct linked_list *l1) {
  struct line_segment ans;
  struct node *temp_node_ptr = l1->head;
  for (int i = 0; i < l1->count; i++, temp_node_ptr = temp_node_ptr->next) {
    if (temp_node_ptr->l1.p1.x == val)
      return temp_node_ptr->l1;
  }

  ans.p1.x = -1;
  ans.p1.y = -1;
  ans.p2.x = -1;
  ans.p2.y = -1;

  return ans;
}

struct linked_list *sortListByP1X(struct linked_list *l1) {
  // (1) Store all the nodes in an array
  // (2) Sort the new array by node.l1.p1.x
  // (3) Create a new linked list l2
  // (4) Create new nodes according to the array and insert into end;

  struct node *arr[l1->count];
  struct node *temp_node_ptr = l1->head;
  for (int i = 0; i < l1->count; i++) {
    arr[i] = temp_node_ptr;
    temp_node_ptr = temp_node_ptr->next;
  }

  int gap, i, j;
  struct node *temp;
  for (gap = (l1->count) / 2; gap > 0; gap /= 2)
    for (i = gap; i < (l1->count); i++)
      for (j = i - gap; j >= 0 && arr[j]->l1.p1.x > arr[j + gap]->l1.p1.x;
           j -= gap) {
        temp = arr[j];
        arr[j] = arr[j + gap];
        arr[j + gap] = temp;
      }

  struct linked_list *lst_ptr =
      (struct linked_list *)malloc(sizeof(struct linked_list));
  lst_ptr->count = 0;
  lst_ptr->head = NULL;

  for (int i = 0; i < l1->count; i++) {
    struct node *temp_node_ptr2 = (struct node *)malloc(sizeof(struct node));
    temp_node_ptr2 = arr[i];

    if (lst_ptr->count == 0) {
      lst_ptr->head = temp_node_ptr2;
      temp_node_ptr2->next = NULL;
      lst_ptr->count++;
    } else {
      struct node *temp_ptr3 = lst_ptr->head;
      while (temp_ptr3->next != NULL)
        temp_ptr3 = temp_ptr3->next;
      temp_ptr3->next = temp_node_ptr2;
      temp_node_ptr2->next = NULL;
      lst_ptr->count++;
    }
  }

  return lst_ptr;
}
