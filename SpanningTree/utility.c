#include <stdlib.h>
#include "graph.h"
#include "utility.h"

void mark_as_visited(VisitList* visit_list, char* node_id) {
    VisitList* current = visit_list;

    if(visit_list->node_id == NULL) {
        visit_list->node_id = node_id;

        return;
    }

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = malloc(sizeof(VisitList));
    current->next->node_id = node_id;
    current->next->next = NULL;
}

int is_visited(VisitList* visit_list, char* node_id) {
    VisitList* current = visit_list;

    while(current->node_id != NULL) {
        if(current->node_id == node_id) {
            return 1;
        }

        current = current->next;

        if(current == NULL) {
            break;
        }
    }

    return 0;
}

void free_visited_list(VisitList* visit_list) {
    while(visit_list != NULL) {
        VisitList* to_free = visit_list;
        visit_list = visit_list->next;
        free(to_free);
    }
}