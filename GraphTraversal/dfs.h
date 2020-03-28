#ifndef DFS_HEADER
#define DFS_HEADER

#define STACK_SIZE 255

typedef struct Stack {
    char** items;
    int size;
} Stack;

VisitList* dfs(Graph*, char*);

#endif