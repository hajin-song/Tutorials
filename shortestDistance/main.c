#include <stdio.h>
#include "pq.h"

int
main(int argc, char** argv) {
  PriorityQueue* pq = create_empty_queue();
  printf("fizz\n");
  push(pq, 1, 1);
  push(pq, 5, 5);
  push(pq, 10, 10);
  push(pq, 2, 2);
  push(pq, 3, 3);
  push(pq, 11, 11);
  push(pq, 14, 14);
  push(pq, 4, 4);

  print_queue(pq);
  printf("\n");

  while(pq->size > 0) {
    printf("popped %d\n", pop(pq)->identifier);
    printf("\t");
    print_queue(pq);
    printf("\n");
  }
}

