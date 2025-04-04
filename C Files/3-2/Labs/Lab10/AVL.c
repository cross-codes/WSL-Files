#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
  int value;
  struct TreeNode *left;
  struct TreeNode *right;
  int incl_height;
} TreeNode;

typedef struct BST
{
  TreeNode *root;
} BST;

int max(int a, int b)
{
  return (a > b) ? a : b;
}

int inclusive_height(TreeNode *node)
{
  if (node == NULL)
    return 0;
  return node->incl_height;
}

int is_height_balanced(TreeNode *root)
{
  if (root == NULL)
    return 1;

  int left_incl_height  = inclusive_height(root->left);
  int right_incl_height = inclusive_height(root->right);

  if (abs(left_incl_height - right_incl_height) <= 1 &&
      is_height_balanced(root->left) && is_height_balanced(root->right))
    return 1;
  else
    return 0;
}

int balance_factor(TreeNode *node)
{
  if (node == NULL)
    return 0;

  return inclusive_height(node->left) - inclusive_height(node->right);
}

void update_incl_height(TreeNode *node)
{
  if (node)
  {
    node->incl_height =
        1 + max(inclusive_height(node->left), inclusive_height(node->right));
  }
}

inline TreeNode *rotate_left(TreeNode *x)
{
  TreeNode *y = x->right;
  x->right    = y->left;
  y->left     = x;
  update_incl_height(x);
  update_incl_height(y);
  return y;
}

inline TreeNode *rotate_right(TreeNode *y)
{
  TreeNode *x = y->left;
  y->left     = x->right;
  x->right    = y;
  update_incl_height(y);
  update_incl_height(x);
  return x;
}

TreeNode *new_node(int value)
{
  TreeNode *node    = malloc(sizeof(TreeNode));
  node->value       = value;
  node->left        = NULL;
  node->right       = NULL;
  node->incl_height = 1;
  return node;
}

TreeNode *insertAVL(TreeNode *node, int value)
{
  if (node == NULL)
    return new_node(value);
  if (value < node->value)
    node->left = insertAVL(node->left, value);
  else if (value > node->value)
    node->right = insertAVL(node->right, value);
  else
    return node;

  update_incl_height(node);
  int balance = balance_factor(node);

  if (balance > 1)
  {
    if (value < node->left->value)
    {
      return rotate_right(node);
    }
    else
    {
      node->left = rotate_left(node->left);
      return rotate_right(node);
    }
  }

  if (balance < -1)
  {
    if (value > node->right->value)
    {
      return rotate_left(node);
    }
    else
    {
      node->right = rotate_right(node->right);
      return rotate_left(node);
    }
  }

  return node;
}

TreeNode *predecessor(TreeNode *node)
{
  if (node->left == NULL)
  {
    return NULL;
  }
  TreeNode *current = node->left;
  while (current->right != NULL)
  {
    current = current->right;
  }
  return current;
}

TreeNode *deleteAVL(TreeNode *node, int value)
{
  if (node == NULL)
    return NULL;
  else if (value < node->value)
  {
    node->left = deleteAVL(node->left, value);
    node->incl_height =
        1 + inclusive_height(node->left) > inclusive_height(node->right)
            ? inclusive_height(node->left)
            : inclusive_height(node->right);
  }
  else if (value > node->value)
  {
    node->right = deleteAVL(node->right, value);
    node->incl_height =
        1 + inclusive_height(node->left) > inclusive_height(node->right)
            ? inclusive_height(node->left)
            : inclusive_height(node->right);
  }
  else
  {
    if (node->left == NULL && node->right == NULL)
    {
      free(node);
      node = NULL;
    }
    else if (node->left == NULL)
    {
      TreeNode *temp = node;
      node           = node->right;
      free(temp);
    }
    else
    {
      TreeNode *temp = predecessor(node);
      node->value    = temp->value;
      node->left     = deleteAVL(node->left, temp->value);
      node->incl_height =
          1 + inclusive_height(node->left) > inclusive_height(node->right)
              ? inclusive_height(node->left)
              : inclusive_height(node->right);
    }
  }

  int balance = balance_factor(node);
  if (balance > 1)
  {
    if (balance_factor(node->left) >= 0)
    {
      node = rotate_right(node);
      node->right->incl_height =
          1 + (inclusive_height(node->right->left) >
                       inclusive_height(node->right->right)
                   ? inclusive_height(node->right->left)
                   : inclusive_height(node->right->right));
      node->incl_height =
          1 + (inclusive_height(node->left) > inclusive_height(node->right)
                   ? inclusive_height(node->left)
                   : inclusive_height(node->right));
    }
    else
    {
      node->left = rotate_left(node->left);
      node->left->left->incl_height =
          1 + (inclusive_height(node->left->left->left) >
                       inclusive_height(node->left->left->right)
                   ? inclusive_height(node->left->left->left)
                   : inclusive_height(node->left->left->right));
      node->left->incl_height = 1 + (inclusive_height(node->left->left) >
                                             inclusive_height(node->left->right)
                                         ? inclusive_height(node->left->left)
                                         : inclusive_height(node->left->right));

      node                    = rotate_right(node);
      node->right->incl_height =
          1 + (inclusive_height(node->right->left) >
                       inclusive_height(node->right->right)
                   ? inclusive_height(node->right->left)
                   : inclusive_height(node->right->right));
      node->incl_height =
          1 + (inclusive_height(node->left) > inclusive_height(node->right)
                   ? inclusive_height(node->left)
                   : inclusive_height(node->right));
    }
  }
  else if (balance < -1)
  {
    if (balance_factor(node->right) <= 0)
    {
      node                    = rotate_left(node);
      node->left->incl_height = 1 + (inclusive_height(node->left->left) >
                                             inclusive_height(node->left->right)
                                         ? inclusive_height(node->left->left)
                                         : inclusive_height(node->left->right));
      node->incl_height =
          1 + (inclusive_height(node->left) > inclusive_height(node->right)
                   ? inclusive_height(node->left)
                   : inclusive_height(node->right));
    }
    else
    {
      node->right = rotate_right(node->right);
      node->right->right->incl_height =
          1 + (inclusive_height(node->right->right->left) >
                       inclusive_height(node->right->right->right)
                   ? inclusive_height(node->right->right->left)
                   : inclusive_height(node->right->right->right));
      node->right->incl_height =
          1 + (inclusive_height(node->right->left) >
                       inclusive_height(node->right->right)
                   ? inclusive_height(node->right->left)
                   : inclusive_height(node->right->right));
      node                    = rotate_left(node);
      node->left->incl_height = 1 + (inclusive_height(node->left->left) >
                                             inclusive_height(node->left->right)
                                         ? inclusive_height(node->left->left)
                                         : inclusive_height(node->left->right));
      node->incl_height =
          1 + (inclusive_height(node->left) > inclusive_height(node->right)
                   ? inclusive_height(node->left)
                   : inclusive_height(node->right));
    }
  }

  return node;
}

void traverse_bfs(TreeNode *node)
{
  if (node == NULL)
  {
    return;
  }
  TreeNode *queue[100];
  int front     = 0;
  int back      = 0;
  queue[back++] = node;
  while (front != back)
  {
    TreeNode *current = queue[front++];
    printf("%d ", current->value);
    if (current->left != NULL)
    {
      queue[back++] = current->left;
    }
    if (current->right != NULL)
    {
      queue[back++] = current->right;
    }
  }
}

int main()
{
  BST *bst  = malloc(sizeof(BST));
  bst->root = NULL;

  bst->root = insertAVL(bst->root, 1);
  bst->root = insertAVL(bst->root, 2);
  bst->root = insertAVL(bst->root, 3);
  bst->root = insertAVL(bst->root, 4);
  bst->root = insertAVL(bst->root, 5);
  bst->root = insertAVL(bst->root, 6);
  bst->root = insertAVL(bst->root, 7);
  bst->root = insertAVL(bst->root, 8);
  bst->root = insertAVL(bst->root, 9);

  printf("Is balanced: %d\n", is_height_balanced(bst->root));

  traverse_bfs(bst->root);

  bst->root = deleteAVL(bst->root, 2);

  printf("\nIs balanced: %d\n", is_height_balanced(bst->root));

  traverse_bfs(bst->root);

  return 0;
}
