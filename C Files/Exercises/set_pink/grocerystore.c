#include "grocerystore.h"

struct item *readGroceryList(int count) {
  struct item *groceryList = (struct item *)malloc(sizeof(struct item) * count);
  int ID = 1;
  printf("\n");

  for (int i = 0; i < count; i++) {
    printf("Enter details for item %d:\n", ID);
    groceryList[i].ID = ID;
    printf("Name: ");
    scanf("%s", groceryList[i].name);
    printf("Price: ");
    scanf("%f", &groceryList[i].price);
    printf("Quantity: ");
    scanf("%d", &groceryList[i].quantity);
    printf("\n");
    ID++;
  }

  return groceryList;
}

void printGroceryList(struct item *gItems, int count) {
  for (int i = 0; i < count; i++)
    printf("Item ID: %d"
           ", Name: %s"
           ", Price: %.6f"
           ", Quantity: %d\n",
           gItems[i].ID, gItems[i].name, gItems[i].price, gItems[i].quantity);
}

struct item findItem(int qVal, struct item *gItems, int count) {
  struct item ret_gItem;
  for (int i = 0; i < count; i++)
    if (gItems[i].quantity == qVal) {
      ret_gItem = gItems[i];
      return ret_gItem;
    }
  ret_gItem.ID = -1;
  return ret_gItem;
}

struct item findMaxPriceItem(struct item *gItems, int count) {
  int max = -1000;
  int max_index = -1;
  for (int i = 0; i < count; i++) {
    if (max < gItems[i].price) {
      max = gItems[i].price;
      max_index = i;
    }
  }

  return gItems[max_index];
}

struct gLinkedList *createGLL(struct item *gItems, int count) {
  // Create the linked list
  struct gLinkedList *lst_ptr =
      (struct gLinkedList *)malloc(sizeof(struct gLinkedList));
  lst_ptr->count = 0;
  lst_ptr->first = NULL;

  // Create a node in a loop and add it to the linked list
  for (int i = 0; i < count; i++) {
    struct gNode *temp_node_ptr = (struct gNode *)malloc(sizeof(struct gNode));
    temp_node_ptr->gro_item = gItems[i];
    temp_node_ptr->next = NULL;
    if (lst_ptr->count == 0) {
      lst_ptr->first = temp_node_ptr;
      temp_node_ptr->next = NULL;
      lst_ptr->count++;
    } else {
      temp_node_ptr->next = lst_ptr->first;
      lst_ptr->first = temp_node_ptr;
      lst_ptr->count++;
    }
  }

  return lst_ptr;
}

void printGLinkedList(struct gLinkedList *newList) {
  struct gNode *temp_node_ptr = newList->first;
  while (temp_node_ptr != NULL) {
    printf("Item ID: %d"
           ", Name: %s"
           ", Price: %.6f"
           ", Quantity: %d\n",
           temp_node_ptr->gro_item.ID, temp_node_ptr->gro_item.name,
           temp_node_ptr->gro_item.price, temp_node_ptr->gro_item.quantity);
    temp_node_ptr = temp_node_ptr->next;
  }
}
