#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures
struct linked_list_node
{
  int key;
  struct linked_list_node *next;
};

struct tree_node
{
  int key;
  struct linked_list_node *head;
  struct tree_node *left, *right;
};

struct bst
{
  struct tree_node *root;
};

// Typedefs
typedef struct linked_list_node ListNode;
typedef struct tree_node TreeNode;
typedef struct bst BinarySearchTree;

// Method signatures
ListNode *new_list_node(int key);
ListNode *push_front_LL(ListNode *head, ListNode *node);

TreeNode *new_tree_node(ListNode *head);
BinarySearchTree *new_BST();
void tree_insert(BinarySearchTree *T, TreeNode *z);

// Private helper functions
int linked_list_length_(ListNode *head);
void merge_(int array[], int p, int q, int r);
void merge_sort_(int array[], int p, int r);
void merge_sort_from_second_(ListNode *head);
void sort_dfs_(TreeNode *root);
void print_linked_list_(ListNode *head, FILE *output);
void traverse_dfs_(TreeNode *root, FILE *output);

// Evaluative functions
BinarySearchTree *readData();
void sortLists(BinarySearchTree *tree);
void traverse(BinarySearchTree *tree);

int main(int argc, char **argv)
{
  BinarySearchTree *tree = readData();
  sortLists(tree);
  traverse(tree);
  return 0;
}

[[nodiscard]] BinarySearchTree *readData()
{
  BinarySearchTree *res = new_BST();
  FILE *input           = fopen("file1.txt", "r");

  if (input == NULL)
  {
    perror("Input file not found\n");
    __builtin_trap();
  }

  size_t n;
  fscanf(input, "%zd ", &n);
  char buf[20001];
  while (n-- > 0)
  {
    bool first_node = false;
    ListNode *head = NULL, *actual_head = NULL;
    fgets(buf, sizeof(buf), input);
    char *tokens = strtok(buf, " ");
    while (tokens != NULL)
    {
      if (!first_node)
      {
        actual_head = new_list_node(atoi(tokens));
        first_node  = true;
      }
      else
        head = push_front_LL(head, new_list_node(atoi(tokens)));

      tokens = strtok(NULL, " ");
    }

    head               = push_front_LL(head, actual_head);
    TreeNode *new_node = new_tree_node(head);
    tree_insert(res, new_node);
  }

  fclose(input);
  return res;
}

void sortLists(BinarySearchTree *tree)
{
  sort_dfs_(tree->root);
}

void traverse(BinarySearchTree *tree)
{
  FILE *output = fopen("file2.txt", "w");
  traverse_dfs_(tree->root, output);
  fclose(output);
}

// Function implementations

// Create a new ListNode
// TC: O(1)
[[nodiscard]] ListNode *new_list_node(int key)
{
  ListNode *new_node = (ListNode *)malloc(sizeof(ListNode));
  new_node->next     = NULL;
  new_node->key      = key;

  return new_node;
}

// Push a ListNode to the front of a linked list
// TC: O(1)
[[nodiscard]] ListNode *push_front_LL(ListNode *head, ListNode *node)
{
  node->next = head;
  return node;
}

// Create a new BST node
// TC: O(1)
[[nodiscard]] TreeNode *new_tree_node(ListNode *head)
{
  TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode));

  new_node->key      = head->key;

  new_node->head     = (ListNode *)malloc(sizeof(ListNode));
  *new_node->head    = *head;

  new_node->left     = NULL;
  new_node->right    = NULL;

  return new_node;
}

// Create a new BST
// TC: O(1)
[[nodiscard]] BinarySearchTree *new_BST()
{
  BinarySearchTree *bst = (BinarySearchTree *)malloc(sizeof(BinarySearchTree));
  bst->root             = NULL;

  return bst;
}

// Insert a node into a BST while maintaining the BST property
// TC: O(n)
void tree_insert(BinarySearchTree *T, TreeNode *z)
{
  TreeNode *x = T->root, *y = NULL;

  while (x != NULL)
  {
    y = x;
    if (z->key < x->key)
      x = x->left;
    else
      x = x->right;
  }

  if (y == NULL)
    T->root = z;
  else if (z->key < y->key)
    y->left = z;
  else
    y->right = z;
}

// Calculate the length of a linked list
// TC: O(n)
int linked_list_length_(ListNode *head)
{
  int cnt           = 1;
  ListNode *current = head;
  while (current->next != NULL)
  {
    current = current->next;
    cnt++;
  }

  return cnt;
}

// Merge two sorted portions into one array
// TC: O(n)
void merge_(int array[], int p, int q, int r)
{
  int nL = q - p + 1, nR = r - q;
  int L[nL], R[nR];

  for (int i = 0; i < nL; i++)
    L[i] = array[p + i];

  for (int j = 0; j < nR; j++)
    R[j] = array[q + j + 1];

  int i = 0, j = 0, k = p;
  while (i < nL && j < nR)
  {
    if (L[i] <= R[j])
      array[k] = L[i++];
    else
      array[k] = R[j++];
    k++;
  }

  while (i < nL)
  {
    array[k] = L[i];
    i++;
    k++;
  }

  while (j < nR)
  {
    array[k] = R[j];
    j++;
    k++;
  }
}

// Sort an array
// TC: O(nlog(n))
void merge_sort_(int array[], int p, int r)
{
  if (p >= r)
    return;

  int q = (p + r) >> 1;
  merge_sort_(array, p, q);
  merge_sort_(array, q + 1, r);
  merge_(array, p, q, r);
}

// Merge sort a linked list from the second node
// TC: O(nlog(n));
void merge_sort_from_second_(ListNode *head)
{
  int n             = linked_list_length_(head->next), array[n];
  ListNode *current = head;
  current           = current->next;
  for (int i = 0; i < n; i++)
  {
    array[i] = current->key;
    current  = current->next;
  }

  merge_sort_(array, 0, n - 1);

  current = head;
  for (int i = 0; i < n; i++)
  {
    current->next->key = array[i];
    current            = current->next;
  }
}

// Sort linked lists in every noe
// TC: O(k.n log(n))
void sort_dfs_(TreeNode *root)
{
  if (root == NULL)
    return;

  merge_sort_from_second_(root->head);
  sort_dfs_(root->left);
  sort_dfs_(root->right);
}

// Write a linked list's contents onto a file
// TC: O(n)
void print_linked_list_(ListNode *head, FILE *output)
{
  ListNode *current = head;
  while (current->next != NULL)
  {
    fprintf(output, "%d ", current->key);
    current = current->next;
  }

  fprintf(output, "%d\n", current->key);
}

// Inorder traversal of the BST while printing all of the node's contents
// TC: O(k.n)
void traverse_dfs_(TreeNode *root, FILE *output)
{
  if (root == NULL)
    return;

  traverse_dfs_(root->left, output);
  print_linked_list_(root->head, output);
  traverse_dfs_(root->right, output);
}
