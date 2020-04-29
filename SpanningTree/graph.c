#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"

int node_exists(Graph*, char*);

Graph* create_empty_graph() {
    Graph* g = malloc(sizeof(Graph));

    g->nodes = (NodeList*)malloc(sizeof(NodeList));
    g->edges = (EdgeList*)malloc(sizeof(EdgeList));

    g->nodes->current = NULL;
    g->nodes->next = NULL;
    
    g->edges->current = NULL;
    g->edges->next = NULL;

    return g;
}

Node* create_node(char* identifier) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->identifier = identifier;

    return node;
}

Edge* create_edge(char* node_one_id, char* node_two_id, int weight) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));

    edge->node_one_id = node_one_id;
    edge->node_two_id = node_two_id;
    edge->weight = weight;

    return edge;
}

void insert_node(Graph* g, Node* node) {
    NodeList* last_node = g->nodes;
    
    if(last_node->current == NULL) {
        last_node->current = node;

        return;
    }

    while(last_node->next != NULL) {
        last_node = last_node->next;
    }

    last_node->next = (NodeList*)malloc(sizeof(NodeList));
    last_node->next->current = node;
    last_node->next->next = NULL;
}

void insert_edge(Graph* g, Edge* edge) {
    if(node_exists(g, edge->node_one_id) == 0 && node_exists(g, edge->node_two_id) == 0) {
        printf("Nodes connected by edge does not exist in the graph.\n");

        return;
    }

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

    while(current_node != NULL && current_node->current != NULL) {
        printf("Node named %s\n", current_node->current->identifier);
        current_node = current_node->next;
    }

    while(current_edge != NULL && current_edge->current != NULL) {
        printf("Edge between %s and %s with cost of %d\n", current_edge->current->node_one_id, current_edge->current->node_two_id, current_edge->current->weight);
        current_edge = current_edge->next;
    }
}

EdgeList* get_node_neighbours(Graph* g, char* node_id) {
    EdgeList* neighbours = (EdgeList*)malloc(sizeof(EdgeList));
    EdgeList* current_neighbours = neighbours;

    EdgeList* current_edge = g->edges;

    while(current_edge != NULL && current_edge->current != NULL) {
        if (strcmp(current_edge->current->node_one_id, node_id) == 0|| strcmp(current_edge->current->node_two_id, node_id) == 0) {
            current_neighbours->current = current_edge->current;
            current_neighbours->next = (EdgeList*)malloc(sizeof(EdgeList));
            current_neighbours = current_neighbours->next;
        }

        current_edge = current_edge->next;
    }

    return neighbours;
}

Node* find_node(Graph* g, char* node_id) {
    NodeList* current_node = g->nodes;

    while(current_node != NULL && current_node->current != NULL) {
        if(strcmp(current_node->current->identifier, node_id) == 0) {
            return current_node->current;
        }

        current_node = current_node->next;
    }

    return NULL;
}

int node_exists(Graph* g, char* node_id) {
    NodeList* current_node = g->nodes;

    while(current_node != NULL && current_node->current != NULL) {
        if(strcmp(current_node->current->identifier, node_id) == 0) {
            return 1;
        }

        current_node = current_node->next;
    }

    return 0;
}

void free_graph(Graph* g) {
    NodeList* current_node = g->nodes;
    EdgeList* current_edge = g->edges;

    while(current_node != NULL && current_node->current != NULL) {
        NodeList* to_free = current_node;
        current_node = current_node->next;
        free(to_free->current);
        free(to_free);
    }

    while(current_edge != NULL && current_edge->current != NULL) {
        EdgeList* to_free = current_edge;
        current_edge = current_edge->next;
        free(to_free->current);
        free(to_free);
    }
}