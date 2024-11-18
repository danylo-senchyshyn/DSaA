#include <stdio.h>
#include "sort.h"

void PrintArray(int a[], int n, int prechod) {
    int j;
    for (j = 1; j <= n; j++)printf("%2d ", a[j]);
    printf("\n");
}

void bubbleSort(int a[], int n, int dir) {
    if (a == NULL || n < 1) {
        return;
    }

    int temp;

    if (dir == ASC) {
        for (int i = 0; i <= n; i++) {
            for (int j = n; j >= i + 1; j--) {
                if((a[j - 1] > a[j])) {
                    temp = a[j - 1];
                    a[j - 1] = a[j];
                    a[j] = temp;
                }
                PrintArray(a, n, dir);
            }
        }
    } else if (dir == DSC) {
        for (int i = 1; i <= n; i++) {
            for (int j = n; j >= i + 1; j--) {
                if((a[j - 1] < a[j])) {
                    temp = a[j - 1];
                    a[j - 1] = a[j];
                    a[j] = temp;
                }
                PrintArray(a, n, dir);
            }
        }
    }
}

void insertSort(int *A, int n, int dir) {
    printf("DOPLNIT ...");
}

void selectionSort(int a[], int n, int dir) {
    printf("DOPLNIT ...");
}
