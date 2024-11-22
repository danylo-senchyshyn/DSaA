#include "maxmin.h"
#include <stdio.h>
#include <stdlib.h>

#ifndef MAX
#define MAX(a, b) ((a)>(b)?a:b)
#endif
#ifndef MIN
#define MIN(a, b) ((a)<(b)?a:b)
#endif

// поиск максимального и минимального элементов массива
pair MaxMin(int A[], int L, int H) {
    pair ret1, ret2, ret;

    int n = H - L + 1;
    int center = (L + H) / 2;

    if (n == 1) {
        ret.min = A[L];
        ret.max = A[L];
        return ret;
    } else if (n == 2) {
        if (A[L] > A[H]) {
            ret.max = A[L];
            ret.min = A[H];
        } else {
            ret.max = A[H];
            ret.min = A[L];
        }
        return ret;
    } else {
        ret1 = MaxMin(A, L, center);
        ret2 = MaxMin(A, center + 1, H);

        if (ret1.max > ret2.max) {
            ret.max = ret1.max;
        } else {
            ret.max = ret2.max;
        }

        if (ret1.min < ret2.min) {
            ret.min = ret1.min;
        } else {
            ret.min = ret2.min;
        }
    }

    return ret;
}
