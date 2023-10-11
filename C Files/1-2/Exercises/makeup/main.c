#include "defs.h"

int main() {
  struct linked_list *linklist1 = createNewList();

  struct node *n1 = createNewNode(1, 2, 3, 4);
  insertNodeAtStartIntoList(linklist1, n1);

  struct node *n2 = createNewNode(5, 6, 7, 8);
  insertNodeAtStartIntoList(linklist1, n2);

  struct node *n3 = createNewNode(9, 10, 11, 12);
  insertNodeAtStartIntoList(linklist1, n3);

  struct node *n4 = createNewNode(13, 14, 15, 16);
  insertNodeAtStartIntoList(linklist1, n4);

  struct node *n5 = createNewNode(17, 18, 19, 20);
  insertNodeAtStartIntoList(linklist1, n5);

  struct node *n6 = createNewNode(21, 22, 23, 24);
  insertNodeAtStartIntoList(linklist1, n6);

  printLinkedList(linklist1);

  printf("\nEnter the x value of point p1 for the line segment you wish to "
         "search:");
  float find_val;
  scanf("%f", &find_val);

  struct line_segment ls1 = findLineSegment(find_val, linklist1);
  if (ls1.p1.x == -1) {
    printf("The required line segment is not found in the linked list\n");
  } else {
    printf("The first line segment found is:\n");
    printf("Point 1: X: %f, Y: %f\n", ls1.p1.x, ls1.p1.y);
    printf("Point 2: X: %f, Y: %f\n", ls1.p2.x, ls1.p2.y);
  }

  printf("\nSorting the Elements in the LinkedList and Printing them:\n\n");
  struct linked_list *linklist2 = sortListByP1X(linklist1);

  printLinkedList(linklist2);

  return 0;
}
