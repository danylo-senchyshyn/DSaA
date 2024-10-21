#include <stdio.h>
#include "err.h"
#include "graph.h"
#include "lqueue.h"

struct GraphRecord
{
      int adj[max][max];
      int visited[max];
      int nodes;
};

Graph CreateGraph(int NodesCount) {
    Graph G = malloc(sizeof(struct GraphRecord));
    if (G == NULL) Error("Out of space!");

    G->nodes = NodesCount;

    for (int i = 0; i < NodesCount; i++) {
        for (int j = 0; j < NodesCount; j++) {
            G->adj[i][j] = 0;
        }
    }

    for (int i = 0; i < NodesCount; i++) {
        G->visited[i] = 0;
    }

    return G;
}

void DisposeGraph(Graph G) {
    if (G != NULL) {
        free(G);
    }
}

void buildadjm(Graph G) {
    int u, v;
    printf("Введите ребра в формате 'u v' (Ctrl+D для завершения):\n");
    while (scanf("%d %d", &u, &v) == 2) {
        G->adj[u][v] = 1;
        G->adj[v][u] = 1;
    }
}

void printadjm(Graph G) {
    printf("\nМатрица смежности:\n");
    for (int i = 0; i < G->nodes; i++) {
        for (int j = 0; j < G->nodes; j++) {
            printf("%d ", G->adj[i][j]);
        }
        printf("\n");
    }
}

void ClearVisited(Graph G) {
    for (int i = 0; i < G->nodes; i++) {
        G->visited[i] = 0;
    }
}

// 3 stavy - 0 (not found), 1 (opened), 2 (closed)
void dfs(Graph G, int v0) {
    if (G == NULL) {
        Error("Graph is NULL!");
    }
    if (G->nodes <= 0) {
        Error("Graph has no nodes!");
    }
    if (v0 < 0 || v0 >= G->nodes) {
        Error("Starting node is out of bounds!");
    }
    if (G->visited[v0] == 1) {
        return;
    }
    if (G->visited[v0] == 2) {
        return;
    }

    printf("Посещаем узел %d\n", v0);
    G->visited[v0] = 1;

    for (int i = 0; i < G->nodes; i++) {
        if (G->adj[v0][i] == 1 && G->visited[i] == 0) {
            dfs(G, i);
        }
    }

    G->visited[v0] = 2;
}

void dfs2(Graph G, int v) {
    printf("The node opened: %d\n", v);

    G->visited[v] = 1;

    for (int w = 0; w < G->nodes; w++) {
        if (G->adj[v][w] == 1 && G->visited[w] == 0) {
            dfs2(G, w);
        }
    }

    G->visited[v] = 2;
}