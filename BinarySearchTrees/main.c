#include <stdio.h>
#include "bst.h"

int main() {
  printf("BST\n");

  Tree* tree = create_bst();
  printf("buzzbazz\n");

  insert_to_bst(tree, 1);
  insert_to_bst(tree, 5);
  insert_to_bst(tree, 4);
  insert_to_bst(tree, 3);
  insert_to_bst(tree, 8);
  insert_to_bst(tree, 7);

  printf("foobar\n");
  printf("%d\n", search_bst(tree, 1)->value);
  printf("%d\n", search_bst(tree, 3)->value);
  printf("%d\n", search_bst(tree, 8)->value);
  printf("%d\n", search_bst(tree, 7)->value);

  return(0);
}
