#include "funkcje.h"

Node *newNode(int num) {
    Node *new = malloc(sizeof(Node));
    new->value = num;
    new->next = NULL;
    return new;
}

void addEdge(Graph *graph, int a, int b) {
    struct Node* new = newNode(b);
    struct Node* current = graph->adjacency_lists[a];
    if (current == NULL) {
        graph->adjacency_lists[a] = new; // if there are no edges yet, the new is the first one
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new; // add newNode at the end of the list
    }
}

Graph *newGraph(int n) {
    struct Graph* new_graph = malloc(sizeof(struct Graph));
    new_graph->nodes_num = n;
    new_graph->adjacency_lists = malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++)
        new_graph->adjacency_lists[i] = NULL;
    return new_graph;
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->nodes_num; i++) {
        printf("%d: ", i);
        Node* adjList = graph->adjacency_lists[i];
        while (adjList != NULL) {
            printf("%d ", adjList->value);
            adjList = adjList->next;
        }
        printf("\n");
    }
}

void freeGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->nodes_num; v++) { // przejscie po kazdym wierzcholku grafu
        Node* adjList = graph->adjacency_lists[v];
        Node* temp;
        while (adjList) { // zwolnienie kazdego elementu z listy sasiadow
            temp = adjList;
            adjList = adjList->next;
            free(temp);
        }
    }
    free(graph->adjacency_lists); // zwolnienie pamieci dla tablicy list sasiadow
    free(graph); // zwlonienie pamieci dla samego grafu
}

void DFS(Graph *graph, int num, int visited[]) {
    printf("%d ", num);
    visited[num] = 1;
    Node* current = graph->adjacency_lists[num];
    while (current != NULL) {
        if (visited[current->value] == 0) 
            DFS(graph, current->value, visited);
        current = current->next;
    }
}

int all_visited(int n, const int visited[n]) {
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) return i;
    }
    return -1;
}

int CountConnectedComponents(Graph *graph, int visited[]) {
    int connected_components_num = 0;
    int starting_node = 0;
    while (starting_node != -1) {
        DFS(graph, starting_node, visited);
        printf("\n");
        connected_components_num += 1;
        starting_node = all_visited(graph->nodes_num, visited);
    }
    return connected_components_num;
}
