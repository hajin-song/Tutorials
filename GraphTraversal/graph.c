#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph* create_empty_graph() {
    Graph* g = malloc(sizeof(Graph));

    g->nodes = malloc(sizeof(NodeList));
    g->edges = malloc(sizeof(EdgeList));

    g->nodes->current = NULL;
    g->nodes->next = NULL;
    
    g->edges->current = NULL;
    g->edges->next = NULL;

    return g;
}

Node* create_node(char* identifier) {
    Node* node = malloc(sizeof(Node));

    node->identifier = identifier;

    return node;
}

Edge* create_edge(char* node_one_id, char* node_two_id) {
    Edge* edge = malloc(sizeof(Edge));

    edge->node_one_id = node_one_id;
    edge->node_two_id = node_two_id;

    return edge;
}

void insert_node(Graph* g, Node* node) {
    NodeList* last_node = g->nodes;

    // printf("Inserting node, %s...\n", node->identifier);

    if(last_node->current == NULL) {
        last_node->current = node;

        return;
    }

    // printf("First node right now is %s...\n", last_node->current->identifier);

    while(last_node->next != NULL) {
        last_node = last_node->next;
    }

    // printf("Last node right now is %s...\n", last_node->current->identifier);
    // printf("What after next? %d...\n\n", last_node->next == NULL);

    last_node->next = malloc(sizeof(NodeList));
    last_node->next->current = node;
    last_node->next->next = NULL;
}

void insert_edge(Graph* g, Edge* edge) {
    EdgeList* last_edge = g->edges;

    if(last_edge->current == NULL) {
        last_edge->current = edge;

        return;
    }

    while(last_edge->next != NULL) {
        last_edge = last_edge->next;
    }

    last_edge->next = malloc(sizeof(EdgeList));
    last_edge->next->current = edge;
    last_edge->next->next = NULL;
}

void print_graph(Graph* g) {
    NodeList* current_node = g->nodes;
    EdgeList* current_edge = g->edges;

    printf("Printing Nodes in the Graph...\n");

    while(current_node != NULL && current_node->current != NULL) {
        printf("\t%s\n", current_node->current->identifier);

        current_node = current_node->next;
    }

    printf("Printing Edges in the Graph...\n");

    while(current_edge != NULL && current_edge->current != NULL) {
        printf("\tbetween %s and %s\n", current_edge->current->node_one_id, current_edge->current->node_two_id);

        current_edge = current_edge->next;
    }


}