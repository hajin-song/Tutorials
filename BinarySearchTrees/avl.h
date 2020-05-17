#ifndef AVL_HEADER
#define AVL_HEADER

typedef struct Node_Avl {
    int value;
    struct Node_Avl* left;
    struct Node_Avl* right;
    int height;
} Node_Avl;

void preOrder(Node_Avl*);
Node_Avl* insert_avl(Node_Avl*, int);

#endif