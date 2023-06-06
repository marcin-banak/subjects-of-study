#include "funkcje.c"

int main(int argc, const char *argv[])
{
    if (argc==1) 
    {
        fprintf(stderr, "Nie wybrano pliku"); 
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) 
    { 
        fprintf(stderr, "Nie można otworzyc pliku '%s'", argv[1]); 
        return 1; 
    }

    int n, m; // ilość n - wierczhołek, e - krawędź
    fscanf(file, "%d %d", &n, &m);
    Graph *graph = newGraph(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        fscanf(file, "%d %d", &a, &b);
        addEdge(graph, a, b);
    }
    fclose(file);
    printGraph(graph);

    int visited[n];
    memset(visited, 0, sizeof(visited));
    printf("ilosc skladowych spojnosci: %d", CountConnectedComponents(graph, visited));

    freeGraph(graph);
    return 0;
}
