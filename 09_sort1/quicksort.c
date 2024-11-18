#include <stdlib.h>
#include <stdio.h>

static int qdebug = 0;

void qsortDebug(int ano) {
    qdebug = ano;
}

void PrintPartition(int a[], int lo, int hi, int median, int left, int right) {
    int i;
    printf("x=%2d:  [ ", median);
    if (right < lo)printf("] ");
    for (i = lo; i <= hi; i++) {
        if (i == left)printf("[ ");
        printf("%2d ", a[i]);
        if (i == right)printf("] ");
    }
    if (left > hi)printf("[ ");
    printf("]\n");
}

int GetRandom(int lo, int hi) {
    return lo + rand() % (hi - lo + 1);
}

void quicksort(int a[], int lo, int hi) {
    int left, right, median, temp;

    if (hi <= lo) return;
    /* at least 2 elements */
    left = lo;
    right = hi;
    median = a[GetRandom(lo, hi)];
    /* partition a[lo..hi],  a[lo..left-1]<=median and a[right+1..hi]>=median */
    while (right >= left) {
        while (a[left] < median)left++;
        while (a[right] > median)right--;
        if (left > right) break;
        //swap
        temp = a[left];
        a[left] = a[right];
        a[right] = temp;
        left++;
        right--;
    }
    if (qdebug)PrintPartition(a, lo, hi, median, left, right);
    /* divide and conquer */
    quicksort(a, lo, right);
    quicksort(a, left, hi);
}




