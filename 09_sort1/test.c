#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heapsort.h"
#include "quicksort.h"
#include "sort.h"

#define N  16

int data1[] = {0, 12, 15, 3, 8, 2, 16, 7, 1, 10, 11, 4, 5, 9, 6, 13, 14};

void Copy(int *dest, int *src, int n) {
    int i;
    for (i = 0; i <= n; i++)dest[i] = src[i];
}

int d[N + 1];

int main() {
    int i;

    printf("\nBUBBLESORT ASC\n");
    Copy(d, data1, N);
    bubbleSort(d, N, ASC);
    printf("\nBUBBLESORT DSC\n");
    Copy(d, data1, N);
    bubbleSort(d, N, DSC);

    printf("\nINSERTSORT ASC\n");
    Copy(d, data1, N);
    insertSort(d, N, ASC);
    printf("\nINSERTSORT DSC\n");
    Copy(d, data1, N);
    insertSort(d, N, DSC);

    printf("\nSELECTIONSORT ASC\n");
    Copy(d, data1, N);
    selectionSort(d, N, ASC);
    printf("\nSELECTIONSORT DSC\n");
    Copy(d, data1, N);
    selectionSort(d, N, DSC);

    printf("\nQUICKSORT\n");
    Copy(d, data1, N);
    srand(time(NULL));
    //qsortDebug(1);
    quicksort(d, 1, N);
    for (i = 1; i <= N; i++)printf("%2d ", d[i]);
    printf("\n");

    printf("\nHEAPSORT\n");
    //hsortDebug(1);
    heapSort(d, N);
    //hsortDebug(0);
    for (i = 1; i <= N; i++)printf("%2d ", d[i]);
    printf("\n");
    // system("PAUSE");

    return 0;
}
