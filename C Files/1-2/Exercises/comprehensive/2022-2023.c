#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

#define sz sizeof

struct consumer {
  int Consumer_ID;
  char Name[25];
  int Age;
  char Address[100];
  char Gender;
};

struct electricty_bill {
  int bill_number;
  struct consumer Consumer_details;
  int month;
  int year;
  int Units_Consumed;
  int Bill_Amount;
};

struct node {
  struct electricty_bill element;
  struct node *prev;
  struct node *next;
};

struct dllist {
  struct node *head;
  int count;
};

struct dllist *readDetails(int num) {
  struct dllist *linked_list = (struct dllist *)malloc(sz(struct dllist));
  linked_list->head = NULL;
  linked_list->count = 0;
  struct node *prev_ptr = NULL;
  for (int i = 0; i < num; i++) {
    if (linked_list->head == NULL) {
      struct node *temp_node = (struct node *)malloc(sz(struct node));
      printf("Enter the Bill number: ");
      scanf("%d", &(temp_node->element.bill_number));
      printf("Enter the consumer ID: ");
      scanf("%d", &(temp_node->element.Consumer_details.Consumer_ID));
      printf("Enter the name: ");
      scanf("%s", temp_node->element.Consumer_details.Name);
      printf("Enter the Age: ");
      scanf("%d", &(temp_node->element.Consumer_details.Age));
      printf("Enter the Address: ");
      scanf(" %[^\n]%*c", temp_node->element.Consumer_details.Address);
      printf("Enter the Gender: ");
      scanf("%c", &(temp_node->element.Consumer_details.Gender));
      printf("Enter the month: ");
      scanf("%d", &(temp_node->element.month));
      printf("Enter the year: ");
      scanf("%d", &(temp_node->element.year));
      printf("Enter the number of units consumed: ");
      int units = 0, bill_amt = 0;
      scanf("%d", &units);
      temp_node->element.Units_Consumed = units;
      if (units < 100)
        bill_amt = units * 5;
      else if (units < 200)
        bill_amt = 100 * 5 + (units - 100) * 10;
      else
        bill_amt = 100 * 15 + (units - 200) * 15;
      temp_node->element.Bill_Amount = bill_amt;
      linked_list->head = temp_node;
      prev_ptr = temp_node;
      temp_node->prev = NULL;
      temp_node->next = NULL;
      linked_list->count++;
    } else {
      struct node *temp_node = (struct node *)malloc(sz(struct node));
      printf("Enter the Bill number: ");
      scanf("%d", &(temp_node->element.bill_number));
      printf("Enter the consumer ID: ");
      scanf("%d", &(temp_node->element.Consumer_details.Consumer_ID));
      printf("Enter the name: ");
      scanf("%s", temp_node->element.Consumer_details.Name);
      printf("Enter the Age: ");
      scanf("%d", &(temp_node->element.Consumer_details.Age));
      printf("Enter the Address: ");
      scanf(" %[^\n]%*c", temp_node->element.Consumer_details.Address);
      printf("Enter the Gender: ");
      scanf("%c", &(temp_node->element.Consumer_details.Gender));
      printf("Enter the month: ");
      scanf("%d", &(temp_node->element.month));
      printf("Enter the year: ");
      scanf("%d", &(temp_node->element.year));
      printf("Enter the number of units consumed: ");
      int units = 0, bill_amt = 0;
      scanf("%d", &units);
      temp_node->element.Units_Consumed = units;
      if (units < 100)
        bill_amt = units * 5;
      else if (units < 200)
        bill_amt = 100 * 5 + (units - 100) * 10;
      else
        bill_amt = 100 * 15 + (units - 200) * 15;
      prev_ptr->next = temp_node;
      temp_node->element.Bill_Amount = bill_amt;
      temp_node->prev = prev_ptr;
      prev_ptr = temp_node;
      temp_node->next = NULL;
      linked_list->count++;
    }
  }

  return linked_list;
}

void subsidizeBills(struct dllist *linked_list_ptr) {
  struct node *temp_node_ptr = linked_list_ptr->head;
  while (temp_node_ptr != NULL) {
    if (temp_node_ptr->element.Consumer_details.Age > 65)
      temp_node_ptr->element.Bill_Amount -=
          0.5 * temp_node_ptr->element.Bill_Amount;
    temp_node_ptr = temp_node_ptr->next;
  }
}

int32_t main() {
  struct dllist *test = readDetails(2);
  printf("%d\n", test->head->element.Bill_Amount);
  printf("%d\n", test->head->next->element.Bill_Amount);
  subsidizeBills(test);
  printf("%d\n", test->head->next->element.Bill_Amount);
  printf("%d\n", test->head->element.Bill_Amount);

  return 0;
}
