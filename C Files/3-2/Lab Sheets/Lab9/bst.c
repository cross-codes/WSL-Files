#include <stdio.h>
#include <stdlib.h>

#define max(a, b)                                                              \
  ({                                                                           \
    __typeof__(a) _a = (a);                                                    \
    __typeof__(b) _b = (b);                                                    \
    _a > _b ? _a : _b;                                                         \
  })

typedef struct listnode
{
  int value;
  struct listnode *next;
} ListNode;

typedef struct node
{
  int value;
  struct node *left;
  struct node *right;
} Node;

typedef struct bst
{
  Node *root;
} BST;

BST *new_bst()
{
  BST *bst  = malloc(sizeof(BST));
  bst->root = NULL;
  return bst;
}

Node *new_node(int value)
{
  Node *node  = malloc(sizeof(Node));
  node->value = value;
  node->left  = NULL;
  node->right = NULL;
  return node;
}

void traverse_in_order(Node *node)
{
  if (node == NULL)
  {
    return;
  }
  traverse_in_order(node->left);
  printf("%d ", node->value);
  traverse_in_order(node->right);
}

void traverse_pre_order(Node *node)
{
  if (node == NULL)
  {
    return;
  }

  printf("%d ", node->value);
  traverse_pre_order(node->left);
  traverse_pre_order(node->right);
}

void traverse_post_order(Node *node)
{
  if (node == NULL)
  {
    return;
  }

  traverse_post_order(node->left);
  traverse_post_order(node->right);
  printf("%d ", node->value);
}

void insert(BST *bst, int value)
{
  Node *node = new_node(value);
  if (bst->root == NULL)
  {
    bst->root = node;
    return;
  }
  Node *current = bst->root;
  while (current != NULL)
  {
    if (value < current->value)
    {
      if (current->left == NULL)
      {
        current->left = node;
        return;
      }
      current = current->left;
    }
    else
    {
      if (current->right == NULL)
      {
        current->right = node;
        return;
      }
      current = current->right;
    }
  }
}

BST *constructBST(int array[], size_t n)
{
  BST *bst = new_bst();
  for (size_t i = 0; i < n; i++)
    insert(bst, array[i]);

  return bst;
}

int search(BST *bst, int key)
{
  Node *current = bst->root;
  while (current != NULL)
  {
    if (key == current->value)
    {
      return 1;
    }
    else if (key < current->value)
    {
      current = current->left;
    }
    else
    {
      current = current->right;
    }
  }
  return 0;
}

int test_if_BST(Node *root)
{
  int res = 1;

  if (root == NULL)
  {
    res &= 1;
    return res;
  }

  if (root->left != NULL)
  {
    if (root->left->value <= root->value)
      res &= 1;
    else
      res &= 0;
  }

  if (root->right != NULL)
  {
    if (root->value <= root->right->value)
      res &= 1;
    else
      res &= 0;
  }

  res &= test_if_BST(root->left);
  res &= test_if_BST(root->right);

  return res;
}

int BST_height(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }

  return 1 + max(BST_height(root->left), BST_height(root->right));
}

int find_min(BST *bst)
{
  Node *current = bst->root;
  while (current->left != NULL)
  {
    current = current->left;
  }
  return current->value;
}

int find_max(BST *bst)
{
  Node *current = bst->root;
  while (current->right != NULL)
  {
    current = current->right;
  }
  return current->value;
}

Node *predecessor(Node *node)
{
  if (node->left == NULL)
  {
    return NULL;
  }
  Node *current = node->left;
  while (current->right != NULL)
  {
    current = current->right;
  }
  return current;
}

Node *successor(Node *node)
{
  if (node->right == NULL)
  {
    return NULL;
  }
  Node *current = node->right;
  while (current->left != NULL)
  {
    current = current->left;
  }
  return current;
}

void delete(BST *bst, Node *node)
{
  if (node == NULL)
    return;
  if (node->left == NULL && node->right == NULL)
  {
    // Node is a leaf
    Node *current = bst->root;
    while (current != NULL)
    {
      if (current->left == node)
      {
        current->left = NULL;
        break;
      }
      if (current->right == node)
      {
        current->right = NULL;
        break;
      }
      if (node->value < current->value)
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }
    }
    free(node);
    return;
  }

  if (node->left == NULL)
  {
    // Node only has right child
    Node *current = bst->root;
    if (current == node)
    {
      bst->root = node->right;
      free(node);
      return;
    }
    while (current != NULL)
    {
      if (current->left == node)
      {
        current->left = node->right;
        break;
      }
      if (current->right == node)
      {
        current->right = node->right;
        break;
      }
      if (node->value < current->value)
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }
    }
    free(node);
    return;
  }

  if (node->right == NULL)
  {
    // Node only has left child
    Node *current = bst->root;
    if (current == node)
    {
      bst->root = node->left;
      free(node);
      return;
    }
    while (current != NULL)
    {
      if (current->left == node)
      {
        current->left = node->left;
        break;
      }
      if (current->right == node)
      {
        current->right = node->left;
        break;
      }
      if (node->value < current->value)
      {
        current = current->left;
      }
      else
      {
        current = current->right;
      }
    }
    free(node);
    return;
  }

  // Node has both children
  Node *temp  = successor(node);
  node->value = temp->value;
  delete (bst, temp);
  return;
}

void remove_half_nodes(BST *bst, Node *node)
{
  if (node == NULL)
    return;

  if ((node->left != NULL && node->right == NULL) ||
      (node->left == NULL && node->right != NULL))
  {
    delete (bst, node);
    return;
  }

  remove_half_nodes(bst, node->left);
  remove_half_nodes(bst, node->right);
}

ListNode *flatten(Node *root)
{
  ListNode *head = (ListNode *)malloc(sizeof(ListNode));
  if (root == NULL)
    return NULL;

  head->value = root->value;
  head->next  = flatten(root->left);
  if (head->next != NULL)
    head->next->next = flatten(root->right);
  else
    head->next = flatten(root->right);

  return head;
}

// Driver program to test the above functions (feel free to play around with
// this)
/*
          2
        1
         3
          4
           5
            6
             7
              8
*/
int main()
{
  int elements[] = {2, 1, 3, 4, 5, 6, 7, 8};
  BST *bst       = constructBST(elements, 8);
  traverse_pre_order(bst->root);

  printf("\n");

  ListNode *ptr     = flatten(bst->root);
  ListNode *current = ptr;
  while (current != NULL)
  {
    printf("%d ", current->value);
    current = current->next;
  }

  return 0;
}
