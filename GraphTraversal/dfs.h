#ifndef DFS_HEADER
#define DFS_HEADER
#include "graph.h"

#define QUEUE_SIZE 255

typedef struct Queue {
    char** items;
    int size;
} Queue;

VisitList* dfs(Graph*, char*);

#endif