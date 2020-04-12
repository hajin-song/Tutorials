#ifndef PRIM_HEADER
#define PRIM_HEADER
#include "graph.h"

typedef struct QueueItem {
  char* node;
  int cost;
} QueueItem;

typedef struct PriorityQueue {
    QueueItem* queue_item;
    int max_size;
    int item_count;
} PriorityQueue;

typedef struct MinimumSpanningTreeNode {
  char* current;
  char* from;
  int cost;
} MinimumSpanningTreeNode;

typedef struct MinimumSpanningTree {
  MinimumSpanningTreeNode* current;
  struct MinimumSpanningTree* next;
} MinimumSpanningTree;


PriorityQueue* create_empty_queue();
void push(PriorityQueue*, int, char*);
char* pop(PriorityQueue*);
MinimumSpanningTree* prim(Graph*, char*);
void free_tree(MinimumSpanningTree*);
#endif