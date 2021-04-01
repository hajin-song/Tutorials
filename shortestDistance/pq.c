#include <stdlib.h>
#include <stdio.h>
#include "pq.h"

PriorityQueue* create_empty_queue() {
  PriorityQueue* queue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
  queue->items = (PriorityQueueItem**)malloc(sizeof(PriorityQueueItem*) * 100);
  queue->size = 0;

  return queue;
}

void push(PriorityQueue* pq, int identifier, int cost) {
  int q_index = pq->size;
  PriorityQueueItem* item = (PriorityQueueItem*)malloc(sizeof(PriorityQueueItem));
  item->identifier = identifier;
  item->cost = cost;

  if (pq->size == 0){
    pq->items[1] = item;
    pq->size++;

    return;
  }

  int current_index = pq->size + 1;

  while(current_index > 1) {
    int parent_index = current_index / 2;

    if(pq->items[parent_index]->cost > item->cost) {
      pq->items[current_index] = pq->items[parent_index];
      current_index = parent_index;
    } else {
      break;
    }
  }

  pq->items[current_index] = item;
  pq->size++;
}

PriorityQueueItem* pop(PriorityQueue* pq) {
  if(pq->size <= 0) {
    return NULL;
  }

  PriorityQueueItem* item = pq->items[1];
  pq->size--;

  int current_index = 1;

  while(current_index != pq->size + 1) {
    int swap_index = pq->size + 1;
    int child_index = current_index * 2;

    // At this point, we do the comparison of children
    if(child_index <= pq->size && pq->items[child_index]->cost < pq->items[swap_index]->cost) {
      swap_index = child_index;
    }

    if(child_index + 1 <= pq->size && pq->items[child_index + 1]->cost < pq->items[swap_index]->cost) {
      swap_index = child_index + 1;
    }

    pq->items[current_index] = pq->items[swap_index];
    current_index = swap_index;
  }

  return item;
}

void print_queue(PriorityQueue* pq) {
  for(int q_index = 0 ; q_index < pq->size ; q_index++) {
    printf(" %d ", pq->items[q_index+1]->identifier);
  }
}