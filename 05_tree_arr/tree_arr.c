#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tree_arr.h"
#include "err.h"

struct TreeRecord {
    int MaxLevel;
    int *Array;
};

int GetMaxSize(Tree T) {
    return pow(2, T->MaxLevel + 1);
}

Tree CreateTree(int MaxLevel) {
    Tree T = malloc(sizeof(struct TreeRecord));
    if (T == NULL) Error("Out of space!!!");
    T->MaxLevel = MaxLevel;
    int size = GetMaxSize(T);
    T->Array = malloc(size * sizeof(int));
    if (T->Array == NULL) Error("Out of space!!!");
    for (int i = 0; i < size; i++) {
        T->Array[i] = 0; // инициализируем нулями
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
    for (int i = 0; i < GetMaxSize(T); i++) {
        T->Array[i] = 0; // инициализируем нулями
    }
}

void Insert(Tree T, int Index, int Elem) {
    if (T == NULL) Error("No tree!");
    if (Index < 1 || Index >= GetMaxSize(T)) Error("Bad index!");
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
            if (k < GetMaxSize(T) && T->Array[k] != 0)
                printf("%02d", T->Array[k]);
            else
                printf("..");
            k++;
            for (int s = 0; s < level_spaces; s++) putchar(' ');
        }
        putchar('\n');
    }
}

void PrintSpaces(int Count) {
    for (int i = 0; i < Count; i++) {
        putchar(' ');
    }
}

// выводит все узлы на указанном уровне дерева. уровень начинается с 0
void PrintRow(Tree T, int Level) {
    if (T == NULL) {
        Error("No tree!");
        return;
    }
    if (Level < 0 || Level > T->MaxLevel) {
        Error("Bad level!");
        return;
    }

    int start = pow(2, Level);          // первый узел на уровне
    int end = pow(2, Level + 1) - 1;    // последний узел на уровне

    for (int i = start; i <= end; i++) {
        if (i < GetMaxSize(T)) {
            if (T->Array[i] != 0) {
                printf("%02d ", T->Array[i]);
            } else {
                printf("-- ");
            }
        } else {
            printf("-- ");
        }
    }
    putchar('\n');
}

// выводит все узлы поддерева, уровень - Index
void PrintSubtree(Tree T, int Index) {
    if (T == NULL) {
        Error("No tree!");
        return;
    }
    if (Index < 1 || Index >= GetMaxSize(T)) {
        Error("Bad index!");
        return;
    }

    int k = 1;
    int to = pow(2, T->MaxLevel + 1);
    for(int i = Index; i < to; i *= 2) {
        for(int j = i; j < (k + i); j++) {
            printf("%02d ", T->Array[j]);
        }
        k *= 2;
    }
}

void MyPrintf(const char *format, ...) {
}