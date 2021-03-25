#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

typedef struct Address {
  int streetNumber;
  char* streetName;
  char* suburb;
  int postcode;
} Address_t;

typedef struct LinkedList {
  Address_t* address;
  struct LinkedList* next;
} LinkedList_t;

typedef struct BinaryTree {
  int value;
  struct BinaryTree* left;
  struct BinaryTree* right;
} BinaryTree_t;

void insert_to_binary_tree(BinaryTree_t* tree, int value){
  if(tree->value == NULL) {
    tree->value = value;
    tree->left = NULL;
    tree->right = NULL;

    return;
  }

  BinaryTree_t* current = tree;

  BinaryTree_t* item = (BinaryTree_t*)malloc(sizeof(BinaryTree_t));
  item->value = value;
  item->left = NULL;
  item->right = NULL;

  while(current!=NULL){
    if(current->value <= value) {
      if(current->right == NULL) {
        current->right = item;
      }

      current = current->right;
    } else {
      if(current->left == NULL) {
        current->left = item;
      }

      current = current->left;
    }
  }
}


Address_t* create_new_item(int streetNumber, char* streetName, char* suburb, int postcode){
  Address_t* address = (Address_t*)malloc(sizeof(Address_t));

  address->streetNumber = streetNumber;
  address->streetName = streetName;
  address->suburb = suburb;
  address->postcode = postcode;

  return address;
}

void insert_to_list(LinkedList_t* head, Address_t* address){
  if(head->address == NULL) {
    head->address = address;
  }

  LinkedList_t* current = head;

  while(current->next != NULL) {
    current = current->next;
  }

  current->next = (LinkedList_t*)malloc(sizeof(LinkedList_t));
  current->next->address = address;
  current->next->next = NULL;
}


void insert_to_list_sorted(LinkedList_t* head, Address_t* address){
  if(head->address == NULL) {
    head->address = address;
  }

  LinkedList_t* current = head;
  LinkedList_t* prev = head;

  while(current->next != NULL) {
    if(current->address->streetNumber >= address->streetNumber) {
      // Keep going, you haven't found the spot yet
      prev = current;
      current = current->next;
    } else {
      // Current value you are looking at in the list
      // is greater than the value you are trying to add
      // So, the value you are trying to add
      // Should come from the current value you are looking at right now in the list

      // Make sure 
      // 1. the previous value we looked at in the list points to the new value we are adding
      // 2. the new value we are adding needs to point to the current value we are looking at in the list
      // 3. the current value we are looking at in the list does not change
      LinkedList_t* newItem = (LinkedList_t*)malloc(sizeof(LinkedList_t));
      newItem->next = NULL;
      newItem->address = address;
      prev->next = newItem;
      newItem->next = current;

      break;
    }

 
   // I didn't get to add, just add it to the last of the list now
    printf("I am a log statement that is needed\n");
  }
}

void print_address(Address_t* address){
    printf("%d %s %s %d\n", 
    address->streetNumber,
    address->streetName,
    address->suburb,
    address->postcode);
}

void print_list(LinkedList_t* list) {
  while(list != NULL && list->address != NULL) {
    print_address(list->address);
    list = list->next;
  }
}

int
main(int argc, char** argv){
  /*
  LinkedList_t* addresses = (LinkedList_t*)malloc(sizeof(LinkedList_t));
  addresses->address = create_new_item(66, "Royal Parade", "Parkville", 3052);

  printf("%d %s %s %d\n", 
    addresses->address->streetNumber,
    addresses->address->streetName,
    addresses->address->suburb,
    addresses->address->postcode);

  addresses->next = (LinkedList_t*)malloc(sizeof(LinkedList_t));
  addresses->next->address = create_new_item(37, "Kent Grove", "Caulfield North", 3161);

    printf("%d %s %s %d\n", 
    addresses->next->address->streetNumber,
    addresses->next->address->streetName,
    addresses->next->address->suburb,
    addresses->next->address->postcode);
  */

  LinkedList_t* head = (LinkedList_t*)malloc(sizeof(LinkedList_t));
  head->address = NULL;
  head->next = NULL;
  insert_to_list(head, create_new_item(66, "Royal Parade", "Parkville", 3052));
  insert_to_list(head, create_new_item(37, "Kent Grove", "Caulfield North", 3161));

  print_address(head->address);

  print_list(head);

  return 0;
}