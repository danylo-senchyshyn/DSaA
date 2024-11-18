#include <stdio.h>

static int debug = 0;

void hsortDebug(int dbg) {
    debug = dbg;
}

void printHeap(int a[], int last, int n, char *txt) {
    int i, j, k;
    k = 1;
    j = 0;
    printf("====== %s ==================\n", txt);
    for (i = 1; i <= last; i++) {
        printf("%2d ", a[i]);
        j++;
        if (j == k || i == last) {
            printf("\n");
            j = 0;
            k = k * 2;
        }
    }
    for (i = last + 1; i <= n; i++) {
        if (i == last + 1)printf("[ ");
        printf("%2d ", a[i]);
        if (i == n)printf("]\n");
    }
    printf("----------------------------------------\n");
}

void heapify(int a[], int root, int last) {
    int maxChild, temp;
    if (root * 2 > last)return;
    if (root * 2 == last)maxChild = root * 2;
    else if (a[root * 2] > a[root * 2 + 1])maxChild = root * 2;
    else maxChild = root * 2 + 1;

    if (a[root] < a[maxChild]) {
        temp = a[root];
        a[root] = a[maxChild];
        a[maxChild] = temp;
        heapify(a, maxChild, last);
    }
}

void heapSort(int a[], int n) {
    int i, temp;
    char pom[128];

    for (i = (n / 2); i > 0; i--) {
        heapify(a, i, n);
    }
    if (debug)printHeap(a, n, n, "Po uprave na HEAP");
    for (i = n; i > 1; i--) {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        heapify(a, 1, i - 1);
        if (debug) {
            sprintf(pom, "Po a[1]<->a[%d] a uprave na HEAP", i);
            printHeap(a, i - 1, n, pom);
        }
    }
}

