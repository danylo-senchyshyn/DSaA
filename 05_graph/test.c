#include <stdio.h>
#include "graph.h"
#include "err.h"

#define max 100

int main() {
    int n;
    Graph G;

    printf("Enter the number of nodes in the graph (maximum = %d): ", max);
    scanf("%d", &n);

    if (n > max) {
        Error("Exceeded maximum number of nodes!");
    }

    G = CreateGraph(n);

    buildadjm(G);

    printf("\nAdjacency matrix:\n");
    printadjm(G);

    printf("\nDepth first search (DFS):\n");
    dfs(G, 0);

    DisposeGraph(G);

    putchar('\n');
    return 0;
}