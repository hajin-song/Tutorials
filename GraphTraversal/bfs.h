#ifndef BFS_HEADER
#define BFS_HEADER
#include "graph.h"

#define QUEUE_SIZE 255

typedef struct Queue {
    char** items;
    int size;
} Queue;

VisitList* bfs(Graph*, char*);

#endif