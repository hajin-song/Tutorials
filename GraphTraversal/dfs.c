#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "graph.h"
#include "dfs.h"

Stack* create_empty_stack();
void add_to_stack(Stack*, char*);
char* pop_from_stack(Stack*);

VisitList* dfs(Graph* g, char* node_id) {
    VisitList* visit_list = malloc(sizeof(VisitList));
    Stack* s = create_empty_stack();

    add_to_stack(s, node_id);

    while(s->size > 0) {
        char* visiting_node = pop_from_stack(s);

        if(!is_visited(visit_list, visiting_node)) {
            mark_as_visited(visit_list, visiting_node);

            EdgeList* neighbours = get_node_neighbours(g, visiting_node);

            while(neighbours->current != NULL) {
                if(strcmp(neighbours->current->node_one_id, visiting_node) == 0) {
                    if(!is_visited(visit_list, neighbours->current->node_two_id)){
                        add_to_stack(s, neighbours->current->node_two_id);
                    }
                } else {
                    if(!is_visited(visit_list, neighbours->current->node_one_id)){
                        add_to_stack(s, neighbours->current->node_one_id);
                    }
                }
                neighbours = neighbours->next;
            }
        }
    }

    return visit_list;
}

Stack* create_empty_stack(){
    Stack* s = malloc(sizeof(Stack));
    s->items = malloc(sizeof(char*) * STACK_SIZE);
    s->size = 0;

    return s;
}

void add_to_stack(Stack* s, char* node_id) {
    s->items[s->size++] = node_id;
}

char* pop_from_stack(Stack* s) {
    char* item = s->items[s->size-1];
    s->items[--s->size] = NULL;

    return item;
}