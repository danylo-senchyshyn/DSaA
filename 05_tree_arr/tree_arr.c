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

void DisposeTree(Tree T) {
    if (T != NULL) {
        free(T->Array);
        free(T);
    }
}

void MakeEmpty(Tree T) {
    if (T == NULL) Error("No tree!");
    for (int i = 1; i < pow(2, T->MaxLevel + 1); i++) {
        T->Array[i] = 0;
    }
}

void Insert(Tree T, int Index, int Elem) {
    if (T == NULL) Error("No tree!");
    if (Index < 1 || Index >= pow(2, T->MaxLevel + 1))
        Error("Bad index!");
    else
        T->Array[Index] = Elem;
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

            if (T->Array[k] != 0)
                printf("%02d", T->Array[k]);
            else
                printf("..");

            k++;
            for (int s = 0; s < level_spaces; s++) putchar(' ');
        }
        putchar('\n');
    }
}

void PrintRow(Tree T, int Level) {
    if (T == NULL) Error("No tree!");
    if (Level < 1 || Level > T->MaxLevel) Error("Invalid level!");

    int start = pow(2, Level) - 1;
    int end = start + pow(2, Level) - 1;

    for (int i = start; i <= end; i++) {
        if (T->Array[i] != 0)
            printf("%02d ", T->Array[i]);
        else
            printf(".. ");
    }
    putchar('\n');
}

void PrintSubtree(Tree T, int Index) {
    if (T == NULL) Error("No tree!");
    if (Index < 1 || Index >= pow(2, T->MaxLevel + 1)) Error("Bad index!");

    if (T->Array[Index] != 0)
        printf("%02d ", T->Array[Index]);

    int left = 2 * Index;
    int right = 2 * Index + 1;

    if (left < pow(2, T->MaxLevel + 1) && T->Array[left] != 0)
        PrintSubtree(T, left);
    if (right < pow(2, T->MaxLevel + 1) && T->Array[right] != 0)
        PrintSubtree(T, right);
}

void PrintSpaces(int Count) {
    for (int i = 0; i < Count; i++) {
        putchar(' ');
    }
}