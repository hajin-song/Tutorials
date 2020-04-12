#ifndef UTILITY_HEADER
#define UTILITY_HEADER

#include "graph.h"

typedef struct VisitList {
    char* node_id;
    struct VisitList* next;
} VisitList;

void mark_as_visited(VisitList*, char*);
int is_visited(VisitList*, char*);

#endif