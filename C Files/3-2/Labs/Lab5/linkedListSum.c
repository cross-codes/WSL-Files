#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node *NODE;
struct node {
  int ele;
  NODE next;
};

typedef struct linked_list *LIST;
struct linked_list {
  int count;
  NODE head;
};

LIST createNewList() {
  LIST myList;
  myList = (LIST)malloc(sizeof(struct linked_list));
  myList->count = 0;
  myList->head = NULL;
  return myList;
}

NODE createNewNode(int value) {
  NODE myNode;
  myNode = (NODE)malloc(sizeof(struct node));
  myNode->ele = value;
  myNode->next = NULL;
  return myNode;
}

int llSumNTR(NODE head) {
  if (head == NULL)
    return 0;
  return head->ele + llSumNTR(head->next);
}

int llSumTR(NODE head, int currentSum) {
  if (head == NULL)
    return currentSum;
  else {
    return llSumTR(head->next, currentSum + head->ele);
  }
}

int llSumITER(NODE head) {
  int currentSum = 0;
  while (head != NULL) {
    currentSum += head->ele;
    head = head->next;
  }

  return currentSum;
}

int main() {
  FILE *fp;
  fp = fopen("data/numbers1000.txt", "r");
  if (fp == NULL) {
    printf("Error opening file\n");
    exit(1);
  }

  int num;
  LIST myList = createNewList();
  while (fscanf(fp, "%d", &num) != EOF) {
    NODE myNode = createNewNode(num);
    myNode->next = myList->head;
    myList->head = myNode;
    myList->count++;
  }
  fclose(fp);

  NODE head = myList->head;
  clock_t start = clock();
  printf("Non tail recursive, total sum: %d ", llSumNTR(head));
  clock_t end = clock();
  printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

  head = myList->head;
  start = clock();
  printf("Tail recursive, total sum: %d ", llSumTR(head, 0));
  end = clock();
  printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

  head = myList->head;
  start = clock();
  printf("Iterative, total sum: %d ", llSumITER(head));
  end = clock();
  printf("Time taken: %f\n", (double)(end - start) / CLOCKS_PER_SEC);

  return 0;
}
