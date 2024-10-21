#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree_arr.h"
#include "err.h"

struct TreeRecord {
    int MaxLevel;
    int *Array;
};

Tree CreateTree(int MaxLevel) {
    Tree T = malloc(sizeof(struct TreeRecord));
    if (T == NULL) Error("Out of space!!!");

    int size = pow(2, MaxLevel + 1);
    T->Array = malloc(size * sizeof(int));
    if (T->Array == NULL) Error("Out of space!!!");

    T->MaxLevel = MaxLevel;
    for (int i = 0; i < size; i++) {
        T->Array[i] = 0;
    }

    return T;
}

void Insert(Tree T, int Index, int Elem) {
    if (T == NULL) Error("No tree!");
    if (Index < 1 || Index >= pow(2, T->MaxLevel + 1))
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

void PrintRow(Tree T, int Level) {
    if (T == NULL) Error("No tree!");
    if (Level < 1 || Level > T->MaxLevel) Error("Invalid level!");

    int start = pow(2, Level - 1);
    int end = pow(2, Level) - 1;

    for (int i = start; i <= end; i++) {
        printf("%02d ", T->Array[i]);
    }
    putchar('\n');
}

void PrintSubtree(Tree T, int Index) {
    if (T == NULL) Error("No tree!");
    if (Index < 1 || Index >= pow(2, T->MaxLevel + 1)) Error("Bad index!");

    int left = 2 * Index;
    int right = 2 * Index + 1;

    printf("%02d ", T->Array[Index]);

    if (left < pow(2, T->MaxLevel + 1) && T->Array[left] != 0)
        PrintSubtree(T, left);
    if (right < pow(2, T->MaxLevel + 1) && T->Array[right] != 0)
        PrintSubtree(T, right);
}