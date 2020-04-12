#include <stdio.h>
#include "graph.h"
#include "prim.h"

int main() {
    Graph* g = create_empty_graph();

    insert_node(g, create_node("A"));
    insert_node(g, create_node("B"));
    insert_node(g, create_node("C"));
    insert_node(g, create_node("D"));
    insert_node(g, create_node("E"));
    insert_node(g, create_node("F"));

    insert_edge(g, create_edge("A", "B", 5));
    insert_edge(g, create_edge("A", "C", 6));
    insert_edge(g, create_edge("A", "D", 4));
    insert_edge(g, create_edge("B", "C", 1));
    insert_edge(g, create_edge("B", "D", 2));
    insert_edge(g, create_edge("C", "D", 2));
    insert_edge(g, create_edge("C", "E", 5));
    insert_edge(g, create_edge("C", "F", 3));
    insert_edge(g, create_edge("D", "F", 4));
    insert_edge(g, create_edge("E", "F", 4));

    MinimumSpanningTree* mst = prim(g, "A");

    while(mst != NULL && mst->current != NULL) {
      printf("From %s, go to %s with cost of %d\n", mst->current->from, mst->current->current, mst->current->cost);
      mst = mst->next;
    }

    free_graph(g);
    free_tree(mst);
    return(0);
}
