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
    if (NodesCount <= 0 || NodesCount > max) {
        Error("Invalid number of nodes!");
        return NULL;
    }

    Graph G = malloc(sizeof(struct GraphRecord));
    if (G == NULL) Error("Out of space!");

    G->nodes = NodesCount;

    // Инициализация матрицы смежности и массива visited
    for (int i = 0; i < NodesCount; i++) {
        for (int j = 0; j < NodesCount; j++) {
            G->adj[i][j] = 0;
        }
        G->visited[i] = 0;
    }
    return G;
}

void DisposeGraph(Graph G) {
    if (G != NULL) free(G);
}

void buildadjm(Graph G) {
    if (G == NULL) return;

    int i, j;
    for (i = 0; i < G->nodes; i++) {
        for (j = 0; j < G->nodes; j++) {
            printf("enter 1 if there is an edge from %d to %d, otherwise enter 0 \n", i, j);
            scanf("%d", &(G->adj[i][j]));
            if (i == j && G->adj[i][j] != 0) {
                Error("Diagonal values should be zero!");
                return;
            }
            if (G->adj[i][j] < 0) {
                Error("Graph adjacency matrix cannot contain negative values!");
                return;
            }
        }
    }
}

void printadjm(Graph G) {
    if (G == NULL) return;

    for (int i = 0; i < G->nodes; i++) {
        for (int j = 0; j < G->nodes; j++) {
            printf(" %d", G->adj[i][j]);
        }
        putchar('\n');
    }
}

void ClearVisited(Graph G) {
    if (G == NULL) return;

    for (int n = 0; n < G->nodes; n++)
        G->visited[n] = 0;
}

void dfs(Graph G, int v0) {
    if (G == NULL || v0 < 0 || v0 >= G->nodes) {
        Error("Invalid graph or starting node!");
        return;
    }

    for (int i = 0; i < G->nodes; i++) {
        if (G->adj[i][i] != 0 || G->visited[i] < 0 || G->visited[i] > 2) {
            Error("Invalid graph structure or visited values.");
            return;
        }
    }

    ClearVisited(G);
    dfs2(G, v0);
}

void dfs2(Graph G, int v) {
    if (G == NULL || v < 0 || v >= G->nodes) return;

    printf("The node opened: %d\n", v);
    G->visited[v] = 1;

    for (int w = 0; w < G->nodes; w++) {
        if (G->adj[v][w] == 1 && G->visited[w] == 0) {
            dfs2(G, w);
        }
    }
    G->visited[v] = 2;
}

int find_not_visited_node(Graph G) {
    if (G == NULL) return -1;

    for (int i = 0; i < G->nodes; i++) {
        if (G->visited[i] == 0) return i;
    }
    return -1;
}

void dfsst(Graph G, int v0) {
    if (G == NULL || G->adj == NULL || v0 < 0 || v0 >= G->nodes) {
        Error("Invalid graph or starting node!");
        return;
    }

    ClearVisited(G);

    int not_visited_node = v0;
    do {
        dfsst2(G, not_visited_node);
    } while ((not_visited_node = find_not_visited_node(G)) != -1);
}

void dfsst2(Graph G, int v) {
    if (G == NULL || G->adj == NULL || v < 0 || v >= G->nodes || G->visited[v] == 2) {
        Error("Invalid graph or starting node!");
        return;
    }

    for (int w = 0; w < G->nodes; w++) {
        if (G->adj[v][w] == 1 && G->visited[w] == 0) {
            printf("Edge: (%d,%d)\n", v, w);
            dfsst2(G, w);
        }
    }
    G->visited[v] = 2;
}

void bfs(Graph G, int v0) {
    if (G == NULL || v0 < 0 || v0 >= G->nodes) {
        Error("Invalid graph or starting node!");
        return;
    }

    ClearVisited(G);
    LQueue Q = CreateQueue();
    Enqueue(v0, Q);
    G->visited[v0] = 2;
    printf("The node opened: %d\n", v0);

    while (!IsEmptyQueue(Q)) {
        int node = FrontAndDequeue(Q);

        for (int i = 0; i < G->nodes; i++) {
            if (G->adj[node][i] == 1 && G->visited[i] == 0) {
                Enqueue(i, Q);
                printf("The node opened: %d\n", i);
                G->visited[i] = 2;
            }
        }
    }
}

void bfsst(Graph G, int v0) {
    if (G == NULL || v0 < 0 || v0 >= G->nodes) {
        Error("Invalid graph or starting node!");
        return;
    }

    ClearVisited(G);
    LQueue Q = CreateQueue();
    Enqueue(v0, Q);
    G->visited[v0] = 2;

    while (!IsEmptyQueue(Q)) {
        int node = FrontAndDequeue(Q);

        for (int i = 0; i < G->nodes; i++) {
            if (G->adj[node][i] == 1 && G->visited[i] == 0) {
                Enqueue(i, Q);
                printf("Edge: (%d,%d)\n", node, i);
                G->visited[i] = 2;
            }
        }

        int isEnd;
        if ((isEnd = find_not_visited_node(G)) != -1) {
            Enqueue(isEnd, Q);
            G->visited[isEnd] = 2;
        }
    }
}