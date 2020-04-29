#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"

#define LIST_SIZE 100

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

  for(int index = 0 ; index < LIST_SIZE ; index++) {
    printf("%d, ", list[index]);
  }

  quick_sort(list, 0, LIST_SIZE-1);
  printf("\n\n\n");

  for(int index = 0 ; index < LIST_SIZE ; index++) {
    printf("%d, ", list[index]);
  }

  printf("\n");

  free(list);
  return(0);
}
