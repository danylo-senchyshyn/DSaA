#include <stdio.h>
#include <stdlib.h>
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
    if (G == NULL) {
        Error("Attempted to dispose a null graph!");
        return;
    }
    free(G);
}

void buildadjm(Graph G) {
    if (G == NULL) {
        Error("Graph is null!");
        return;
    }

    for (int i = 0; i < G->nodes; i++) {
        for (int j = 0; j < G->nodes; j++) {
            printf("Enter 1 if there is an edge from %d to %d, otherwise enter 0: ", i, j);
            scanf("%d", &(G->adj[i][j]));
            if (G->adj[i][j] != 0 && G->adj[i][j] != 1) {
                printf("Invalid input! Please enter 0 or 1.\n");
                j--;
            }
        }
    }
}

void printadjm(Graph G) {
    if (G == NULL) {
        Error("Graph is null!");
        return;
    }

    for (int i = 0; i < G->nodes; i++) {
        for (int j = 0; j < G->nodes; j++) {
            printf(" %d", G->adj[i][j]);
        }
        putchar('\n');
    }
}

void ClearVisited(Graph G) {
    if (G == NULL) {
        Error("Graph is null!");
        return;
    }

    for (int n = 0; n < G->nodes; n++) {
        G->visited[n] = 0;
    }
}

void dfs(Graph G, int v0) {
    if (G == NULL) {
        Error("Graph is null!");
        return;
    }
    if (v0 < 0 || v0 >= G->nodes) {
        Error("Invalid starting node for DFS!");
        return;
    }

    ClearVisited(G);
    dfs2(G, v0);
}

void dfs2(Graph G, int v) {
    printf("The node opened: %d\n", v);
    G->visited[v] = 1;

    for (int w = 0; w < G->nodes; w++) {
        if (G->adj[v][w] == 1 && G->visited[w] == 0) {
            dfs2(G, w);
        }
    }
}

void dfsst(Graph G, int v0) {
    if (G == NULL) {
        Error("Graph is null!");
        return;
    }
    if (v0 < 0 || v0 >= G->nodes) {
        Error("Invalid starting node for DFS spanning tree!");
        return;
    }

    ClearVisited(G);
    printf("Spanning tree edges:\n");
    dfsst2(G, v0);

    for (int i = 0; i < G->nodes; i++) {
        if (G->visited[i] == 0) {
            dfsst2(G, i);
        }
    }
}

void dfsst2(Graph G, int v) {
    G->visited[v] = 1;
    for (int w = 0; w < G->nodes; w++) {
        if (G->adj[v][w] == 1 && G->visited[w] == 0) {
            printf("Edge: %d -> %d\n", v, w);
            dfsst2(G, w);
        }
    }
}

void bfs(Graph G, int v0) {
    if (G == NULL) {
        Error("Graph is null!");
        return;
    }
    if (v0 < 0 || v0 >= G->nodes) {
        Error("Invalid starting node for BFS!");
        return;
    }

    ClearVisited(G);
    int queue[max], front = 0, rear = 0;

    printf("Component starting at node: %d\n", v0);
    queue[rear++] = v0;
    G->visited[v0] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("The node opened: %d\n", v);

        for (int w = 0; w < G->nodes; w++) {
            if (G->adj[v][w] == 1 && G->visited[w] == 0) {
                queue[rear++] = w;
                G->visited[w] = 1;
            }
        }
    }

    for (int i = 0; i < G->nodes; i++) {
        if (G->visited[i] == 0) {
            printf("Component starting at node: %d\n", i);
            bfs(G, i);
        }
    }
}

void bfsst(Graph G, int v0) {
    if (G == NULL) {
        Error("Graph is null!");
        return;
    }
    if (v0 < 0 || v0 >= G->nodes) {
        Error("Invalid starting node for BFS spanning tree!");
        return;
    }

    ClearVisited(G);
    int queue[max], front = 0, rear = 0;

    printf("Spanning tree edges:\n");
    queue[rear++] = v0;
    G->visited[v0] = 1;

    while (front < rear) {
        int v = queue[front++];
        for (int w = 0; w < G->nodes; w++) {
            if (G->adj[v][w] == 1 && G->visited[w] == 0) {
                printf("Edge: %d -> %d\n", v, w);
                queue[rear++] = w;
                G->visited[w] = 1;
            }
        }
    }

    for (int i = 0; i < G->nodes; i++) {
        if (G->visited[i] == 0) {
            bfsst(G, i);
        }
    }
}