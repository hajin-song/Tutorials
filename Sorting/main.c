#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"
#include "mergeSort.h"

#define LIST_SIZE 10

void seed_random(int* list){
    int random_num, count;

    srand(time(NULL));

    for(count = 0; count < LIST_SIZE ; count++) {
        list[count] = rand() % 99;
    }
}

int main() {
  int* list = (int*)malloc(LIST_SIZE * sizeof(int));
  seed_random(list);

  for(int i = 0 ; i < LIST_SIZE ; i++) {
    printf("%d ", list[i]);
  }

  printf("\n\n\n");

  merge_sort(list, 0, LIST_SIZE-1);

  for(int i = 0 ; i < LIST_SIZE ; i++) {
    printf("%d ", list[i]);
  }

  printf("\n");

  printf("Debug purpose statement\n");

  free(list);
  return(0);
}
