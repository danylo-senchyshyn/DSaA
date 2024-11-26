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
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if ((dir == ASC && a[j - 1] > a[j]) || (dir == DSC && a[j - 1] < a[j])) {
                temp = a[j - 1];
                a[j - 1] = a[j];
                a[j] = temp;
            }
        }
        PrintArray(a, n, i + 1);
    }
}

void insertSort(int *A, int n, int dir) {
    if (A == NULL || n <= 0) {
        return;
    }

    for (int i = 1; i < n; i++) {
        int value = A[i];
        int j = i - 1;

        if (dir == ASC) {
            while (j >= 0 && A[j] > value) {
                A[j + 1] = A[j];
                j--;
            }
        } else if (dir == DSC) {
            while (j >= 0 && A[j] < value) {
                A[j + 1] = A[j];
                j--;
            }
        }

        A[j + 1] = value;

        PrintArray(A, n, dir);
    }
}

void selectionSort(int a[], int n, int dir) {
    if (a == NULL || n < 1) {
        printf("Error\n");
        return;
    }

    int i, j, minidx, tmp;
    PrintArray(a, n, 0);

    if (dir == ASC) {
        for (i = 0; i < n - 1; i++) {
            minidx = i;
            for (j = i + 1; j < n; j++) {
                if (a[j] < a[minidx]) {
                    minidx = j;
                }
            }
            tmp = a[i];
            a[i] = a[minidx];
            a[minidx] = tmp;

            PrintArray(a, n, i + 1);
        }
    } else if (dir == DSC) {
        for (i = 0; i < n - 1; i++) {
            minidx = i;
            for (j = i + 1; j < n; j++) {
                if (a[j] > a[minidx]) {
                    minidx = j;
                }
            }
            tmp = a[i];
            a[i] = a[minidx];
            a[minidx] = tmp;

            PrintArray(a, n, i + 1);
        }
    }
}
