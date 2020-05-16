#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

Node* create_node(int value) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = value;
  node->left = NULL;
  node->right = NULL;

  return node;
}

Tree* create_bst() {
  Tree* bst = (Tree*)malloc(sizeof(Tree));
  bst->head = NULL;

  return bst;
}

void insert_to_bst(Tree* tree, int value) {
  Node* new_node = create_node(value);
  Node* current = tree->head;

  if(current == NULL) {
    tree->head = new_node;

    return;
  }

  while(current != NULL) {
    if (current->value < value) {
      if (current->right == NULL) {
        current->right = new_node;
        return;
      } else {
        current = current->right;
      }
    } else {
      if (current->left == NULL) {
        current->left = new_node;
        return;
      } else {
         current = current->left;
      }
    }
  }
}

Node* search_bst(Tree* tree, int value) {
    Node* current = tree->head;

  if(current == NULL) {
    return NULL;
  }

  while(current != NULL) {
    if (current -> value == value) {
      return current;
    }
    else if (current->value < value) {
      if (current->right == NULL) {
        break;
      } else {
        current = current->right;
      }
    } else {
      if (current->left == NULL) {
        break;
      } else {
        current = current->left;
      }
    }
  }

  return NULL;
}