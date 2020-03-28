#include <stdio.h>
#include "graph.h"

int main() {
    printf("Hello World\n");
    
    Graph* g = create_empty_graph();

    insert_node(g, create_node("Melbourne"));
    insert_node(g, create_node("Hawthorne"));
    insert_node(g, create_node("Auburn"));
    insert_node(g, create_node("Caulfield North"));
    insert_node(g, create_node("St. Kilda East"));

    insert_edge(g, create_edge("Melbourne", "Hawthorne"));
    insert_edge(g, create_edge("Hawthorne", "Auburn"));
    insert_edge(g, create_edge("Melbourne", "St. Kilda East"));
    insert_edge(g, create_edge("St. Kilda East", "Caulfield North"));

    print_graph(g);

    return(0);
}