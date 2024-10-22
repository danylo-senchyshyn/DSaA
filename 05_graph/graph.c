#include <stdio.h>
#include "err.h"
#include "graph.h"
#include "lqueue.h"

struct GraphRecord {
    int adj[max][max];
    int visited[max];
    int nodes;
};

Graph CreateGraph(int NodesCount) {
    Graph G;

    G = malloc(sizeof(struct GraphRecord));
    if (G == NULL) Error("Out of space!!!");

    G->nodes = NodesCount;

    for (int i = 0; i < max; i++) {
        for (int j = 0; j < max; j++) {
            G->adj[i][j] = 0;
        }
        G->visited[i] = 0;
    }

    return G;
}

void DisposeGraph(Graph G) {
    free(G);
}

/* a function to build adjacency matrix of a graph */
void buildadjm(Graph G) {
    int i, j;
    for (i = 0; i < G->nodes; i++)
        for (j = 0; j < G->nodes; j++) {
            printf("enter 1 if there is an edge from %d to %d, otherwise enter 0 \n", i, j);
            scanf("%d", &(G->adj[i][j]));
        }
}

void printadjm(Graph G) {
    int i, j;
    for (i = 0; i < G->nodes; i++) {
        for (j = 0; j < G->nodes; j++)
            printf(" %d", G->adj[i][j]);
        putchar('\n');
    }
}

void ClearVisited(Graph G) {
    int n;
    for (n = 0; n < G->nodes; n++)
        G->visited[n] = 0;
}

// 3 stavy - 0 (not found), 1 (opened), 2 (closed)
void dfs(Graph G, int v0) {
    if (G == NULL) {
        printf("Graph is NULL\n");
        return;
    }
    if (G->nodes <= 0) {
        printf("Graph is empty\n");
        return;
    }
    if (v0 < 0 || v0 >= G->nodes) {
        printf("Invalid starting node\n");
        return;
    }
    ClearVisited(G);
    dfs2(G, v0);  // Рекурсивный вызов функции dfs2
}

void dfs2(Graph G, int v) {
    G->visited[v] = 1;
    printf("Visited: %d\n", v);

    for (int w = 0; w < G->nodes; w++) {
        if (G->adj[v][w] == 1 && G->visited[w] == 0) {
            printf("Edge: %d -> %d\n", v, w);
            dfs2(G, w);
        }
    }
}

void dfsst(Graph G, int v0) {
    if (G == NULL) {
        printf("Graph is NULL\n");
        return;
    }
    if (G->nodes <= 0) {
        printf("Graph is empty\n");
        return;
    }
    if (v0 < 0 || v0 >= G->nodes) {
        printf("Invalid starting node\n");
        return;
    }

    ClearVisited(G);
    printf("Spanning Tree from node %d:\n", v0);
    dfsst2(G, v0);

    for (int i = 0; i < G->nodes; i++) {
        if (G->visited[i] == 0) {
            printf("Spanning Tree from node %d:\n", i);
            dfsst2(G, i);
        }
    }
}

void dfsst2(Graph G, int v) {
    G->visited[v] = 1;
    for (int w = 0; w < G->nodes; w++) {
        if (G->adj[v][w] == 1 && G->visited[w] == 0) {
            printf("Edge (Spanning Tree): %d -> %d\n", v, w);
            dfsst2(G, w);
        }
    }
}

void bfs(Graph G, int start) {
    if (G == NULL) {
        printf("Graph is NULL\n");
        return;
    }
    if (G->nodes <= 0) {
        printf("Graph is empty\n");
        return;
    }
    if (start < 0 || start >= G->nodes) {
        printf("Invalid starting node\n");
        return;
    }

    ClearVisited(G);
    LQueue Q = CreateQueue();
    Enqueue(start, Q);
    G->visited[start] = 1;

    while (!IsEmptyQueue(Q)) {
        int v = Front(Q);
        Dequeue(Q);
        printf("Visited: %d\n", v);

        for (int w = 0; w < G->nodes; w++) {
            if (G->adj[v][w] == 1 && G->visited[w] == 0) {
                printf("Edge: %d -> %d\n", v, w);
                Enqueue(w, Q);
                G->visited[w] = 1;
            }
        }
    }
    RemoveQueue(&Q);
}

void bfsst(Graph G, int v0) {
    if (G == NULL) {
        printf("Graph is NULL\n");
        return;
    }
    if (G->nodes <= 0) {
        printf("Graph is empty\n");
        return;
    }
    if (v0 < 0 || v0 >= G->nodes) {
        printf("Invalid starting node\n");
        return;
    }

    ClearVisited(G);
    printf("Spanning Tree from node %d:\n", v0);
    bfs(G, v0);

    for (int i = 0; i < G->nodes; i++) {
        if (G->visited[i] == 0) {
            printf("Spanning Tree from node %d:\n", i);
            bfs(G, i);
        }
    }
}
