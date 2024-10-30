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
    for (int i = 0; i < G->nodes; i++) {
        G->visited[i] = 0;  
    }
}

void dfs(Graph G, int v0) {
    if (G == NULL || G->nodes <= 0) {
        printf("Invalid graph\n");
        return;
    }
    if (v0 < 0 || v0 >= G->nodes) {
        printf("Invalid starting vertex: %d\n", v0);
        return;
    }

    ClearVisited(G);
    printf("DFS starting from vertex %d:\n", v0);
    dfs2(G, v0);

    for (int i = 0; i < G->nodes; i++) {
        if (G->visited[i] == 0) {
            printf("DFS starting from component vertex %d:\n", i);
            dfs2(G, i);
        }
    }
}

void dfs2(Graph G, int v) {
    G->visited[v] = 1;
    printf("Visited vertex: %d\n", v);

    for (int w = 0; w < G->nodes; w++) {
        if (G->adj[v][w] == 1 && G->visited[w] == 0) {
            dfs2(G, w);
        }
    }
    G->visited[v] = 2; 
}

void dfsst(Graph G, int v0) {
    if (v0 < 0 || v0 >= G->nodes) {
        printf("Invalid starting vertex: %d\n", v0);
        return;
    }
    ClearVisited(G);
    printf("Spanning tree (DFS) starting from vertex %d:\n", v0);
    dfsst2(G, v0);
    for (int i = 0; i < G->nodes; i++) {
        if (G->visited[i] == 0) {
            printf("Spanning tree starting from component vertex %d:\n", i);
            dfsst2(G, i);
        }
    }
}

void dfsst2(Graph G, int v) {
    G->visited[v] = 1;
    for (int w = 0; w < G->nodes; w++) {
        if (G->adj[v][w] == 1 && G->visited[w] == 0) {
            printf("Edge: (%d, %d)\n", v, w);
            dfsst2(G, w);
        }
    }
}

void bfs(Graph G, int v0) {
    if (v0 < 0 || v0 >= G->nodes) {
        printf("Invalid starting vertex: %d\n", v0);
        return;
    }
    ClearVisited(G);
    printf("BFS starting from vertex %d:\n", v0);

    int queue[max];
    int front = 0;
    int rear = 0;

    queue[rear++] = v0;
    G->visited[v0] = 1;

    while (front < rear) {
        int v = queue[front++];
        printf("Visited vertex: %d\n", v);

        for (int w = 0; w < G->nodes; w++) {
            if (G->adj[v][w] == 1 && G->visited[w] == 0) {
                queue[rear++] = w;
                G->visited[w] = 1;
            }
        }
    }

    for (int i = 0; i < G->nodes; i++) {
        if (G->visited[i] == 0) {
            printf("BFS starting from component vertex %d:\n", i);
            bfs(G, i);
        }
    }
}

void bfsst(Graph G, int v0) {
    if (v0 < 0 || v0 >= G->nodes) {
        printf("Invalid starting vertex: %d\n", v0);
        return;
    }
    ClearVisited(G);
    printf("Spanning tree (BFS) starting from vertex %d:\n", v0);

    int queue[max];
    int front = 0;
    int rear = 0;

    queue[rear++] = v0;
    G->visited[v0] = 1;

    while (front < rear) {
        int v = queue[front++];

        for (int w = 0; w < G->nodes; w++) {
            if (G->adj[v][w] == 1 && G->visited[w] == 0) {
                if (rear < max) {
                    printf("Edge: (%d, %d)\n", v, w);
                    queue[rear++] = w;
                    G->visited[w] = 1;
                } else {
                    printf("Queue overflow! Cannot enqueue vertex %d\n", w);
                }
            }
        }
    }

    for (int i = 0; i < G->nodes; i++) {
        if (G->visited[i] == 0) {
            printf("Spanning tree starting from component vertex %d:\n", i);
            bfsst(G, i);
        }
    }
}