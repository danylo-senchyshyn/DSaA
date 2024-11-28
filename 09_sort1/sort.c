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
        for (int i = 1; i <= n; i++) {
            for (int j = n; j >= i + 1; j--) {
                if ((a[j - 1] > a[j])) {
                    temp = a[j - 1];
                    a[j - 1] = a[j];
                    a[j] = temp;
                }
            }
            PrintArray(a, n, dir);
        }
    } else if (dir == DSC) {
        for (int i = 1; i <= n; i++) {
            for (int j = n; j >= i + 1; j--) {
                if ((a[j - 1] < a[j])) {
                    temp = a[j - 1];
                    a[j - 1] = a[j];
                    a[j] = temp;
                }
            }
            PrintArray(a, n, dir);
        }
    }
}

void insertSort(int *A, int n, int dir) {
    if (A == NULL || n < 0) {
        return;
    }

    int value, j;
    if (dir == ASC) {
        for (int i = 1; i <= n; i++) {
            value = A[i];
            j = i - 1;

            while (j >= 1 && A[j] > value) {
                A[j + 1] = A[j];
                j--;
            }

            A[j + 1] = value;
            PrintArray(A, n, dir);
        }
    } else if (dir == DSC) {
        for (int i = 1; i <= n; i++) {
            value = A[i];
            j = i - 1;

            while (j >= 1 && A[j] < value) {
                A[j + 1] = A[j];
                j--;
            }

            A[j + 1] = value;
            PrintArray(A, n, dir);
        }
    }
}

void selectionSort(int a[], int n, int dir) {
    if (a == NULL || n < 1) {
        return;
    }

    int i, j, minidx, tmp;
    PrintArray(a, n, dir);
    if (dir == ASC) {
        for (i = 1; i <= n; i++) {
            minidx = i;
            for (j = i + 1; j <= n; j++) {
                if (a[j] < a[minidx]) {
                    minidx = j;
                }
            }

            tmp = a[i];
            a[i] = a[minidx];
            a[minidx] = tmp;
            PrintArray(a, n, dir);
        }
    } else if (dir == DSC) {
        for (i = 1; i <= n; i++) {
            minidx = i;
            for (j = i + 1; j <= n; j++) {
                if (a[j] > a[minidx]) {
                    minidx = j;
                }
            }

            tmp = a[i];
            a[i] = a[minidx];
            a[minidx] = tmp;
            PrintArray(a, n, dir);
        }
    }
}