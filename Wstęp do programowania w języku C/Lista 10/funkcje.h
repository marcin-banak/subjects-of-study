#ifndef GRAFY_FUNKCJE_H
#define GRAFY_FUNKCJE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES_NUMBER 1000000
#define MAX_VERTICES_NUMBER 1000000
// GRAFY SKIEROWANE

typedef struct Node {  // pojedynczy wierzcholek
    int value; // numer wierzcholka
    struct Node *next;  // wskaznik do listy sasiadow
} Node;

typedef struct Graph {  // graf
    int nodes_num; // ilosc wierzcholkow
    Node **adjacency_lists; // tablica lista sasiedztwa
} Graph;

Node *newNode(int num); // tworzenie nowego wierzcholka o numerze num
Graph *newGraph(int n); // tworzenie nowego grafu o n wierzcholkach
void addEdge(Graph *graph, int a, int b); // dodanie krawedzi z a do b
void printGraph(Graph *graph); // wypisywanie grafu
void freeGraph(struct Graph* graph); // zwolnienie pamieci

void DFS(Graph *graph, int num, int visited[]); // przeszukiwanie DFS od wierzchołka num
int all_visited(int n, const int visited[n]);
int CountConnectedComponents(Graph *graph, int visited[]);

#endif //GRAFY_FUNKCJE_H
