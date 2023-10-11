#ifndef __DEFS_H
#define __DEFS_H

#include <stdio.h>
#include <stdlib.h>

struct point {
  float x;
  float y;
};

struct line_segment {
  struct point p1;
  struct point p2;
};

struct node {
  struct line_segment l1;
  struct node *next;
};

struct linked_list {
  int count;
  struct node *head;
};

struct linked_list *createNewList();
struct node *createNewNode(float xVal1, float yVal1, float xVal2, float yVal2);
void insertNodeAtStartIntoList(struct linked_list *l1, struct node *n1);
void printLinkedList(struct linked_list *l1);
struct line_segment findLineSegment(float val, struct linked_list *l1);
struct linked_list *sortListByP1X(struct linked_list *l1);

#endif
