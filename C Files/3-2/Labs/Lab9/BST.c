#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b)                                                              \
  ({                                                                           \
    __typeof__(a) _a = (a);                                                    \
    __typeof__(b) _b = (b);                                                    \
    _a > _b ? _a : _b;                                                         \
  })

struct node
{
  int key;
  struct node *left;
  struct node *right;
};

struct bst
{
  struct node *root;
};

struct person
{
  int id;
  char *name;
  int age;
  int height;
  int weight;
};

struct person_tree_node
{
  int key;
  struct person *person;
  struct person_tree_node *left;
  struct person_tree_node *right;
};

struct person_bst
{
  struct person_tree_node *root;
};

struct tree_traversal_node
{
  int id;
  int depth;
};

typedef struct node TreeNode;
typedef struct bst BST;
typedef struct person Person;
typedef struct person_tree_node PersonTreeNode;
typedef struct person_bst PBST;
typedef struct tree_traversal_node TraversalPair;

void swap(int, int);

BST *new_BST();
TreeNode *new_node(int);

void inorder_traversal(TreeNode *);
void preorder_traversal(TreeNode *);
void postorder_traversal(TreeNode *);
void tree_insert(BST *, int);
BST *constructBST(int[], int);
bool is_valid_BST(BST *);
int height(BST *);

PBST *new_PBST();
PersonTreeNode *new_person_node(Person);
void pbst_insert(PBST *, Person);
PBST *constructPBST(Person[], int n);
int height_pbst(PBST *bst);
int LCA(PBST *, int, int);
void flatten(BST *bst);

int main(int argc, char **argv)
{

  BST *bst1 = new_BST();

  tree_insert(bst1, 2);
  tree_insert(bst1, 1);
  tree_insert(bst1, 3);
  tree_insert(bst1, 4);
  tree_insert(bst1, 5);
  tree_insert(bst1, 6);
  tree_insert(bst1, 7);
  tree_insert(bst1, 8);

  inorder_traversal(bst1->root);
  printf("\n");
  postorder_traversal(bst1->root);
  printf("\n");
  preorder_traversal(bst1->root);
  printf("\n");

  int a[]   = {2, 1, 3, 4, 5, 6, 7, 8};
  BST *bst2 = constructBST(a, 8);

  inorder_traversal(bst1->root);
  printf("\n");
  postorder_traversal(bst1->root);
  printf("\n");
  preorder_traversal(bst1->root);
  printf("\n");

  printf("%d\n", is_valid_BST(bst1));
  printf("%d\n", is_valid_BST(bst2));
  printf("%d\n", height(bst1));
  printf("%d\n", height(bst2));

  printf("Reading from file and testing heights\n");

  FILE *handle = fopen("n_integers.txt", "r");
  if (handle == NULL)
  {
    perror("Input file not found\n");
    __builtin_trap();
  }

  BST *trees[20001];
  int trees_pos = 0;
  char buf[2001];
  size_t n;

  while (fscanf(handle, "%zd", &n) != EOF)
  {
    int array[n];

    char _;
    fscanf(handle, "%c%c", &_, &_);

    for (size_t i = 0; i < n; i++)
      fscanf(handle, " %d", array + i);

    trees[trees_pos++] = constructBST(array, n);

    fscanf(handle, "%c%c%c", &_, &_, &_);
    printf("\n");
  }

  for (int i = 0; i < trees_pos; i++)
    printf("Height: %d\n", height(trees[i]));

  fclose(handle);

  // Reading the csv files
  FILE *csv_handle = fopen("dat10.csv", "r");
  if (csv_handle == NULL)
  {
    perror("Input file not found\n");
    __builtin_trap();
  }

  Person people[20001];
  int i = 0;

  while (fgets(buf, sizeof(buf), csv_handle))
  {
    char *tokens   = strtok(buf, ",");

    people[i].id   = atoi(tokens);
    tokens         = strtok(NULL, ",");

    people[i].name = (char *)malloc(strlen(tokens) + 1);
    strcpy(people[i].name, tokens);

    tokens           = strtok(NULL, ",");
    people[i].age    = atoi(tokens);
    tokens           = strtok(NULL, ",");
    people[i].height = atoi(tokens);
    tokens           = strtok(NULL, ",");
    people[i].weight = atoi(tokens);
    i++;
  }

  PBST *pbst = constructPBST(people, i);
  printf("Height of PBST: %d\n", height_pbst(pbst));
  printf("LCA: %d\n", LCA(pbst, 2, 3));

  return 0;
}

void swap(int a, int b)
{
  int temp = a;
  a        = b;
  b        = temp;
}

BST *new_BST()
{
  BST *bst  = (BST *)malloc(sizeof(BST));
  bst->root = NULL;
  return bst;
}

TreeNode *new_node(int value)
{
  TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
  node->key      = value;
  node->left     = NULL;
  node->right    = NULL;
  return node;
}

void inorder_traversal(TreeNode *root)
{
  if (root == NULL)
    return;

  inorder_traversal(root->left);
  printf("%d ", root->key);
  inorder_traversal(root->right);
}

void preorder_traversal(TreeNode *root)
{
  if (root == NULL)
    return;

  printf("%d ", root->key);
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}

void postorder_traversal(TreeNode *root)
{
  if (root == NULL)
    return;

  postorder_traversal(root->left);
  postorder_traversal(root->right);
  printf("%d ", root->key);
}

void tree_insert(BST *T, int key)
{
  TreeNode *x = T->root, *y = NULL;
  while (x != NULL)
  {
    y = x;
    if (key < x->key)
      x = x->left;
    else
      x = x->right;
  }

  if (y == NULL)
    T->root = new_node(key);
  else if (key < y->key)
    y->left = new_node(key);
  else
    y->right = new_node(key);
}

BST *constructBST(int array[], int size)
{
  BST *res = new_BST();
  for (int i = 0; i < size; i++)
    tree_insert(res, array[i]);

  return res;
}

bool validate_bst_(TreeNode *root, int min, int max)
{
  if (root == NULL)
    return true;

  if (root->key < min || root->key > max)
    return false;

  return validate_bst_(root->left, min, root->key) &&
         validate_bst_(root->right, root->key, max);
}

bool is_valid_BST(BST *bst)
{
  return validate_bst_(bst->root, INT_MIN, INT_MAX);
}

int inclusive_height_(TreeNode *root)
{
  if (root == NULL)
    return 0;

  return 1 + max(inclusive_height_(root->left), inclusive_height_(root->right));
}

int height(BST *bst)
{
  return inclusive_height_(bst->root) - 1;
}

PBST *new_PBST()
{
  PBST *bst = (PBST *)malloc(sizeof(PBST));
  bst->root = NULL;
  return bst;
}

PersonTreeNode *new_person_node(Person person)
{
  PersonTreeNode *node = (PersonTreeNode *)malloc(sizeof(PersonTreeNode));
  node->key            = person.height;
  node->person         = (Person *)malloc(sizeof(Person));
  *node->person        = person;
  node->left           = NULL;
  node->right          = NULL;
  return node;
}

void pbst_insert(PBST *T, Person person)
{
  PersonTreeNode *x = T->root, *y = NULL;
  int key = person.height;

  while (x != NULL)
  {
    y = x;
    if (key < x->key)
      x = x->left;
    else
      x = x->right;
  }

  if (y == NULL)
    T->root = new_person_node(person);
  else if (key < y->key)
    y->left = new_person_node(person);
  else
    y->right = new_person_node(person);
}

PBST *constructPBST(Person array[], int n)
{
  PBST *pbst = new_PBST();
  for (int i = 0; i < n; i++)
    pbst_insert(pbst, array[i]);

  return pbst;
}

int inclusive_height_pbst_(PersonTreeNode *root)
{
  if (root == NULL)
    return 0;

  return 1 + max(inclusive_height_pbst_(root->left),
                 inclusive_height_pbst_(root->right));
}

int height_pbst(PBST *pbst)
{
  return inclusive_height_pbst_(pbst->root) - 1;
}

TraversalPair tree_traversal_array[2001];
int p_index = 0, q_index = 0, depth = 0, array_pos = 0;
bool found_p = false, found_q = false;

void build_tree_traversal(PersonTreeNode *root, int id_p, int id_q)
{
  if (root == NULL)
    return;

  ++depth;
  tree_traversal_array[array_pos].id    = root->person->id;
  tree_traversal_array[array_pos].depth = depth;
  array_pos++;

  if (root->person->id == id_q && !found_q)
  {
    found_q = true;
    q_index = array_pos - 1;
  }

  if (root->person->id == id_p && !found_p)
  {
    found_p = true;
    p_index = array_pos - 1;
  }

  build_tree_traversal(root->left, id_p, id_q);
  tree_traversal_array[array_pos].id    = root->person->id;
  tree_traversal_array[array_pos].depth = depth;
  array_pos++;
  depth--;
  build_tree_traversal(root->left, id_p, id_q);
}

int LCA(PBST *pbst, int id_p, int id_q)
{
  p_index   = 0;
  q_index   = 0;
  depth     = 0;
  array_pos = 0;
  found_p   = false;
  found_q   = false;

  build_tree_traversal(pbst->root, id_p, id_q);
  if (p_index > q_index)
    swap(p_index, q_index);

  int min_depth = INT_MAX;
  int res;
  for (int i = p_index; i < q_index; i++)
  {
    if (tree_traversal_array[i].depth < min_depth)
    {
      res       = tree_traversal_array[i].id;
      min_depth = tree_traversal_array[i].depth;
    }
  }

  return res;
}

TreeNode *prev = NULL;

void flatten_dfs_(TreeNode *root)
{
  if (root == NULL)
    return;

  flatten_dfs_(root->right);
  flatten_dfs_(root->left);
  root->right = prev;
  root->left  = NULL;
  prev        = root;
}

void flatten(BST *bst)
{
  prev = NULL;
  flatten_dfs_(bst->root);
}
