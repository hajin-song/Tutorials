#ifndef PRIORITY_QUEUE_HEADER
#define PRIORITY_QUEUE_HEADER

typedef struct PriorityQueueItem {
  int cost;
  int identifier;
} PriorityQueueItem;

typedef struct PriorityQueue {
  PriorityQueueItem** items;
  int size;
} PriorityQueue;


PriorityQueue* create_empty_queue();
void push(PriorityQueue*, int, int);
PriorityQueueItem* pop(PriorityQueue*);
void print_queue(PriorityQueue*);

#endif