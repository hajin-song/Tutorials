#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "utility.h"
#include "prim.h"

MinimumSpanningTree* initialise_tree(Graph*, char*);
MinimumSpanningTreeNode* find_node_in_tree(MinimumSpanningTree*, char*);

MinimumSpanningTree* prim(Graph* g, char* start_node_id) {
  VisitList* visit_list = malloc(sizeof(VisitList));
  PriorityQueue* q = create_empty_queue();
  MinimumSpanningTree* mst = initialise_tree(g, start_node_id);

  MinimumSpanningTreeNode* current_node = find_node_in_tree(mst, start_node_id);

  push(q, current_node->cost, current_node->current);

  while(q->item_count > 0) {
    current_node = find_node_in_tree(mst, pop(q));

    if(is_visited(visit_list, current_node->current)) {
      continue;
    }

    mark_as_visited(visit_list, current_node->current);

    EdgeList* current_node_edges = get_node_neighbours(g, current_node->current);

    while(current_node_edges != NULL && current_node_edges->current != NULL) {
      Edge* current_edge = current_node_edges->current;
      int current_edge_cost = current_edge->weight;
      char* neighbour_node_id;
      current_node_edges = current_node_edges->next;
      
      if(strcmp(current_edge->node_one_id, current_node->current) == 0) {
        neighbour_node_id = current_edge->node_two_id;
      } else {
        neighbour_node_id = current_edge->node_one_id;
      }

      if(is_visited(visit_list, neighbour_node_id)) {
        continue;
      }

      MinimumSpanningTreeNode* neighbour_node_in_tree = find_node_in_tree(mst, neighbour_node_id);

      if(current_edge_cost < neighbour_node_in_tree->cost) {
        neighbour_node_in_tree->cost = current_edge_cost;
        neighbour_node_in_tree->from = current_node->current;
        push(q, current_edge_cost, neighbour_node_id);
      }
    }
  }

  free(q->queue_item);
  free(q);
  free_visited_list(visit_list);

  return mst;
}

PriorityQueue* create_empty_queue() {
   PriorityQueue* queue = malloc(sizeof(PriorityQueue));

    queue->max_size = 4;
    queue->item_count = 0;
    queue->queue_item = malloc(sizeof(QueueItem) * 4);

   return queue;
}

void push(PriorityQueue* q, int cost, char* node_id) {
  if(q->item_count + 1 >= q->max_size) {
    q->max_size = q->max_size * 2;
    q->queue_item = (QueueItem*)realloc(q->queue_item, q->max_size * sizeof(QueueItem));
  }

  int cur_index = q->item_count + 1;
  int parent_index = q->item_count / 2;

  while(cur_index > 1 && q->queue_item[parent_index].cost > cost) {
    q->queue_item[cur_index] = q->queue_item[parent_index];
    cur_index = parent_index;
    parent_index = parent_index/2;
  }

  q->queue_item[cur_index].cost = cost;
  q->queue_item[cur_index].node = node_id;
  q->item_count++;
}

char* pop(PriorityQueue* q) {
  if(q->item_count <= 0) {
    return NULL;
  }

  QueueItem top_item = q->queue_item[1];
  q->item_count--;

  int current_index = 1;

  while(current_index != q->item_count+1) {
    int current_swap_index = q->item_count + 1;
    int current_child_index = current_index * 2;

    if(current_child_index <= q->item_count && q->queue_item[current_child_index].cost < q->queue_item[current_swap_index].cost) {
      current_swap_index = current_child_index;
    }

    if(current_child_index + 1 <= q->item_count && q->queue_item[current_child_index+1].cost < q->queue_item[current_swap_index].cost) {
      current_swap_index = current_child_index + 1;
    }

    q->queue_item[current_index] = q->queue_item[current_swap_index];
    current_index = current_swap_index;
  }

  return top_item.node;
}

MinimumSpanningTree* initialise_tree(Graph* g, char* start_node_id) {
  MinimumSpanningTree* mst = (MinimumSpanningTree*)malloc(sizeof(MinimumSpanningTree));
  MinimumSpanningTree* mst_head = mst;

  NodeList* node = g->nodes;

  while(node!=NULL) {
    mst->current = (MinimumSpanningTreeNode*)malloc(sizeof(MinimumSpanningTreeNode));
    mst->current->current = node->current->identifier;

    if(strcmp(start_node_id, node->current->identifier) == 0) {
      mst->current->cost = 0;
    } else {
      mst->current->cost = 9999;
    }

    mst->next = (MinimumSpanningTree*)malloc(sizeof(MinimumSpanningTree));
    mst = mst->next;
    node = node->next;
  }

  return mst_head;
}

void free_tree(MinimumSpanningTree* mst) {
  while(mst != NULL && mst->current != NULL) {
    MinimumSpanningTree* to_free = mst;
    mst = mst->next;
    free(mst->current);
    free(mst);
  }
}

MinimumSpanningTreeNode* find_node_in_tree(MinimumSpanningTree* mst, char* node_id) {
  while(mst != NULL && mst->current != NULL) {
    MinimumSpanningTree* to_free = mst;
    
    if(strcmp(mst->current->current, node_id) == 0) {
      return mst->current;
    }

    mst = mst->next;
  }

  return NULL;
}