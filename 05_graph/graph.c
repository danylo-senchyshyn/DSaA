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
int find_not_visited_node(Graph G) {
    for (int i = 0; i < G->nodes; i++) {
        if (G->visited[i] == 0) {
            return i;
        }
    }
    return -1;
}

void dfs(Graph G, int v0) {
    if (G == NULL) {
        Error("No graph");
        return;
    }
    ClearVisited(G);
    dfs2(G, v0);

    for (int i = 0; i < G->nodes; i++) {
        if (G->visited[i] == 0) {
            G->visited[i] = 2;
            printf("Isolated node closed: %d\n", i);
        }
    }
}

void dfs2(Graph G, int v) {
    if (G->visited[v] != 0) return;
    printf("The node opened: %d\n", v);
    G->visited[v] = 1;

    for (int w = 0; w < G->nodes; w++) {
        if (G->adj[v][w] == 1 && G->visited[w] == 0) {
            dfs2(G, w);
        }
    }

    G->visited[v] = 2;
    printf("The node closed: %d\n", v);
}

void dfsst(Graph G, int v0) {
    if (G == NULL) {
        Error("No graph");
        return;
    }
    ClearVisited(G);
    dfsst2(G, v0);

    int not_visited_node;
    while ((not_visited_node = find_not_visited_node(G)) != -1) {
        dfsst2(G, not_visited_node);
    }
}

void dfsst2(Graph G, int v) {
    if (G->visited[v] != 0) return;
    G->visited[v] = 1;

    for (int w = 0; w < G->nodes; w++) {
        if (G->adj[v][w] == 1 && G->visited[w] == 0) {
            printf("Edge: (%d,%d)\n", v, w);
            dfsst2(G, w);
        }
    }

    G->visited[v] = 2;
}

void bfs(Graph G, int v0) {
    if (G == NULL) {
        Error("No graph");
        return;
    }

    ClearVisited(G);
    LQueue Q = CreateQueue();
    Enqueue(v0, Q);
    G->visited[v0] = 1;
    printf("The node opened: %d\n", v0);

    while (!IsEmptyQueue(Q)) {
        int node = FrontAndDequeue(Q);

        for (int i = 0; i < G->nodes; i++) {
            if (G->adj[node][i] == 1 && G->visited[i] == 0) {
                Enqueue(i, Q);
                G->visited[i] = 1;
                printf("The node opened: %d\n", i);
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
    G->visited[v0] = 1;

    int isEnd;

    do {
        while (!IsEmptyQueue(Q)) {
            int node = FrontAndDequeue(Q);

            for (int i = 0; i < G->nodes; i++) {
                if (G->adj[node][i] == 1 && G->visited[i] == 0) {
                    Enqueue(i, Q);
                    G->visited[i] = 1;
                    printf("Edge: (%d, %d)\n", node, i);
                }
            }
        }

        isEnd = find_not_visited_node(G);
        if (isEnd != -1) {
            Enqueue(isEnd, Q);
            G->visited[isEnd] = 1;
        }

    } while (isEnd != -1);
}