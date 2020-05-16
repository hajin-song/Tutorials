#ifndef BST_HEADER
#define BST_HEADER

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Tree {
  Node* head;
} Tree;

Tree* create_bst();
void insert_to_bst(Tree*, int);
Node* search_bst(Tree*, int);

#endif