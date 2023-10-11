#include "grocerystore.h"

int main() {
  int num_g;
  printf("Enter number of unique grocery items in the store:");
  scanf("%d", &num_g);
  struct item *gItems = readGroceryList(num_g);

  printGroceryList(gItems, num_g);

  int qVal;
  printf("\nEnter the quantity of the item you wish to find: ");
  scanf("%d", &qVal);
  struct item fItem = findItem(qVal, gItems, num_g);
  if (fItem.ID == -1)
    printf("\nItem Not Found!\n\n");
  else {
    printf("\nThe first item found with quantity %d is:\n", qVal);
    printf("ID: %d, ", fItem.ID);
    printf("Name: %s, ", fItem.name);
    printf("Price: %f, ", fItem.price);
    printf("Quantity: %d\n\n", fItem.quantity);
  }

  struct item maxItem = findMaxPriceItem(gItems, num_g);
  printf("\nThe item with maximum price is:\n");
  printf("ID: %d, ", maxItem.ID);
  printf("Name: %s, ", maxItem.name);
  printf("Price: %f, ", maxItem.price);
  printf("Quantity: %d\n\n", maxItem.quantity);

  struct gLinkedList *gLL = createGLL(gItems, num_g);
  printf("Printing the Linked List created:\n");
  printGLinkedList(gLL);
}
