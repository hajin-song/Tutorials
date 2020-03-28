#include <stdio.h>
#include "graph.h"
#include "utility.h"
#include "dfs.h"

int main() {
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

    VisitList* result = dfs(g, "Melbourne");

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