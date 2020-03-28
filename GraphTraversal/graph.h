#ifndef GRAPH_HEADER
#define GRAPH_HEADER

#define MAX_NODE_IDENTIFIER 255

typedef struct Node {
    char* identifier;
} Node;

typedef struct Edge {
    char* node_one_id;
    char* node_two_id;
} Edge;

typedef struct NodeList {
    Node* current;
    struct NodeList* next;
} NodeList;

typedef struct EdgeList {
    Edge* current;
    struct EdgeList* next;
} EdgeList;

typedef struct Graph {
    NodeList* nodes;
    EdgeList* edges;
} Graph;

Graph* create_empty_graph();
Node* create_node(char*);
Edge* create_edge(char*, char*);
void insert_node(Graph*, Node*);
void insert_edge(Graph*, Edge*);
void print_graph(Graph*);
EdgeList* get_node_neighbours(Graph*, char*);
#endif