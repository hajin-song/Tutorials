#include <stdio.h>
#include "graph.h"
#include "utility.h"
#include "dfs.h"
#include "bfs.h"

int main() {
    Graph* g = create_empty_graph();

    insert_node(g, create_node("Melbourne"));
    insert_node(g, create_node("Hawthorne"));
    insert_node(g, create_node("Auburn"));
    insert_node(g, create_node("Caulfield North"));
    insert_node(g, create_node("St. Kilda East"));

    insert_edge(g, create_edge("Melbourne", "Hawthorne"));
    insert_edge(g, create_edge("Hawthorne", "Auburn"));
    insert_edge(g, create_edge("Auburn", "Camberwell"));
    insert_edge(g, create_edge("Camberwell", "Laburnum"));
    insert_edge(g, create_edge("Laburnum", "Blackburn"));
    insert_edge(g, create_edge("Blackburn", "Nunawading"));
    insert_edge(g, create_edge("Nunawading", "Lilydale"));

    insert_edge(g, create_edge("Melbourne", "St. Kilda East"));
    insert_edge(g, create_edge("St. Kilda East", "Caulfield North"));
    insert_edge(g, create_edge("Caulfield North", "Caulfield South"));
    insert_edge(g, create_edge("Caulfield South", "Chaltenham"));
    insert_edge(g, create_edge("Chaltenham", "Brighton"));
    insert_edge(g, create_edge("Brighton", "Elstenwick"));
    insert_edge(g, create_edge("Elstenwick", "Sandringham"));

    print_graph(g);

    VisitList* result = bfs(g, "Melbourne");

    printf("Visited in the order of\n");

    while(result->node_id != NULL) {
        printf("\t%s\n", result->node_id);

        result = result->next;

        if(result == NULL) {
            break;
        }
    }

    return(0);
}
