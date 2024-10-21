#include "err.h"
#include "tree_arr.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct TreeRecord {
    int MaxLevel;
    int *Array;
};

Tree CreateTree(int MaxLevel) {
    Tree T;
    T = malloc(sizeof(struct TreeRecord));
    if (T == NULL) Error("Out of space!!!");

    T->Array = malloc(pow(2, MaxLevel + 1) * sizeof(int));
    if (T->Array == NULL) Error("Out of space!!!");

    T->MaxLevel = MaxLevel;
    for (int i = 0; i < pow(2, T->MaxLevel + 1); i++)
        T->Array[i] = 0;

    return T;
}

void Insert(Tree T, int Index, int Elem) {
    if (T == NULL) Error("No tree!");
    if (Index < 1 || Index > pow(2, T->MaxLevel + 1) - 1)
        Error("Bad index!");
    else
        T->Array[Index] = Elem;
}

void DisposeTree(Tree T) {
    if (T != NULL) {
        free(T->Array);
        free(T);
    }
}

void PrintTree(Tree T) {
    if (T == NULL) Error("No tree!");

    int k = 1, n, level_spaces;
    for (int i = 1; i <= T->MaxLevel + 1; i++) {
        n = pow(2, i - 1);
        level_spaces = (4 * pow(2, T->MaxLevel) - 2 * n) / n;

        for (int j = 0; j < n; j++) {
            if (j == 0)
                for (int s = 0; s < level_spaces / 2; s++) putchar(' ');

            printf("%02d", T->Array[k++]);
            for (int s = 0; s < level_spaces; s++) putchar(' ');
        }
        putchar('\n');
    }
}

void PrintSpaces(int Count) {
    while (Count-- > 0) putchar(' ');
}