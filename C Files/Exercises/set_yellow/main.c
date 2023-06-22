#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma pack(1)

#define MAXVAL 100 // Maximum value of the length of the array
#define MAXNAME 25 // Maximum length of the "name" field
#define sz sizeof  // Abbr. for sizeof()
enum boolean { false, true };

struct medicine {
  int ID;
  char name[MAXNAME];
  float price;
  int quantity;
};

struct mnode {
  struct medicine element;
  struct mnode *next_node_ptr;
};

struct mLinkedList {
  int count;
  struct mnode *head_ptr;
};

struct medicine *readMedicineList(int count) {
  struct medicine *med_arr =
      (struct medicine *)malloc(sz(struct medicine) * count);
  int ID = 1;
  for (int i = 0; i < count; i++) {
    char name[MAXNAME];
    float price;
    int quantity;
    printf("Enter details for medicine %d\n", ID);
    printf("Name: ");
    scanf("%s", name);
    printf("Price: ");
    scanf("%f", &price);
    printf("Quantity: ");
    scanf("%d", &quantity);
    med_arr[i].ID = ID;
    strcpy(med_arr[i].name, name);
    med_arr[i].price = price;
    med_arr[i].quantity = quantity;
    ID++;
    printf("\n");
  }

  return med_arr;
}

void printMedicineList(struct medicine *arr, int arr_len) {
  for (int i = 0; i < arr_len; i++)
    printf("Medicine ID: %d"
           ", Name: %s"
           ", Price: %.2f"
           ", Quantity: %d\n",
           arr[i].ID, arr[i].name, arr[i].price, arr[i].quantity);
}

struct medicine findMedicine(float medPrice, struct medicine *arr, int count) {
  for (int i = 0; i < count; i++) {
    if (arr[i].price == medPrice) {
      printf("The first medicine found with price %.2f is:\n", medPrice);
      printf("Medicine ID: %d"
             ", Name: %s"
             ", Price: %.2f"
             ", Quantity: %d\n",
             arr[i].ID, arr[i].name, arr[i].price, arr[i].quantity);
      return arr[i];
    }
  }
  struct medicine no_med;
  no_med.ID = -1;

  printf("No medicine found with price %.2f\n", medPrice);
  printf("Medicine ID: %d"
         ", Name: %s"
         ", Price: %.2f"
         ", Quantity: %d\n",
         no_med.ID, no_med.name, no_med.price, no_med.quantity);
  return no_med;
}

struct medicine findMinQuantityMedicine(struct medicine *arr, int count) {
  int min = INT_MAX;
  for (int i = 0; i < count; i++)
    if (min > arr[i].quantity)
      min = arr[i].quantity;
  for (int j = 0; j < count; j++)
    if (min == arr[j].quantity) {
      printf("\nThe medicine with minimum quantity is: \n");
      printf("ID: %d"
             ", Name: %s"
             ", Price: %.2f"
             ", Quantity: %d\n",
             arr[j].ID, arr[j].name, arr[j].price, arr[j].quantity);
      return arr[j];
    }

  struct medicine err;
  err.ID = -1;
  return err;
}

struct mLinkedList *createMedLL(struct medicine *arr, int count) {
  struct mLinkedList *lst_ptr;
  lst_ptr = (struct mLinkedList *)malloc(sz(struct mLinkedList));
  lst_ptr->count = 0;
  lst_ptr->head_ptr = NULL;
  for (int i = 0; i < count; i++) {
    struct mnode *temp_node_ptr = (struct mnode *)malloc(sz(struct mnode));
    temp_node_ptr->element = arr[i];
    temp_node_ptr->next_node_ptr = NULL;
    if (lst_ptr->count == 0) {
      lst_ptr->head_ptr = temp_node_ptr;
      temp_node_ptr->next_node_ptr = NULL;
      lst_ptr->count++;
    } else {
      temp_node_ptr->next_node_ptr = lst_ptr->head_ptr;
      lst_ptr->head_ptr = temp_node_ptr;
      lst_ptr->count++;
    }
  }
  return lst_ptr;
}

void printMedLinkedList(struct mLinkedList *lst_ptr) {
  printf("\nPrinting the linked list created: \n");
  struct mnode *temp_ptr = lst_ptr->head_ptr;
  while (temp_ptr->next_node_ptr != NULL) {
    printf("Medicine ID: %d"
           ", Name: %s"
           ", Price: %.2f"
           ", Quantity: %d\n",
           temp_ptr->element.ID, temp_ptr->element.name,
           temp_ptr->element.price, temp_ptr->element.quantity);
    temp_ptr = temp_ptr->next_node_ptr;
  }
  printf("Medicine ID: %d"
         ", Name: %s"
         ", Price: %.2f"
         ", Quantity: %d\n",
         temp_ptr->element.ID, temp_ptr->element.name, temp_ptr->element.price,
         temp_ptr->element.quantity);
}

int main() {
  float match_price = 0.00;
  int count;
  printf("Enter the number of unique medicines in the store: ");
  scanf("%d", &count);
  printf("\n");
  struct medicine *med_arr = readMedicineList(count);
  printMedicineList(med_arr, count);
  printf("\nEnter the price of the medicine you wish to find: ");
  scanf("%f", &match_price);
  findMedicine(match_price, med_arr, count);
  findMinQuantityMedicine(med_arr, count);
  struct mLinkedList *ll = createMedLL(med_arr, count);
  printMedLinkedList(ll);
  return 0;
}
