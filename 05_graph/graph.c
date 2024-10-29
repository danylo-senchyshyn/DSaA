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
    for (int i = 0; i < G->nodes; i++)
        for (int j = 0; j < G->nodes; j++) {
            printf("enter 1 if there is an edge from %d to %d, otherwise enter 0 \n", i, j);
            scanf("%d", &(G->adj[i][j]));
        }
}

void printadjm(Graph G) {
    for (int i = 0; i < G->nodes; i++) {
        for (int j = 0; j < G->nodes; j++)
            printf(" %d", G->adj[i][j]);
        putchar('\n');
    }
}

void ClearVisited(Graph G) {
    for (int n = 0; n < G->nodes; n++)
        G->visited[n] = 0;
}

// 3 stavy - 0 (not found), 1 (opened), 2 (closed)
void dfs(Graph G, int v0) {
    if (G == NULL) {
        Error("No graph");
        return;
    }
    ClearVisited(G);
    dfs2(G, v0);
}

void dfs2(Graph G, int v) {
    printf("The node opened: %d\n", v);
    for (int w = 0; w < G->nodes; w++) {
        if (G->adj[v][w] == 1 && G->visited[w] == 0)
            dfs2(G, w);
        G->visited[v] = 2;
    }
}

int find_not_visited_node(Graph G) {
    for (int i = 0; i < G->nodes; i++) {
        for (int j = 0; j < G->nodes; j++) {
            if (G->adj[i][j] == 1 && G->visited[j] == 0) return i;
        }
    }
    return -1;
}

void dfsst(Graph G, int v0) {
    if (G == NULL) {
        Error("No graph");
        return;
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
            printf("Edge: (%d,%d)\n", v, w);
            dfsst2(G, w);
        }
        G->visited[v] = 2;
    }
}

void bfs(Graph G, int v0) {
    if (G == NULL) {
        Error("No graph");
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
    if (G == NULL) {
        Error("No graph");
        return;
    }
    ClearVisited(G);
    LQueue Q = CreateQueue();
    Enqueue(v0, Q);
    G->visited[v0] = 2;

    int isEnd;

    do {
        while (!IsEmptyQueue(Q)) {
            int node = FrontAndDequeue(Q);

            for (int i = 0; i < G->nodes; i++) {
                if (G->adj[node][i] == 1 && G->visited[i] == 0) {
                    Enqueue(i, Q);
                    printf("Edge: (%d,%d)\n", node, i);
                    G->visited[i] = 2;
                }
            }
        }

        if ((isEnd = find_not_visited_node(G)) != -1) {
            Enqueue(isEnd, Q);
            G->visited[isEnd] = 2;
        }

    } while (isEnd != -1);
}