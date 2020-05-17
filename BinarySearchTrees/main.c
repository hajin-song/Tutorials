#include <stdio.h>
#include "bst.h"
#include "avl.h"

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


  Node_Avl* avl_tree = NULL; 
  
  /* Constructing tree given in the above figure */
  avl_tree = insert_avl(avl_tree, 10); 
  avl_tree = insert_avl(avl_tree, 20); 
  avl_tree = insert_avl(avl_tree, 30); 
  avl_tree = insert_avl(avl_tree, 40); 
  avl_tree = insert_avl(avl_tree, 50); 
  avl_tree = insert_avl(avl_tree, 25); 

  printf("Preorder traversal of the constructed AVL"
         " tree is \n"); 
  preOrder(avl_tree); 

  printf("\n");

  return(0);
}
