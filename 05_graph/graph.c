#include <stdio.h>
#include <stdlib.h>
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
    if (G == NULL) Error("Memory allocation failed!");
    G->nodes = NodesCount;
    for (int i = 0; i < NodesCount; i++) {
        G->visited[i] = 0;
        for (int j = 0; j < NodesCount; j++) {
            G->adj[i][j] = 0;
        }
    }
    return G;
}

void DisposeGraph(Graph G) {
    free(G);
}

void buildadjm(Graph G) {
    for (int i = 0; i < G->nodes; i++) {
        for (int j = 0; j < G->nodes; j++) {
            printf("Введите 1, если есть ребро от %d до %d, иначе 0: ", i, j);
            scanf("%d", &(G->adj[i][j]));
        }
    }
}

void printadjm(Graph G) {
    for (int i = 0; i < G->nodes; i++) {
        for (int j = 0; j < G->nodes; j++) {
            printf("%d ", G->adj[i][j]);
        }
        putchar('\n');
    }
}

void ClearVisited(Graph G) {
    for (int n = 0; n < G->nodes; n++) {
        G->visited[n] = 0;
    }
}

void dfs(Graph G, int v0) {
    if (G == NULL) {
        Error("Graph is not defined!");
    }
    ClearVisited(G);
    dfs2(G, v0);
}

void dfs2(Graph G, int v) {
    printf("Посещаем узел: %d\n", v);
    G->visited[v] = 1;
    for (int w = 0; w < G->nodes; w++) {
        if (G->adj[v][w] == 1 && G->visited[w] == 0) {
            dfs2(G, w);
        }
    }
    G->visited[v] = 2;
}

int find_not_visited_node(Graph G) {
    for (int i = 0; i < G->nodes; i++) {
        if (G->visited[i] == 0) return i;
    }
    return -1;
}

void dfsst(Graph G, int v0) {
    if (G == NULL) {
        Error("Graph is not defined!");
    }
    ClearVisited(G);
    int not_visited_node = v0;
    do {
        dfsst2(G, not_visited_node);
    } while ((not_visited_node = find_not_visited_node(G)) != -1);
}

void dfsst2(Graph G, int v) {
    for (int w = 0; w < G->nodes; w++) {
        if (G->adj[v][w] == 1 && G->visited[w] == 0) {
            printf("Ребро: (%d, %d)\n", v, w);
            dfsst2(G, w);
        }
    }
    G->visited[v] = 2;
}

void bfs(Graph G, int v0) {
    if (G == NULL) {
        Error("Graph is not defined!");
    }
    ClearVisited(G);
    LQueue Q = CreateQueue();
    Enqueue(v0, Q);
    G->visited[v0] = 1;
    printf("Посещаем узел: %d\n", v0);

    while (!IsEmptyQueue(Q)) {
        int node = FrontAndDequeue(Q);
        for (int i = 0; i < G->nodes; i++) {
            if (G->adj[node][i] == 1 && G->visited[i] == 0) {
                Enqueue(i, Q);
                printf("Посещаем узел: %d\n", i);
                G->visited[i] = 1;
            }
        }
        G->visited[node] = 2;
    }
}

void bfsst(Graph G, int v0) {
    if (G == NULL) {
        Error("Graph is not defined!");
    }
    ClearVisited(G);
    LQueue Q = CreateQueue();
    Enqueue(v0, Q);
    G->visited[v0] = 1;

    do {
        while (!IsEmptyQueue(Q)) {
            int node = FrontAndDequeue(Q);
            for (int i = 0; i < G->nodes; i++) {
                if (G->adj[node][i] == 1 && G->visited[i] == 0) {
                    Enqueue(i, Q);
                    printf("Ребро: (%d, %d)\n", node, i);
                    G->visited[i] = 1;
                }
            }
        }
        int isEnd = find_not_visited_node(G);
        if (isEnd != -1) {
            Enqueue(isEnd, Q);
            G->visited[isEnd] = 1;
        }
    } while (find_not_visited_node(G) != -1);
}