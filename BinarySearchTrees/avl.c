#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "avl.h"

void preOrder(Node_Avl* root) 
{ 
    if(root != NULL) 
    { 
        printf("%d ", root->value); 
        preOrder(root->left); 
        preOrder(root->right); 
    } 
} 

int max(Node_Avl* left, Node_Avl* right) {
  if(left == NULL && right == NULL) {
    return -1;
  }

  if(left == NULL) {
    return right->height;
  }

  if(right == NULL) {
    return left->height;
  }

  if(left->height < right->height) {
    return right->height;
  }

  return left->height;
}

Node_Avl* create_node_avl(int value) {
  Node_Avl* node = (Node_Avl*)malloc(sizeof(Node_Avl));
  node->value = value;
  node->left = NULL;
  node->right = NULL;
  node->height = 0;

  return node;
}

int calculate_node_balance(Node_Avl* node) {
  int left_height = -1, right_height = -1;

  if(node->right != NULL) {
    right_height = node->right->height;
  }

  if(node->left != NULL) {
    left_height = node->left->height;
  }

  return left_height - right_height;
}

Node_Avl* left_rotate(Node_Avl* node) {
  Node_Avl* right_child = node->right;
  Node_Avl* right_child_left_child = right_child->left;

  right_child->left = node;
  node->right = right_child_left_child;
  
  node->height = max(node->left, node->right) + 1; 
  right_child->height = max(right_child->left, right_child->right) + 1;

  return right_child;
}

Node_Avl* right_rotate(Node_Avl* node) {
  Node_Avl* left_child = node->left;
  Node_Avl* left_child_right_child = left_child->right;

  left_child->right = node;
  node->left = left_child_right_child;
  
  node->height = max(node->left, node->right) + 1; 
  left_child->height = max(left_child->left, left_child->right) + 1;

  return left_child;
}

Node_Avl* insert_avl(Node_Avl* node, int value) {
  if(node == NULL) {
    return create_node_avl(value);
  }

  if(node->value < value) {
    node->right = insert_avl(node->right, value);
  } else if(node->value > value) {
    node->left = insert_avl(node->left, value);
  } else {
    return node;
  }

  node->height = max(node->left, node->right) + 1;
  int node_balance = calculate_node_balance(node);
  printf("%d %d\n", node->value, node_balance);
  if(node_balance > 1 && node->left->value > value) {
    return right_rotate(node);
  }
  
  if(node_balance < -1 && node->right->value < value) {
    printf("foooz\n");
    return left_rotate(node);
  }

  if(node_balance > 1 && node->left->value < value) {
    node->left = left_rotate(node->left);
    return right_rotate(node);
  }

  if(node_balance < -1 && node->right->value > value) {
    printf("foobar\n");
    node->right = right_rotate(node->right);
    printf("meep\n");
    return left_rotate(node);
  }

  return node;
}
