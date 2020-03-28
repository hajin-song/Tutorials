#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "utility.h"
#include "dfs.h"

Queue* create_empty_queue();
void enqueue(Queue*, char*);
char* dequeue(Queue*);

VisitList* dfs(Graph* g, char* node_id) {
    VisitList* visit_list = malloc(sizeof(VisitList));
    Queue* q = create_empty_queue();

    enqueue(q, node_id);

    while(q->size > 0) {
        char* visiting_node = dequeue(q);

        if(!is_visited(visit_list, visiting_node)) {
            mark_as_visited(visit_list, visiting_node);

            EdgeList* neighbours = get_node_neighbours(g, visiting_node);

            while(neighbours->current != NULL) {
                if(strcmp(neighbours->current->node_one_id, visiting_node) == 0) {
                    if(!is_visited(visit_list, neighbours->current->node_two_id)){
                        enqueue(q, neighbours->current->node_two_id);
                    }
                } else {
                    if(!is_visited(visit_list, neighbours->current->node_one_id)){
                        enqueue(q, neighbours->current->node_one_id);
                    }
                }
                neighbours = neighbours->next;
            }
        }
    }

    return visit_list;
}

Queue* create_empty_queue(){
    Queue* q = malloc(sizeof(Queue));
    q->items = malloc(sizeof(char*) * QUEUE_SIZE);
    q->size = 0;

    return q;
}

void enqueue(Queue* q, char* node_id) {
    q->items[q->size++] = node_id;
}

char* dequeue(Queue* q) {
    char* item = q->items[0];

    for(int i = 1  ; i < q->size ; i++) {
        q->items[i-1] = q->items[i];
    }

    q->size -= 1;

    return item;
}